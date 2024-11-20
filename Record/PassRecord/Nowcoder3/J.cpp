#include <map>
#include <pthread.h>
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

vector<int>e[maxn];
vector<int>scm[maxn];
int stk[maxn],top,dfn[maxn],low[maxn],scc[maxn],sccnum,id;
vector<int> E[maxn];
void tarjan(int u) {
    if (dfn[u] != 0)return ;
    dfn[u] = low[u] = ++id;
    stk[++top] = u;
    for (auto v : e[u]) {
        if (dfn[v] == 0) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (scc[v] == 0)
            low[u] = min(dfn[v], low[u]);
    }
    if (dfn[u] == low[u]) {
        sccnum++;
        while (1) {
            scm[sccnum].push_back(stk[top]);
            scc[stk[top--]] = sccnum;
            if (stk[top + 1] == u) break;
        }
    }
}


void solve(int cas) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        e[u].eb(v);
    }
    for (int i = 1; i <= n; ++i) {
        tarjan(i);
    }
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (auto v : e[i]) {
            if (scc[i] != scc[v]) {
                E[scc[i]].eb(scc[v]);
                deg[scc[v]]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= sccnum; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    vector<int> rk(n + 1, 0);
    int now = 0;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        // rk[p] = now;
        // int pre = now;
        // now += SZ(scm[p]);
        for (auto i : scm[p]) {
            rk[i] = ++now;
        }
        for (auto v : E[p]) {
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    if (sccnum != n) {
        cout << 2 << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << rk[i] << ' ';
        }
        cout << '\n';
        for (int i = n; i >= 1; --i) {
            cout << rk[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << 1 << '\n';
        for (int i = 1; i <= n; ++i) {
            cout << rk[i] << ' ';
        }
        cout << '\n';
    }
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
