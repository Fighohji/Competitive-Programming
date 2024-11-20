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
#define eps (1e-10)
#define pb push_back
#define ll int
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
constexpr int maxn = 6010;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
const ll inf=0x3f3f3f3f;
mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
#define endl '\n'

ll n,k;
ll mas[N];
ll mp[N][N];
ll sum[N][N];
ll gt(ll l,ll r)
{
    //l+1->r
    return sum[r][r]-sum[l][r]-sum[r][l]+sum[l][l];
}
ll dp[N][N];
ll d[N][N];
void solve() 
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>mas[i];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            sum[i][j]=mp[i][j]=d[i][j]=0;
            dp[i][j]=inf;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(mas[i]>mas[j]) mp[i][j]=1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=i+1;j<=n;++j)
    //     {
    //         cout<<i+1<<' '<<j<<' '<<gt(i,j)<<endl;
    //     }
    // }
    // cout<<"//////"<<endl;
    // cout<<"d "<<gt(0,n)<<endl;
    dp[0][0]=0;
    for(int j=1;j<=k+1;++j)
    {
        d[n+1][j]=n;
        for(int i=n;i;--i)
        {
            ll tmp=inf;
            ll p;
            for(int k=d[i][j-1];k<=d[i+1][j];++k)
            {
                if(tmp>dp[k][j-1]+gt(k,i))
                {
                    tmp=dp[k][j-1]+gt(k,i);
                    p=k;
                }
            }
            dp[i][j]=tmp;
            d[i][j]=p;
        }
    }
    cout<<dp[n][k+1]<<endl;
}

bool END;
signed main() {
    cout << fixed << setprecision(20);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
