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
#define endl '\n'
ll l,r;
ll cal(ll x)
{
    ll cnt=0;
    while(x)
    {
        cnt++;
        x/=3;
    }
    return cnt;
}
ll a[50],b[50];
ll ma=0;
ll dp[50][1000];
void dfs(ll x,ll sum,ll up,ll down)
{
    // cout<<x<<" "<<sum<<' '<<up<<' '<<down<<endl;
    if(x==0)
    {
        ma=max(ma,sum);
        return;
    }
    if(!up&&!down&&dp[x][sum]!=-1)
    {
        // ma=max(ma,dp[x][sum]);
        return;
    }
    ll up_lim=up?a[x]:2;
    ll down_lim=down?b[x]:0;

    for(int i=down_lim;i<=up_lim;++i)
    {
        dfs(x-1,sum+i,up*(i<up_lim?0:1),down*(i>down_lim?0:1));
    }
    if(!up&&!down) dp[x][sum]=1;

}
ll gt(ll x,ll y,ll num)
{
    ma=0;
    for(int i=0;i<=49;++i)
    {
        for(int j=0;j<=150;++j) dp[i][j]=-1;
    }
    ll cnt=0;
    while(y)
    {
        a[++cnt]=y%3;
        y/=3;
    }
    cnt=0;
    while(x)
    {
        b[++cnt]=x%3;
        x/=3;
    }
    dfs(cnt,0,1,1);
    return ma+num;
}
void solve()
{
   cin>>l>>r;
   ll p1=cal(l),p2=cal(r);
   if(p1==p2)
   {
        cout<<gt(l,r,p1)<<endl;
        return;
   }
   else
   {
        ll maa=0;
        for(int i=p1+1;i<=p2-1;++i) maa=max(maa,1ll*(i+2*i));
        ll k=1;
        for(int i=1;i<=p1;++i) k*=3ll;
        maa=max(maa,gt(l,k-1,p1));
        k=1;
        for(int i=1;i<p2;++i) k*=3ll;
        maa=max(maa,gt(k,r,p2));
        cout<<maa<<endl;
        return;
   }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
