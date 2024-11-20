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
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

vector<int> G[maxn], link[maxn];
int fa[maxn], son[maxn], sz[maxn];
void DFS(int u, int p) {
    link[p].pb(u);
    if (son[u]) DFS(son[u], p);
    for (auto v : G[u]) {
        if (v == fa[u] || v == son[u]) continue;
        DFS(v, v);
    }
};
void dfs(int u, int p) {
    sz[u] = 1;
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] = max(sz[v] + 1, sz[u]);
        if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        G[i].clear(); link[i].clear();
        fa[i] = 0, son[i] = 0, sz[i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        int f; cin >> f;
        fa[i] = f;
        G[f].pb(i);
    }
    dfs(1, 0); DFS(1, 1);
    int ans = n;
    sort(link + 1, link + 1 + n, [&](vector<int> &x, vector<int> &y){
        return SZ(x) > SZ(y);
    });
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, i - 1 + SZ(link[i]));
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
