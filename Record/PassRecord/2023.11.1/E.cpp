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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

const int B = 2000;
ll a[maxn];
int b[maxn];
vector<pair<int, long long>> G[maxn], T[maxn];
multiset<ll> s[maxn];
ll dp[maxn];
int deg[maxn];
void solve() {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        deg[u]++; deg[v]++;
        G[u].pb({v, w}); G[v].pb({u, w});
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] <= B) continue;
        for (auto [v, w] : G[i]) {
            if (deg[v] <= B) continue;
            T[i].pb({v, w});
        }
    }
    for (int i = 1; i <= q; ++i)
        cin >> b[i];
    dp[b[q]] = LINF;
    for (auto [v, w] : G[b[q]])
        dp[b[q]] = min(dp[b[q]], w);
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > B)
            for (auto [v, w] : G[i])
                s[i].insert(dp[v] + w);
    }
    for (int i = q - 1; i >= 1; --i) {
        if (deg[b[i]] <= B) {
            ll ans = LINF;
            for (auto [v, w] : G[b[i]])
                ans = min(ans, dp[v] + w);
            for (auto [v, w] : G[b[i]]) {
                if (deg[v] <= B) continue;
                s[v].extract(dp[b[i]] + w);
                s[v].insert(ans + w);
            }
            dp[b[i]] = ans;
        } else {
            ll last = dp[b[i]];
            dp[b[i]] = *s[b[i]].begin();
            s[b[i]].erase(s[b[i]].begin());
            s[b[i]].insert(dp[b[i]]);
            for (auto [v, w] : T[b[i]]) {
                s[v].extract(last + w);
                s[v].insert(dp[b[i]] + w);
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + dp[i] % mod * a[i] % mod) % mod;
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
