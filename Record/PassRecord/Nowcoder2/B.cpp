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
constexpr int maxn = 2e4 + 50;
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
int level[maxn * 100];//距离标号
int iter[maxn * 100];//当前弧
vector<edge>e[maxn * 100];

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

int n, m;
vector<pii> G[maxn];
int dep[maxn], fa[maxn], son[maxn], sz[maxn], id[maxn], in[maxn], top[maxn], val[maxn], dfn;
void dfs(int u, int p) {
	sz[u] = 1;
	fa[u] = p;
	dep[u] = dep[p] + 1;
	for (auto [v, c] : G[u]) {
		if (v == p) continue;
		val[v] = c;
		dfs(v, u);
		sz[u] += sz[v];
		if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
	}
}

void DFS(int u, int p) {
	in[u] = ++dfn;
	id[dfn] = u;
	top[u] = p;
	if (son[u]) DFS(son[u], p);
	for (auto [v, c] : G[u]) {
		if (v == fa[u] || v == son[u]) continue;
		DFS(v, v);
	}
}

int  idseg[maxn << 2];
int S, T;
void build(int p, int l, int r) {
	idseg[p] = ++dfn;
	if (l == r) {
		add_edge(dfn, T, val[id[l]]);
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	add_edge(idseg[p], idseg[p << 1], INF);
	add_edge(idseg[p], idseg[p << 1 | 1], INF);
}

void connect(int idx, int p, int l, int r, int ql, int qr) {
	if (ql > qr) return ;
	if (ql <= l && r <= qr) {
		add_edge(idx, idseg[p], INF);
		return ;
	}
	int mid = l + r >> 1;
	if (ql <= mid) connect(idx, p << 1, l, mid, ql, qr);
	if (mid < qr) connect(idx, p << 1 | 1, mid + 1, r, ql, qr);
}

int getlca(int &u, int &v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		connect(dfn, 1, 2, n, in[top[u]], in[u]);
		u = fa[top[u]];
	}
	return u;
}

void solve(int cas) {
	cin >> n >> m;
	for (int i = 1; i < n; ++i) {
		int u, v, c; cin >> u >> v >> c;
		G[u].eb(v, c);
		G[v].eb(u, c);
	}
	dfs(1, 0); DFS(1, 1);
	S = ++dfn, T = ++dfn;
	build(1, 2, n);
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v, x, y; cin >> u >> v >> x >> y;
		if (x <= y) continue;
		int lca = -1;		
		++dfn;
		add_edge(S, dfn, x - y);
		lca = getlca(u, v);
		if (dep[u] > dep[v]) swap(u, v);
		connect(dfn, 1, 2, n, in[u] + 1, in[v]);
		// while (dep[top[u]] > dep[lca]) {
		// 	connect(dfn, 1, 2, n, in[top[u]], in[u]);
		// 	u = fa[top[u]];
		// }
		// if (u != lca) connect(dfn, 1, 2, n, in[lca] + 1, in[u]);
		// while (dep[top[v]] > dep[lca]) {
		// 	connect(dfn, 1, 2, n, in[top[v]], in[v]);
		// 	v = fa[top[v]];
		// }
		// if (v != lca) connect(dfn, 1, 2, n, in[lca] + 1, in[v]);
		ans += x - y;
	}
	cout << ans - dinic(S, T) << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

