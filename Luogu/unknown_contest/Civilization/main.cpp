#include <algorithm>
#include <cassert>
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

struct DSU {
    vector<int> fa, d;
    DSU() {}
    DSU(int n) {
        fa.resize(n + 1);
        d.resize(n + 1);
        iota(all(fa), 0);
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        fa[yy] = xx;
        d[xx] = max({d[xx], d[yy], (d[xx] + 1) / 2 + (d[yy] + 1) / 2 + 1});
    }
};
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    assert(n >= 1 && n <= 300000 && m < n && m >= 0 && q >= 1 && q <= 300000);
    vector G(n + 1, vector<int>());
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        assert(u >= 1 && u <= n);
        assert(v >= 1 && v <= n);
        assert(u != v);
        G[u].push_back(v);
        G[v].push_back(u);
        dsu.merge(u, v);
    }
    int tmp, Max;
    vector<bool> vis(n + 1);
    auto dfs = [&](auto self, int u, int p, int dep) -> void {
        vis[u] = 1;
        if (dep > Max) {
            Max = dep;
            tmp = u;
        }
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u, dep + 1);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        Max = 0;
        tmp = i;
        dfs(dfs, i, 0, 0);
        Max = 0;
        dfs(dfs, tmp, 0, 0);
        dsu.d[dsu.find(i)] = Max;
    }
    while (q--) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x;
            cout << dsu.d[dsu.find(x)] << '\n';
        } else {
            cin >> x >> y;
            dsu.merge(x, y);
        }
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
