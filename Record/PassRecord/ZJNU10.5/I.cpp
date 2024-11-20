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
constexpr int maxn = 5010;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 998244353;  1e9 + 7
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
ll n,mod=998244353;
ll ksm(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}
ll inv(ll x)
{
    return ksm(x,mod-2);
}
ll p[N],pp[N];
ll c[N][N];
ll power[N];
void init(ll n)
{
    for(int i=1;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    power[1]=1;
    for(int i=2;i<=n;++i) power[i]=ksm(i,i-2);
}
ll C(ll n,ll m)
{
    return c[n][m];
}
ll num[N],val[N],dp[N];
ll pro[N][N];
void rinit(int n)
{
    for(ll i=1;i<=n;++i)
    {
        pro[i][0]=1;
        for(int j=1;j<=n;++j)
        {
            pro[i][j]=pro[i][j-1]*i%mod;
        }
    }
    num[0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            num[i]=(num[i]+C(i-1,j-1)*num[i-j]%mod*power[j]%mod)%mod;
        }
    }
    // for(int i=1;i<=3;++i) cout<<num[i]<<' ';
        // cout<<endl;
    val[1]=0,val[2]=2%mod;
    for(ll i=3;i<=n;++i)
    {

        for(ll j=1;j<i;++j)
        {

            val[i]=(val[i]+j*j%mod*pro[i-1][i-1-j]%mod*C(i-2,j-1)%mod*i%mod)%mod;
        }
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            dp[i]=(dp[i]+(C(i-1,j-1)*num[i-j]%mod*val[j]%mod+C(i-1,j-1)*dp[i-j]%mod*power[j]%mod)%mod)%mod;
        }
    }
}
void solve()
{
    cin>>n;
    cout<<dp[n]<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T>>mod; init(5000);rinit(5000);while (T--)
    solve();
    return 0;
}
