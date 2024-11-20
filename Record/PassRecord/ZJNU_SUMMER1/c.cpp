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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
const ll N=1e6+10;
struct ty
{
    ll t,l,next;
}edge[N<<1];
ll head[N];
ll cn=0;
void add(ll a,ll b)
{
    edge[++cn].t=b;
    edge[cn].next=head[a];
    head[a]=cn;
}
ll dp[N][2];
ll d[N];
ll n;
void dfs(ll id,ll fa)
{
    ll sum1=0,sum2=0;
    ll f1=0,f2=0,sum3=0;
    dp[id][0]=dp[id][1]=0;
    if(d[id]==1&&id!=1)
    {
        dp[id][0]=0;
        dp[id][1]=INF;
        return ;
    }
    for(int i=head[id];i;i=edge[i].next)
    {
        ll y=edge[i].t;
        if(y==fa) continue;
        dfs(y,id);
        dp[id][0]+=dp[y][1];
        dp[id][1]+=dp[y][0];
        sum3+=min(dp[y][0],dp[y][1]);
        if(dp[y][0]<dp[y][1])f2++;
        else if(dp[y][0]>dp[y][1])f1++;
    }
    dp[id][0]=min(dp[id][0],sum3+f2);
    dp[id][1]=min(dp[id][1],sum3+f1);
    // cout<<id<<' '<<dp[id][0]<<' '<<dp[id][1]<<'\n';
}
void solve(int cas) {
    cin>>n;
    for(int i=1;i<n;++i)
    {
        ll a,b,c;
        cin>>a>>b;
        add(a,b);
        add(b,a);
        d[a]++,d[b]++;
    }
    dfs(1,0);
    // cout<<dp[1][0]<<" "<<dp[1][1]<<endl;
    if(d[1]==1)cout<<min(dp[1][0],dp[1][1]+1);
    else cout<<min(dp[1][0],dp[1][1]);
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
