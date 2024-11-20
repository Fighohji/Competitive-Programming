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

#define int long long

struct LCA {
    int fa[N][18], dep[N], w[N][18];
    void dfs(int u, int p, const vector<vector<pii>> &G) {
        fa[u][0] = p;
        dep[u] = dep[p] + 1;
        for (auto &[v, c] : G[u])
            if (v != p) {
                w[v][0] = c;
                dfs(v, u, G);
            }
    }
    void init_lca(int n) {
        for (int j = 1; j < 18; ++j)
            for (int i = 1; i <= n; ++i) {
                fa[i][j] = fa[fa[i][j - 1]][j - 1];
                w[i][j] = w[fa[i][j - 1]][j - 1] + w[i][j - 1];
            }
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

} T1, T2;
void solve() {
    int n;
    cin >> n;
    n--;
    vector<int> h(n + 2, INF);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    vector<int> stk, nxt(n + 2, n + 1), pre(n + 2, 0);
    stk.push_back(n + 1);
    for (int i = n; i >= 1; --i) {
        while (h[i] >= h[stk.back()]) stk.pop_back(); 
        nxt[i] = stk.back();
        stk.push_back(i);
    }
    stk.clear();
    stk.push_back(0);
    for (int i = 1; i <= n; ++i) {
        while (h[i] >= h[stk.back()]) stk.pop_back(); 
        pre[i] = stk.back();
        stk.push_back(i);
    }
    vector G(n + 1, vector<pii>());
    for (int i = 1; i <= n; ++i) {
        G[i].push_back({nxt[i], h[nxt[i]] * (nxt[i] - i)});
    }
    T1.dfs(1, 0, G);
    T1.init_lca(n);
    vector nG(n + 2, vector<pii>());
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i) {
        nG[i].push_back({pre[i], h[pre[i]] * (i - pre[i])});
        deg[pre[i]]++;
        cerr << i << ' ' << pre[i] << '\n';
    }
    for (int i = 1; i <= n; ++i) {
        if (!deg[pre[i]])
            nG[n + 1].push_back({i, 0});
    }
    T2.dfs(n + 1, 0, nG);
    T2.init_lca(n);
    int q;
    cin >> q;
    cerr << T2.fa[4][0] << '\n';
    while (q--) {
        int x, y;
        cin >> x >> y;
        int Ans = 0;
        y--;
        if (x <= y) {
            cerr << y << '\n';
            for (int i = 17; i >= 0; --i) {
                if (T2.fa[y][i] >= x) {
                    Ans += T2.w[y][i];
                    y = T2.fa[y][i];
                    cerr << y << '\n';
                }
            }
            cerr << "!!!  " << y << ' ' << '\n';
            Ans += (y - pre[y]) * h[y];
        } else {
            for (int i = 17; i >= 0; --i) {
                if (T1.fa[x][i] >= y) {
                    Ans += T1.w[x][i];
                    x = T1.fa[x][i];
                }
            }
            Ans += (x - y + 1) * h[x];
        }
        cout << Ans << '\n';
        cerr << "------\n";
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

