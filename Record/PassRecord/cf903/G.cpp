#include <iterator>
#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 26; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


int norm(int x)
{
    if (x < 0) {
        x = x % mod;
    }
    if (x >= mod) {
        x %= mod;
    }
    return x;
}
template<class T>
T qpow(T base, ll power)
{
    T res = 1;
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

struct mint
{
    int x;
    mint(int x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const { assert(x != 0); return qpow(*this, mod - 2); }
    mint &operator*=(const mint &rhs) { x = (ll)x * rhs.x % mod; return *this; }
    mint &operator+=(const mint &rhs) { x = norm(x + rhs.x); return *this; }
    mint &operator-=(const mint &rhs) { x = norm(x - rhs.x); return *this; }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) { mint res = lhs; res *= rhs; return res; }
    friend mint operator+(const mint &lhs, const mint &rhs) { mint res = lhs; res += rhs; return res; }
    friend mint operator-(const mint &lhs, const mint &rhs) { mint res = lhs; res -= rhs; return res; }
    friend mint operator/(const mint &lhs, const mint &rhs) { mint res = lhs; res /= rhs; return res; }
    friend std::istream &operator>>(std::istream &is, mint &a) { ll v; is >> v; a = mint(v); return is; }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) { return os << a.val(); }
};


mint dif[maxn];

struct SegTree {
#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (ls + 1)
    int cnt[maxn << 2];
    void build(int p, int l, int r) {
        if (l > r) return ;
        cnt[p] = 0;
        if (l == r) return ;
        build(ls, l, mid);
        build(rs, mid + 1, r);
    }
    void update(int p, int l, int r, int pos, int val) {
        if (l > r) return ;
        cnt[p] += val;
        if (l == r) return ;
        if (pos <= mid) update(ls, l, mid, pos, val);
        else update(rs, mid + 1, r, pos, val);
    }
    int query(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l && r <= qr) return cnt[p];
        int res = 0;
        if (ql <= mid) res += query(ls, l, mid, ql, qr);
        if (mid < qr) res += query(rs, mid + 1, r, ql, qr);
        return res;
    }
#undef mid
#undef ls
#undef rs
} seg1, seg2;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 1; i < n; ++i)
        dif[i] = (s[i] - s[i - 1] + 26) % 26;
    seg1.build(1, 1, n - 1); seg2.build(1, 1, n - 1);
    for (int i = 1; i < n; ++i) {
        if (dif[i].val() == 0) seg1.update(1, 1, n - 1, i, 1);
        if (i > 1 && (dif[i - 1] + dif[i]).val() == 0)
            seg2.update(1, 1, n - 1, i, 1);
    }
    while (m--) {
        int op, l, r, x;
        cin >> op >> l >> r;
        l--, r--;
        if (op == 1) {
            cin >> x;
            mint tmpl = dif[l], tmpll = (l - 1 >= 0 ? dif[l - 1] : 0), tmplll = dif[l + 1];
            mint tmpr = dif[r + 1], tmprr = dif[r], tmprrr = dif[r + 2];
            dif[l] += x % 26;
            dif[r + 1] -= x % 26;
            if (l != 0) {
                if (dif[l].val() != tmpl.val()) {
                    if (dif[l].val() == 0) seg1.update(1, 1, n - 1, l, 1);
                    else if (tmpl.val() == 0 && dif[l].val() != 0) seg1.update(1, 1, n - 1, l, -1);
                }

                if (l > 1 && ((dif[l - 1] + dif[l]).val() == 0) != ((tmpl + tmpll).val() == 0)) {
                    if ((tmpl + tmpll).val() != 0) seg2.update(1, 1, n - 1, l, 1);
                    else seg2.update(1, 1, n - 1, l, -1);
                }
                if (l + 1 < n && ((dif[l] + dif[l + 1]).val() == 0) != ((tmpl + tmplll).val() == 0)) {
                    if ((tmpl + tmplll).val() != 0) seg2.update(1, 1, n - 1, l + 1, 1);
                    else seg2.update(1, 1, n - 1, l + 1, -1);
                }
            }

            if (r + 1 >= n) continue;

            if (dif[r + 1].val() != tmpr.val()) {
                if (dif[r + 1].val() == 0) seg1.update(1, 1, n - 1, r + 1, 1);
                else if (tmpr.val() == 0 && dif[r + 1].val() != 0) seg1.update(1, 1, n - 1, r + 1, -1);
            }

            if (r + 1 > 1 && ((dif[r] + dif[r + 1]) .val() == 0) != ((tmpr + tmprr).val() == 0)) {
                if ((tmpr + tmprr).val() != 0) seg2.update(1, 1, n - 1, r + 1, 1);
                else seg2.update(1, 1, n - 1, r + 1, -1);
            }
            if (r + 2 < n && ((dif[r + 1] + dif[r + 2]).val() == 0) != ((tmpr + tmprrr).val() == 0)) {
                if ((tmpr + tmprrr).val() != 0) seg2.update(1, 1, n - 1, r + 2, 1);
                else seg2.update(1, 1, n - 1, r + 2, -1);
            }
        } else {
            l++;
            if (seg1.query(1, 1, n - 1, l, r)) {
                cout << "No\n";
            } else if (seg2.query(1, 1, n - 1, l + 1, r)) {
                cout << "No\n";
            } else cout << "Yes\n";
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
