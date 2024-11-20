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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

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


void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v), G[v].pb(u);
    }
    vector<int> dep(n + 1);
    vector fa(n + 1, vector<int>(18)), pre(n + 1, vector<int>(30)), las(n + 1, vector<int>(30));
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        dep[u] = dep[p] + 1;
        fa[u][0] = p;
        pre[u] = pre[p];
        las[u] = las[p];
        for (int i = 0; i < 30; ++i)
            if ((1 << i) & a[u]) {
                pre[u][i]++;
                las[u][i] = u;
            }
        for (auto v : G[u]) {
            if (v != p) {
                dfs(dfs, v, u);
            }
        }
    };
    dfs(dfs, 1, 0);

    for (int j = 1; j < 18; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];

    auto getLca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 17; i >= 0; --i)
            if (dep[fa[u][i]] >= dep[v])
                u = fa[u][i];
        if (u == v) return u;
        for (int i = 17; i >= 0; --i)
            if (fa[u][i] != fa[v][i])
                u = fa[u][i], v = fa[v][i];
        return fa[u][0];
    };

    int q; cin >> q;
    while (q--) {
        auto getVal = [&](int u, int v, int lca, int bit) {
            return pre[u][bit] + pre[v][bit] - pre[lca][bit] - pre[fa[lca][0]][bit] > 0;
        };
        auto query = [&](int x, int y, int l) {
            int res = 0;
            for (int i = 0; i < 30; ++i)
                res += getVal(x, y, l, i);
            return res;
        };
        int u, v; cin >> u >> v;
        int lca = getLca(u, v);
        int ans = 0;
        for (int i = 0; i < 30; ++i) {
            int top = las[u][i];
            if (dep[top] < dep[lca]) continue;
            ans = max(ans, query(u, top, top) + query(v, top, lca));
        }
        for (int i = 0; i < 30; ++i) {
            int top = las[v][i];
            if (dep[top] < dep[lca]) continue;
            ans = max(ans, query(u, top, lca) + query(v, top, top));
        }
        cout << ans << ' ';
    }
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}

