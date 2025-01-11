#include <cassert>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
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
    int n, m, s;
    cin >> n >> m >> s;
    assert(n >= 1 && n <= 2E5);
    assert(m >= 1 && m <= 2E5);
    assert(s >= 1 && s <= n);
    vector G(n + 1, vector<pii>());
    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        assert(u != v);
        assert(u >= 1 && u <= n);
        assert(v >= 1 && v <= n);
        assert(w >= 0 && w <= 1000000000);
        sum += w;
        G[u].emplace_back(v, w);
    }
    assert(sum <= 1000000000 && sum >= 0);
    vector<bool> v(n + 1);
    auto dfs = [&](auto self, int u) -> void {
        if (v[u]) return;
        v[u] = 1;
        for (auto &[v, w] : G[u]) {
            self(self, v);
        }
    };
    dfs(dfs, s);
    for (int i = 1; i <= n; ++i) {
        assert(v[i] == 1);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    vector<int> dis(n + 1, INF);
    dis[s] = 0;
    vector<bool> vis(n + 1);
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[v, w] : G[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << " \n"[i == n];
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
