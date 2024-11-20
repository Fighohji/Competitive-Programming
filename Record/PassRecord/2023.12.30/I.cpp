
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int n,m,k,d;
ll dis_n[N],dis_p[N],dis_1[N];
void dij(vector<vector<pll>> &mp,int s, ll* dis,int op)
{
    vector<int> vis(n+2,0);
    dis[s]=0;
    priority_queue<pll> q;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        auto x=q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x]++;
        for(auto [y,d]:mp[x])
        {
            if(dis[y]<=dis[x]+d) continue;
            // if(vis[y]) continue;
            dis[y]=dis[x]+d;
            // if(op&&dis_p[y]>d) break;
            q.push(make_pair(-dis[y],y));
        }
    }
}
ll cal(ll l,ll r)
{
    return (l+r)*(r-l+1)/2;
}
ll gt(ll x)
{
    ll ans=x/(d)*cal(1,d);
    if(x%d)
    {
        ans+=cal(d-(x%(d))+1,d);
    }
    return ans;
}
void print(ll* x)
{
    for(int i=1;i<=n;++i) cout<<x[i]<<' ';
        cout<<endl;
}
void solve() {
    cin>>n>>m>>k>>d;
    for(int i=1;i<=n;++i)
    {
        dis_n[i]=dis_p[i]=dis_1[i]=1e18;
    }
    vector vt(n + 1, vector<pll>());
    for(int i=1;i<=m;++i)
    {
        ll a,b;cin>>a>>b;
        vt[a].push_back({b,1});
        vt[b].push_back({a,1});
    }
    dij(vt,n,dis_n,0);
    dij(vt,k,dis_p,0);
    vector vt2(n + 1, vector<pll>());
    for(int i=1;i<=n;++i)
    {
        // // if(dis_p[i]>d+1) continue;
        for(auto &[a,b]:vt[i])
        {
            if(dis_p[a]<d) vt2[i].push_back({a,d-dis_p[a]});
            // else vt2[i].push_back({a,d});
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     cout<<i<<' '<<endl;
    //     for(auto [a,b]:vt2[i]) cout<<a<<' '<<b<<endl;
    // }
    // print(dis_n);
    // print(dis_p);
    dij(vt2,1,dis_1,0);
    // print(dis_1);
    ll ans=dis_1[n];
    for(int i=1;i<=n;++i)
    {
        // if(dis_p[i]>=d)
        {
            for(auto [x, y] : vt[i])
            {
                if(dis_p[x] >= d)
                    ans = min(ans, dis_1[i] + gt(dis_n[i]));
            }
            // ans=min(ans,dis_1[i] + gt(dis_n[i]));
        }
    }
    // get(dis_n[1]);
    cout<<ans<<endl;
}


signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
