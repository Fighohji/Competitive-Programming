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
constexpr int mod = 998244353; /*998244353;*/ /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

const ll N=1e5+10;
struct ty
{
    ll t,l,next;
}edge[N<<1];
ll cn=0;
ll head[N];
void add(ll a,ll b)
{
    edge[++cn].t=b;
    edge[cn].next=head[a];
    head[a]=cn;
}
ll n,m,k;
ll a,b;
ll ans1=0,ans2=0;
ll vis[N],dis[N];
void dij()
{
    priority_queue<pair<ll,ll>> q;
    memset(dis,0x3f,sizeof dis);
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {
        auto ty=q.top();
        q.pop();
        ll id=ty.second;
        if(vis[id]) continue;
        vis[id]++;
        if(dis[id]<=k) ans1++;
        // cout<<id<<' '<<dis[id]<<' '<<ans1<<endl;
        ll cnt=0,mi=1e9,det_sum=0;
        ll pre_sum=0;
        ll ok_sum=0;//后面可以更新的点数
        for(int i=head[id];i!=-1;i=edge[i].next)
        {
            ll y=edge[i].t;//cout<<id<<" "<<y<<endl;
            if(dis[y]>k) continue;
            cnt++;
            mi=min(mi,dis[y]);
            det_sum+=dis[y];
        }
        for(int i=head[id];i!=-1;i=edge[i].next)
        {

            ll y=edge[i].t;
            if(dis[y]<k) pre_sum++;
            if(vis[y])
            {

                continue;
            }
            if(dis[y]<dis[id]+1) continue;
            // cout<<id<<" k "<<y<<endl;
            ok_sum++;
            dis[y]=dis[id]+1;
            q.push(make_pair(-dis[y],y));
        }
        if(dis[id]<=k&&pre_sum==1&&ok_sum==0)
        {
            // cout<<id<<pre_sum<<endl;
            ans1+=(k-dis[id]);
        }
        if(cnt<2||dis[id]>k) continue;
        // cout<<id<<" "<<cnt<<" "<<det_sum<<' '<<mi<<" "<<dis[id]<<endl;
        ans2+=(cnt-1)*(k-mi)+(cnt-1)*(k-1)-(det_sum-mi);
    }
}
void solve(int cas) {
   memset(head,-1,sizeof head);
   cin>>n>>m>>k;
   for(int i=1;i<=m;++i)
   {
        cin>>a>>b;
        add(a,b);
        add(b,a);
   }
   dij();
   // cout<<ans2<<endl;
   cout<<ans1+ans2/2<<endl;
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
