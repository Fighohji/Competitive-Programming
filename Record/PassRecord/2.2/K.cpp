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



struct node {
    int nxt;
    bitset<5> sta;
};
void solve() {
    int n; cin >> n;
    vector<node> e(n + 1);
    vector<int> d(n + 1);
    vector<vector<int>> G(n + 1);
    vector<bitset<5>> las(n + 1, bitset<5>(31));
    for (int i = 1; i <= n; ++i) {
        cin >> e[i].nxt;
        string s; cin >> s;
        vector<int> E[5];
        vector<int> deg(5);
        for (int j = 0; j < 5; ++j) {
            if (j != s[j] - 'A') {
                E[j].pb(s[j] - 'A');
                deg[s[j] - 'A']++;
            }
        }
        queue<int> q;
        for (int j = 0; j < 5; ++j) {
            if (!deg[j])
                q.push(j);
        }
        while (!q.empty()) {
            int p = q.front(); q.pop();
            if (SZ(E[p]) == 0) {
                e[i].sta[p] = 1;
            }
            for (int v : E[p]) {
                deg[v]--;
                if (!deg[v]) q.push(v);
            }
        }
        for (int j = 0; j < 5; ++j) {
            if (deg[j]) e[i].sta[j] = 0;
        }
        if (e[i].nxt != i) {
            G[i].pb(e[i].nxt);
            d[e[i].nxt]++;
        } else {
            las[i] &= e[i].sta;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) q.push(i);
    }
    mint Ans = 1;
    vector<bitset<5>> ex(n + 1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (SZ(G[u]) == 0) {
            Ans *= mint((int)las[u].count());
        }
        for (auto v : G[u]) {
            d[v]--;
            las[v] &= (las[u] & e[u].sta);
            ex[v] |= las[v];
            if (!d[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        // cout << e[i].sta << '\n';
        if (d[i]) {
            int now = i;
            bitset<5> res(31), tmp;
            while (d[now]) {
                tmp |= ex[now];
                d[now]--;
                res &= (e[now].sta & las[now]);
                now = e[now].nxt;
            }
            // cout << res << ' ' << tmp << '\n';
            if ((int)res.count() == 0 && (int)tmp.count()) {
                Ans = Ans;
            } else {
                Ans *= mint((int)res.count());

            }
            // cout << res << '\n';
        }
    }
    cout << Ans << '\n';
}
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
