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


int root[maxn], cnt[maxn << 5], ls[maxn << 5], rs[maxn << 5], idx;
void ins(int p, int &np, int l, int r, int pos, int val) {
    np = ++idx;
    cnt[np] = cnt[p], ls[np] = ls[p], rs[np] = rs[p];
    cnt[np] += val;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) ins(ls[p], ls[np], l, mid, pos, val);
    else ins(rs[p], rs[np], mid + 1, r, pos, val);
}
ll qry(int p, int np, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return cnt[np] - cnt[p];
    int mid = l + r >> 1;
    ll res = 0;
    if (ql <= mid) res += qry(ls[p], ls[np], l, mid, ql, qr);
    if (mid < qr) res += qry(rs[p], rs[np], mid + 1, r, ql, qr);
    return res;
}

ll Ans[maxn], sum;
vector<int> G[maxn];
int in[maxn], out[maxn], dfn, n;

void dfs(int u, int p) {
    in[u] = ++dfn;
    ins(root[dfn - 1], root[dfn], 1, n, u, 1);
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    out[u] = dfn;
    sum += qry(root[in[u] - 1], root[out[u]], 1, n, 1, u) - 1;
}

void DFS(int u, int p) {
    Ans[u] = sum;
    for (auto v : G[u]) {
        if (v == p) continue;
        ll det = v - qry(root[in[v] - 1], root[out[v]], 1, n, 1, v) - qry(root[in[v] - 1], root[out[v]], 1, n, 1, u);
        sum += det;
        DFS(v, u);
        sum -= det;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1, 0);
    DFS(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << " \n"[i == n];
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
