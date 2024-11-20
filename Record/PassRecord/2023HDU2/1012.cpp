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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct edge {
    int v,cap,rev;
};
int level[maxn];//距离标号
int iter[maxn];//当前弧
vector<edge>e[maxn];

void add_edge(int u,int v,int cap, int w = 0) {
    e[u].push_back((edge){v,cap,(int)e[v].size()});
    e[v].push_back((edge){u,w,(int)e[u].size()-1});
}

void bfs(int s) {
    memset(level,-1,sizeof(level));
    queue<int>que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < e[v].size(); ++i) {
            edge &tmp = e[v][i];
            if(tmp.cap > 0 && level[tmp.v] < 0) {
                level[tmp.v] = level[v] + 1;
                que.push(tmp.v);
            }
        }
    }
}

int dfs(int v,int t,int f) {
    if (v == t)
        return f;
    for (int &i = iter[v]; i < e[v].size(); ++i)
    {
        edge &tmp = e[v][i];
        if (tmp.cap > 0 && level[v] < level[tmp.v])
        {
            int d = dfs(tmp.v, t, min(f, tmp.cap));
            if (d > 0) {
                tmp.cap -= d;
                e[tmp.v][tmp.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int dinic(int s,int t) {
    int flow = 0;
    for (; ;) {
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0)
            flow += f;
    }
}


void solve(int cas) {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> now(n + 1, 0);
    int idx = 0;
    int S = ++idx;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (!now[u]) {
            add_edge(S, ++idx, 1);
            now[u] = idx;
        } else {
            add_edge(now[u], ++idx, a[u]);
            now[u] = idx;
        }
        if (!now[v]) {
            add_edge(S, ++idx, 1);
            now[v] = idx;
        } else {
            add_edge(now[v], ++idx, a[v]);
            now[v] = idx;
        }
        add_edge(now[u], now[v], 1, 1);
    }
    int T = ++idx;
    for (int i = 1; i <= k; ++i) {
        int u; cin >> u;
        if (!now[u]) {
            add_edge(S, T, 1);
        } else {
            add_edge(now[u], T, a[u]);
        }
    }
    cout << dinic(S, T) << '\n';
    for (int i = 1; i <= idx; ++i) {
        e[i].clear();
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
