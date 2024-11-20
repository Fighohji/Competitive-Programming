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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define int long long

vector<int>e[maxn];
vector<int>scm[maxn];
int stk[maxn],top,dfn[maxn],low[maxn],scc[maxn],sccnum,id;
void tarjan(int u)
{
    if(dfn[u]!=0)return ;
    dfn[u]=low[u]=++id;
    stk[++top]=u;
    for(auto v:e[u]) 
    {
        if(dfn[v]==0)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(scc[v]==0)
            low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u])
    {
        sccnum++;
        while(1)
        {
            scm[sccnum].push_back(stk[top]);
            scc[stk[top--]]=sccnum;
            if(stk[top+1]==u)break;
        }
    }
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), val(n + 1), cnt(n + 1);
    vector G(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        scm[i].clear();
        scc[i] = stk[i] = 0;
        top = 0, id = 0, sccnum = 0;
        dfn[i] = low[i] = 0;
        cin >> a[i];
    }
    map<pii, bool> mp;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        if (mp.count({u, v})) continue;
        mp[{u, v}] = 1;
        e[u].pb(v);        
    }
    for (int i = 1; i <= n; ++i) {
        tarjan(i);
    }
    for (int i = 1; i <= sccnum; ++i) {
        cnt[i] = SZ(scm[i]);
        for (auto j : scm[i]) {
            val[i] += a[j];
        }
    }
    vector<int> dp_cnt(n + 1), dp_val(n + 1, LINF), deg(n + 1);
    for (int i = 1; i  <= n; ++i) {
        for (auto j : e[i]) {
            if (scc[i] == scc[j]) continue;
            G[scc[i]].pb(scc[j]);
            deg[scc[j]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= sccnum; ++i) {
        if (deg[i] == 0) {
            q.push(i);
            dp_cnt[i] = cnt[i];
            dp_val[i] = val[i];
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        for (auto v : G[p]) {
            if (dp_cnt[p] + cnt[v] > dp_cnt[v]) {
                dp_cnt[v] = dp_cnt[p] + cnt[v];
                dp_val[v] = dp_val[p] + val[v];
            } else if (dp_cnt[p] + cnt[v] == dp_cnt[v]) {
                dp_val[v] = min(dp_val[v], dp_val[p] + val[v]);
            }
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
    int Max = *max_element(all(dp_cnt));
    int ans = LINF;
    for (int i = 1; i <= sccnum; ++i) {
        if (dp_cnt[i] == Max) {
            ans = min(ans, dp_val[i]);
        }
    }
    cout << Max << ' ' << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

