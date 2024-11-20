#include <map>
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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
#define db double
#define il inline
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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
/*
2
12 2 4
1 9
1 2 1
2 3 4
3 4 3
3 5 2
2 6 2
6 7  1
6 8 2
2 9 5
9 10 2
9 11 3
1 12 10
3 3 7 8
4 4 5 7 8
4 7 8 10 11
3 4 5 12
3 2 3
1 2
1 2 1
1 3 1
1 1
2 1 2
3 1 2 3
*/
bool BEGIN;
#define int long long

int fa[maxn][18], dep[maxn];
int Dep[maxn];
void init_lca(int n) {
    for (int j = 1; j < 18; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 17; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i))
            v = fa[v][i];
    if (u == v) return u;
    for (int i = 17; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int dis[maxn];
bool imp[maxn];
vector<pii> e[maxn];
void Clear(int n) {
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        imp[i] = 0;
    }
}
void dfs(int u, int p) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    if (imp[u]) dis[u] = 0;
    for (auto [v, w] : e[u]) {
        if (v == p) continue;
        Dep[v] = Dep[u] + w;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}
void solve() {
    int n, m, q; cin >> n >> m >> q;
    Clear(n);
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x;
        imp[x] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        e[u].eb(v, w);
        e[v].eb(u, w);
    }
    dfs(1, 0);
    init_lca(n);
    while (q--) {
        int k; cin >> k;
        vector<int> p(k + 2);
        for (int i = 1; i <= k; ++i) {
            cin >> p[i];
        }
        p[k + 1] = 0;
        sort(p.begin() + 1, p.end() - 1, [&](int x, int y) {
            return dis[x] > dis[y];
        });
        int ans = dis[p[1]];
        int lca = p[1], Mx = 0;
        for (int i = 1; i <= k; ++i) {
            lca = get_lca(lca, p[i]);
            Mx = max(Mx, Dep[p[i]]);
            int Dis = Mx - Dep[lca];
            ans = min(ans, max(Dis, dis[p[i + 1]]));
        }
        cout << ans << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
