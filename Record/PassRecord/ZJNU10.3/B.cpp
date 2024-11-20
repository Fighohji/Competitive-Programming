#include <map>
#include <numeric>
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

struct Nxt {
    int v, id;
};

struct Move {
    int buc[maxn], cnt[maxn], Max;
    void add(int x) {
        if (cnt[buc[x]]) cnt[buc[x]]--;
        buc[x]++;
        cnt[buc[x]]++;
        if (buc[x] > Max) Max = buc[x];
    }
    void del(int x) {
        cnt[buc[x]]--;
        buc[x]--;
        if (buc[x]) cnt[buc[x]]++;
        if (cnt[Max] == 0 && Max) Max--;
    }
} M[2];

vector<Nxt> G[maxn];

bool inStk[maxn];
int low[maxn], stk[maxn], dfn[maxn], belong[maxn], clk, top, blockCnt;
void tarjan(int u, int p) {
    if (dfn[u]) return ;
    low[u] = dfn[u] = ++clk;
    stk[++top] = u; inStk[u] = 1;
    for (auto [v, id] : G[u]) {
        if (p == id) continue;
        if (!dfn[v]) {
            tarjan(v, id);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        blockCnt++;
        while (stk[top] != u) {
            belong[stk[top]] = blockCnt;
            inStk[stk[top--]] = 0;
        }
        belong[u] = blockCnt;
        inStk[u] = 0;
        top--;
    }
}
void Clear(int n) {
    M[0].Max = M[1].Max = clk = top = blockCnt = 0;
    for (int i = 0; i <= n; ++i) {
        M[0].buc[i] = 0, M[0].cnt[i] = 0;
        M[1].buc[i] = 0, M[1].cnt[i] = 0;
        G[i].clear();
        inStk[i] = 0;
        low[i] = stk[i] = dfn[i] = belong[i] = 0;
    }
}

void solve() {
    int n, m; cin >> n >> m;
    Clear(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector E(n, vector<Nxt>());
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].eb(v, i);
        G[v].eb(u, i);
    }

    for (int i = 0; i < n; ++i)
        tarjan(i, INF);

    vector num(blockCnt + 1, vector<int>());
    for (int i = 0; i < n; ++i)
        for (auto [v, id] : G[i])
            if (belong[v] != belong[i])
                E[i].pb({v, id});

    for (int i = 0; i < n; ++i)
        num[belong[i]].pb(a[i]);

    int idx = 0;

    vector<bool> vis(n + 1);
    vector<int> in(n + 1, n + 1), out(n + 1), Id(n + 1), sz(n + 1), son(n + 1, n);
    auto DFS = [&] (auto &&DFS, int u, int p) -> void {
        vis[belong[u]] = 1;
        in[u] = ++idx;
        Id[idx] = u;
        sz[u] = 1;
        for (auto [v, id] : E[u]) {
            if (v == p) continue;
            DFS(DFS, v, u);
            sz[u] += sz[v];
            if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
        }
        out[u] = idx;
    };
    vector<int> Ans(m + 1, 0);
    auto DSU = [&] (auto &&DSU, int u, bool keep, int extra, int p) -> void {
        int sonid;
        for (auto [v, id] : E[u]) {
            if (v == son[u]) sonid = id;
            if (id == p || v == son[u]) continue;
            DSU(DSU, v, 0, extra, id);
        }
        if (son[u] != n) DSU(DSU, son[u], 1, extra, sonid);
        for (auto [v, id] : E[u]) {
            if (id == p || v == son[u]) continue;
            for (int i = in[v]; i <= out[v]; ++i) {
                for (auto x : num[belong[Id[i]]])
                    M[0].add(x), M[1].del(x);
            }
        }
        for (auto x : num[belong[u]])
            M[0].add(x), M[1].del(x);
        if (p != INF) Ans[p] = M[0].Max + M[1].Max - extra;
        if (!keep) {
            for (int i = in[u]; i <= out[u]; ++i)
                for (auto x : num[belong[Id[i]]])
                    M[0].del(x), M[1].add(x);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!vis[belong[i]]) {

            DFS(DFS, i, INF);
            for (int j = in[i]; j <= out[i]; ++j)
                for (auto x : num[belong[Id[j]]])
                    M[1].add(x);
            Ans[m] += M[1].Max;
            DSU(DSU, i, 0, M[1].Max, INF);
            for (int j = in[i]; j <= out[i]; ++j)
                for (auto x : num[belong[Id[j]]])
                    M[1].del(x);
        }
    }
    for (int i = 0; i < m; ++i)
        cout << Ans[i] + Ans[m] << " \n"[i == m - 1];
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
