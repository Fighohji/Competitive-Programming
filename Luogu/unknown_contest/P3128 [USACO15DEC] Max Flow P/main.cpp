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

int fa[N][18], dep[N];
void dfs(int u, int p, const vector<vector<int>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
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
    int n, k;
    cin >> n >> k;
    vector G(n + 1, vector<int>());
    vector<int> pre(n + 1);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0, G);
    init_lca(n);
    for (int i = 0; i < k; ++i) {
        int s, t;
        cin >> s >> t;
        pre[s]++, pre[t]++;
        int lca = get_lca(s, t);
        pre[lca]--;
        pre[fa[lca][0]]--;
    }
    auto DFS = [&](auto self, int u, int p) -> void {
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            pre[u] += pre[v]; 
        }
    };
    DFS(DFS, 1, 0);
    int Ans = *max_element(all(pre));
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
