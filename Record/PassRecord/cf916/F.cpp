#include <map>
#include <numeric>
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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

void solve() {
    int n; cin >> n;
    vector G(n + 1, vector<int>());
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].pb(i);
    }
    ll ans = 0;
    vector<ll> sz(n + 1), h(n + 1);
    auto DFS = [&](auto &&DFS, int u) ->void {
        h[u] = 1;
        for (auto v : G[u]) {
            DFS(DFS, v);
            h[u] = max(h[u], h[v] + 1);
        }
    };
    int pre = 0;
    auto dfs = [&](auto &&dfs, int u) ->void {
        sz[u] = 1;
        sort(all(G[u]), [&](int x, int y) {
            return h[x] > h[y];
        });
        for (auto v : G[u]) {
            // cout << v << '\n';
            dfs(dfs, v);
            sz[u] += sz[v];
        }
        if (pre - sz[u] + 1 > 0) {
            ans++;
            pre--;
            sz[u]--;
            return;
        }
        pre++;
    };
    DFS(DFS, 1);
    dfs(dfs, 1);
    cout << ans << '\n';
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
