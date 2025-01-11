#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x)
{
	bool f = 0; x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = !f; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); }
	x = f ? -x : x;
}
const int N = 3e5 + 10;
int n, m, ans;
struct node2
{ int u, v, len; }q[N];
struct node
{ int v, w; };
int x[N], y[N];
vector <node> e[N];
int fa[N], dep[N], top[N], siz[N], son[N];
int length[N];
int cmp(node2 x, node2 y)
{ return x.len > y.len; };
void dfs1(int u, int f)
{
	fa[u] = f;
	dep[u] = dep[f] + 1;
	siz[u] = 1;
	int t = -1;
	for (int i = 0; i < e[u].size(); i ++)
	{
		int v = e[u][i].v;
		if (v == f) continue;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > t) t = siz[v], son[u] = v;
	}
}
void dfs2(int u, int f)
{
	top[u] = f;
	if (!son[u]) return;
	dfs2(son[u], f);
	for (int i = 0; i < e[u].size(); i ++)
	{
		int v = e[u][i].v;
		if (v == son[u] || v == fa[u]) continue;
		dfs2(v, v);
	}
}
int lca(int u, int v)
{
	while (top[u] != top[v])
	{
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	if (dep[u] > dep[v]) swap(u, v);
	return u;
}
void dfs(int u, int f, int w)
{
	length[u] = length[f] + w;
	for (int i = 0; i < e[u].size(); i ++) 
		if (e[u][i].v != f) dfs(e[u][i].v, u, e[u][i].w);
}
int cnt[N], res;
void fuckyou(int u, int f, int now, int w)
{
	for (int i = 0; i < e[u].size(); i ++)
	{
		int v = e[u][i].v;
		if (v == f) continue;
		fuckyou(v, u, now, e[u][i].w);
		cnt[u] += cnt[v];
	}
}
int check(int t)
{
	for (int i = 1; i <= n; i ++) cnt[i] = 0;
	res = 0;
	int now = 0;
	for (int i = 1; i <= m; i ++)
	{
		if (q[i].len <= t) break;
		now = i;
		int u = q[i].u, v = q[i].v;
		int d = lca(u, v);
		cnt[u] ++, cnt[v] ++, cnt[d] -= 2;
	}
	fuckyou(1, 0, now, 0);
	if (q[1].len - res <= t) return 1;
	return 0;
}
int main()
{
	read(n); read(m);
	int u, v, w;
	int ww = 0;
	for (int i = 1; i < n; i ++)
	{
		read(u); read(v); read(w);
		e[u].push_back({v, w});
		e[v].push_back({u, w});
		ww = max(ww, w);
	}
	for (int i = 1; i <= m; i ++) read(q[i].u), read(q[i].v);
	dfs(1, 0, 0);
	dfs1(1, 0);
	dfs2(1, 1);
	for (int i = 1; i <= m; i ++)
	{
		int u = q[i].u, v = q[i].v;
		int d = lca(u, v);
		q[i].len = length[u] + length[v] - length[d] * 2;
	}
	sort(q + 1, q + 1 + m, cmp);
	int l = q[1].len - ww, r = q[1].len;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}
