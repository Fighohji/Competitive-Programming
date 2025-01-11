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

int fa[N][18], dep[N];
int pre[N];
void dfs(int u, int p, const vector<vector<pii>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    for (auto &[v, id] : G[u])
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
    int n;
    cin >> n;
    assert(n <= 1E5);
    vector G(n + 1, vector<pii>());
    vector<int> x(n), y(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v >> x[i] >> y[i];
        assert(x[i] >= 1 && x[i] <= 1E5);
        assert(y[i] >= 1 && y[i] <= 1E5);
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }
    dfs(1, 0, G);
    init_lca(n);
    for (int i = 2; i <= n; ++i) {
        int lca = get_lca(i - 1, i);
        pre[i - 1]++, pre[i]++;
        pre[lca] -= 2;
    }
    vector<int> Id(n + 1);
    auto DFS = [&](auto self, int u, int p) -> void {
        for (auto &[v, id] : G[u]) {
            if (v == p) continue;
            Id[v] = id;
            self(self, v, u);
            pre[u] += pre[v];
        }
    };
    DFS(DFS, 1, 0);
    ll Ans = 0;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; ++i) {
        int nid = Id[i];
        Ans += min(1ll * x[nid] * pre[i], 1ll * y[nid]);
        if (1ll * x[nid] * pre[i] <= y[nid]) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cout << Ans << '\n';
    cerr << cnt0 << ' ' << cnt1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
