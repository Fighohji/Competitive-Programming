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
constexpr int mod = 1e9 + 7; /*  */
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

#define int long long
struct Edge {
    int u, v, w;
};
mint fac[maxn];
mint inv[maxn];

void init(int n)
{
    fac[1] = inv[1] = inv[0] = fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = i * fac[i - 1];
    inv[n] = fac[n].inv();
    for (int i = n - 1; i >= 1; --i) inv[i] = (i + 1) * inv[i + 1];
}

mint C(int n, int m)
{
    return fac[n] * inv[m] * inv[n - m];
}
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<mint> seq(k + 1), d(k + 1);
    iota(all(d), 0ll);
    for (int i = 1; i <= k; ++i) d[i] += d[i - 1];
    mint tot = mint(n * (n - 1) / 2);
    mint p = mint(1) / tot;
    for (int i = 1; i <= k; ++i) {
        seq[i] = C(k, i) * qpow(p, i) * qpow(1 - p, k - i);
    }
    mint Ans = 0;
    vector<Edge> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        Ans += mint(k) / tot * mint(e[i].w);
    }
    for (int i = 1; i <= k; ++i) {
        Ans += seq[i] * mint(m) * d[i - 1];
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init(200000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
