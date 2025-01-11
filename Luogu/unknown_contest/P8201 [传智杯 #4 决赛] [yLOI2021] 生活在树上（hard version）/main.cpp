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

constexpr int N = 5e5 + 50;
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

int fa[N][20], dep[N], w[N], pre[N];
void dfs(int u, int p, const vector<vector<int>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    pre[u] = pre[p] ^ w[u];
    for (auto v : G[u])
        if (v != p) dfs(v, u, G);
}
void init_lca(int n) {
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i)) v = fa[v][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

struct Qry {
    int id, dep, val;
};
vector<Qry> qry[N];
int buc[20000001];
void solve() {
    int n, m;
    cin >> n >> m;
    assert(n <= 300000 && m <= 300000);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        assert(w[i] >= 0 && w[i] <= 1000000);
    }

    vector G(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dep[0] = 1;
    dfs(1, 0, G);
    init_lca(n);

    for (int i = 0; i < m; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        assert(k <= 10000000);
        int lca = get_lca(a, b);
        int val = pre[a] ^ pre[b] ^ w[lca] ^ k;
        qry[a].emplace_back(i, dep[lca], val);
        qry[b].emplace_back(i, dep[lca], val);
    }
    vector<bool> Ans(m);
    auto DFS = [&](auto self, int u, int p) -> void {
        int tmp = buc[w[u]];
        buc[w[u]] = dep[u];
        for (auto &[id, d, val] : qry[u]) {
            if (buc[val] >= d) Ans[id] = 1;
        }
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
        }
        buc[w[u]] = tmp;
    };
    DFS(DFS, 1, 0);
    for (int i = 0; i < m; ++i) {
        cout << (Ans[i] ? "Yes\n" : "No\n");
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
