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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
constexpr int maxm = 4e5 + 50;
mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

string s[310];
int n, m;
int cnt = 0;
int tot = 0;
int st, ed;
// struct edge {
//     int v,cap,nxt;
// };
// int level[maxn];//距离标号
// int iter[maxn];//当前弧
// int tt = 1;
// int head[maxn];
// edge e[maxn];

// void add_edge(int u,int v,int cap, int w = 0) {
//     e[++tt]=((edge){v, cap, head[u]});
//     head[u] = tt;
//     e[++tt]=((edge){u, w, head[v]});
//     head[v] = tt;
// }

// void bfs(int s) {
//     for(int i = 0; i <= tot; ++i) level[i] = -1;
//     // memset(level,-1,sizeof(level));
//     queue<int>que;
//     level[s] = 0;
//     que.push(s);
//     while (!que.empty()) {
//         int v = que.front(); que.pop();
//         for (int i = head[v]; i; i = e[i].nxt) {
//             edge &tmp = e[i];
//             if(tmp.cap > 0 && level[tmp.v] < 0) {
//                 level[tmp.v] = level[v] + 1;
//                 que.push(tmp.v);
//             }
//         }
//     }
// }

// int dfs(int v,int t,int f) {
//     if (v == t)
//         return f;
//     for (int i = iter[v]; i; i = e[i].nxt)
//     {
//         edge &tmp = e[i];
//         if (tmp.cap > 0 && level[v] < level[tmp.v])
//         {
//             int d = dfs(tmp.v, t, min(f, tmp.cap));
//             if (d > 0) {
//                 tmp.cap -= d;
//                 e[i ^ 1].cap += d;
//                 return d;
//             }
//         }
//     }
//     return 0;
// }
// int flow;
// void dinic(int s,int t) {
//     // int flow = 0;
//     for (; ;) {
//         bfs(s);
//         if(level[t] < 0) return ;
//         // for(int i = 0; i <= tot; ++i) iter[i] = 0;
//         memset(iter, 0, sizeof(int) * (tot + 1));
//         int f;
//         while ((f = dfs(s, t, INF)) > 0)
//             flow += f;
//     }
// }
struct MaximumFlow
{
    //maxn 最多点数 maxm 最多边数
    int h[maxn],e[maxm],ne[maxm],f[maxm],idx;
    int d[maxn],cur[maxn];
    int n,m,S,T,mxn;
    ll mp_vis[maxn];
    ll col[maxn],ans[maxn];
    ll flag=0;
    void init(int n,int _s,int _t)
    {
        mxn=n,idx=0,S=_s,T=_t;//mxn表示最大点的大小（包括S，T），用于初始化处理，_s表示源点，_T表示汇点
        // memset(h,-1,sizeof h);
        while(n>=0)
            h[n--]=-1;
    }
    void addedge(int a,int b,int c)
    {
        ne[idx]=h[a],e[idx]=b,f[idx]=c,h[a]=idx++;
        ne[idx]=h[b],e[idx]=a,f[idx]=0,h[b]=idx++;
    }
    bool bfs()
    {
        // memset(d,-1,sizeof d);
        for(int i=0;i<=mxn;++i) d[i]=-1;
        d[S]=0;
        queue<int>q;
        q.push(S);
        cur[S]=h[S];
        while(q.size())
        {
            int t=q.front();
            q.pop();
            for(int i=h[t];i!=-1;i=ne[i])
            {
                int j=e[i];
                if(d[j]==-1&&f[i])
                {
                    d[j]=d[t]+1;
                    cur[j]=h[j];
                    if(j==T)return true;
                    q.push(j);
                }
            }
        }
        return false;
    }
    int find(int u,int limit)
    {
        if(u==T)return limit;
        int flow=0;
        for(int i=cur[u];i!=-1&&flow<limit;i=ne[i])
        {
            cur[u]=i;
            int j=e[i];
            if(d[j]==d[u]+1&&f[i])
            {
                int t=find(j,min(f[i],limit-flow));
                if(!t)d[j]=-1;
                f[i]-=t,f[i^1]+=t,flow+=t;
            }
        }
        return flow;
    }
    int dinic()
    {
        int r=0,flow;
        while(bfs())while(flow=find(S,INF))r+=flow;
        return r;
    }
}f;

void build(int x)
{
    // for(int i = 1; i <= n * m + 2 + n + m; ++i) e[i].clear();
    // for(int i = 1; i <= n * m + 2 + n + m; ++i) level[i] = 0;
    if(!x)
    {
        f.init(n * m + n + m + 2, st, ed);
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(s[i][j] == '.')
                {
                    cnt++;
                    f.addedge(n * m + i, (i - 1) * m + j + 1, 1);
                    f.addedge((i - 1) * m + j + 1, n * m + n + j + 1, 1);
                }
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            f.addedge(n * m + n + m + 1, n * m + i, x);
        }
        for(int i = 1; i <= m; ++i)
        {
            f.addedge(n * m + n + i, n * m + n + m + 2, x);
        }
    }
    else
    {

    }
}
void solve() {
    cin >> n >> m;
    ll c, d; cin >> c >> d;
    tot = n * m + n + m + 2;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    st = n * m + n + m + 1;
    ed = n * m + n + m + 2;
    build(0);
    ll res = d * cnt;
    for(int i = 1; i <= max(n, m); ++i)
    {
        build(i);
        dinic(st, ed);
        // cout << i << ' ' << flow << ' ' << cnt << '\n';
        res = min(res, i * c + d * (cnt - flow));
    }
    cout << res << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}

