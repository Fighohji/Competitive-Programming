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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};


int norm(int x)
{
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
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


int trie[maxn << 5][2], idx;
mint lazy[maxn << 5], val[maxn << 5];

void push(int p) {
    if (lazy[p].val() != 1) {
        int &ls = trie[p][0];
        int &rs = trie[p][1];
        // if (!ls) ls = ++idx;
        // if (!rs) rs = ++idx;
        if (ls) lazy[ls] *= lazy[p];
        if (rs) lazy[rs] *= lazy[p];
        if (ls) val[ls] *= lazy[p];
        if (rs) val[rs] *= lazy[p];
        lazy[p] = mint(1);
    }
}

void ins(int x) {
    int now = 1;
    push(now);
    val[now] += mint(1);
    for (int i = 30; i >= 0; --i) {
        int c = (x >> i & 1);
        if (!trie[now][c]) trie[now][c] = ++idx;
        now = trie[now][c];
        push(now);
        val[now] += mint(1);
    }
}

mint qry(int x, int k) {
    mint res = 0;
    int now = 1;
    for (int i = 30; i >= 0; --i) {
        push(now);
        int c = x >> i & 1;
        int t = k >> i & 1;
        if (t == 1) res += val[trie[now][c]];
        now = trie[now][c ^ t];
        // now = trie[now][c];
        // if (!now) break;
    }
    res += val[now];
    return res;
}
/*
k = 3
1 2 3 4 5
2 1
3 1 + 2 = 3
4 0
5 1
*/
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    vector<pii> c(n);
    mint Ans = mint(n);
    idx = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    // cout << Ans << '\n';
    for (int i = 0; i < n; ++i) {
        Ans += qry(a[i], k);
        lazy[1] *= mint(2);
        val[1] *= mint(2);
        ins(a[i]);
    }
    cout << Ans << '\n';
    for (int i = 0; i <= idx; ++i) {
        lazy[i] = mint(1);
        trie[i][0] = trie[i][1] = 0;
        val[i] = 0;
    }
    idx = 1;
}
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i <= 30 * 200000; ++i) lazy[i] = mint(1);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
