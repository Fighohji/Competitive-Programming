#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, r, m;
    cin >> n >> r >> m;
    vector G(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<ll> Ans(n + 1), sz(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
        sz[u] = 1;
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
        Ans[u] = sz[u];
        for (auto v : G[u]) {
            if (v == p) continue;
            Ans[u] += (sz[u] - sz[v]) * sz[v];
        }
    };
    dfs(dfs, r, 0);
    for (int i = 0; i < m; ++i) {
        int p;
        cin >> p;
        cout << Ans[p] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
