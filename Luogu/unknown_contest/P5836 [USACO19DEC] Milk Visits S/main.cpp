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

int fa[N][18], dep[N];
string type;
int pre[N][2];
void dfs(int u, int p, const vector<vector<int>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    pre[u][type[u - 1] == 'H']++;
    pre[u][0] += pre[p][0];
    pre[u][1] += pre[p][1];
    for (auto v : G[u])
        if (v != p) dfs(v, u, G);
}
void init_lca(int n) {
    for (int j = 1; j < 18; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 17; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i)) v = fa[v][i];
    if (u == v) return u;
    for (int i = 17; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
void solve() {
    int n, m;
    cin >> n >> m;
    cin >> type;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, G);
    init_lca(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        string c;
        cin >> a >> b >> c;
        int lca = get_lca(a, b);
        int tp = c == "H";
        int len = dep[a] + dep[b] - dep[lca] - dep[fa[lca][0]];
        int cnt = pre[a][tp] + pre[b][tp] - pre[lca][tp] - pre[fa[lca][0]][tp];
        cout << (len - cnt != len);
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
