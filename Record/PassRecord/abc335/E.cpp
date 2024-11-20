#include <locale>
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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

vector<int> G[maxn], g[maxn];
int id[maxn], a[maxn], idx;

void dfs(int u) {
    id[u] = idx;
    for (auto v : G[u]) {
        if (a[v] == a[u] && !id[v])
            dfs(v);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!id[i]) {
            ++idx;
            dfs(i);
        }
    }
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i)
        for (auto v : G[i]) {
            if (a[v] > a[i]) {
                g[id[i]].pb(id[v]);
                deg[id[v]]++;
            }
        }
    vector<int> dis(n + 1, -INF), vis(n + 1);
    queue<int> q;
    for (int i = 1; i <= idx; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    dis[id[1]] = 1;

    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (auto v : g[p]) {
            int nd = dis[p] + 1;
            dis[v] = max(dis[v], nd);
            deg[v]--;
            if (!deg[v])
                q.push(v);
        }
    }
    cout << max(dis[id[n]], 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
