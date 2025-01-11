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

int fa[N][18], dep[N], pre[N];
void dfs(int u, int p, const vector<vector<pii>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    for (auto &[v, w] : G[u])
        if (v != p) {
            pre[v] = pre[u] ^ w;
            dfs(v, u, G);
        }
}
void init_lca(int n) {
    for (int j = 1; j < 18; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    int Ans = 0;
    while (u != v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = fa[u][0];
        Ans++;
    }
    return Ans;
}
void solve() {
    int n, m;
    cin >> n;
    vector G(n + 1, vector<pii>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(1, 0, G);
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int lca = get_lca(a, b);
        cout << (pre[a] ^ pre[b]) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
