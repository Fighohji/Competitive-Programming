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

constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

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


/*



5 1 4 2
5 1 2
1 4 2

5 1 4 2 3
5 1 2 3
5 1 3
5 1
1 4 2 3
1 2 3
1 3
1



2 4 1 3
2 1 3
2 4 1
1 3
2 1
1



*/

struct node {
    int p; mint val;
    bool operator<(const node & t) const {
        return p < t.p;
    }
    bool operator==(const node & t) const {
        return p == t.p;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    set<node> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[-a[i]] = i;
        s.insert({i, 1});
    }
    int Min = *min_element(a.begin() + 1, a.end());
    for (auto &[_, y] : mp) {

        int x = -_;
        auto p = s.lower_bound((node){y, 0});
        auto tmp = p;
        mint L = (*p).val, R = (*p).val;
        mint cntl = 0, cntr = 0;
        while (p != s.begin()) {
            --p;
            if (a[(*p).p] < a[(*tmp).p]) {
                ++p;
                break;
            }
            cntl += 1;
            L += (*p).val;
        }

        s.erase(p, ++tmp);
        s.insert({y, 1});
        p = s.lower_bound((node){y, 0});
        tmp = p;
        ++p;
        while (p != s.end()) {
            if (a[(*p).p] < a[(*tmp).p]) {
                break;
            }
            R += (*p).val;
            cntr += 1;
            ++p;
        }

        s.erase(tmp, p);
        s.insert({y, (L + cntl) * R + cntr) + (cntl + 1) * (cntr + 1)});
    }
    cout << (*s.begin()).val << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
