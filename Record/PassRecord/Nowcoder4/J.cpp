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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
ll n,m;
ll dp[5010][10010];
ll f[10010];
ll ff[10010];
ll F(ll x)
{
    ll id=m*2-x;
    if(id==0) return f[2*m];
    else return f[2*m]-f[id-1];
}
void solve(int cas) {
    cin>>n>>m;
    dp[0][m]=1;
    for(int i=0;i<=2*m;++i) dp[1][i]=1;
    for(int i=0;i<=2*m;++i)
    {
        if(i==0) f[i]=dp[0][i];
        else f[i]=f[i-1]+dp[0][i];
    }
    for(int i=0;i<=2*m;++i)
    {
        if(i==0) ff[i]=f[m*2]-f[m*2-1];
        else ff[i]=ff[i-1]+f[min(m+i,m*2)]-f[m-1];
    }
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=2*m;++j)
        {
            dp[i][j]+=ff[j];
        }
        for(int j=0;j<=2*m;++j)
        {
            if(j==0) f[j]=dp[i-1][0];
            else f[j]=f[j-1]+dp[i-1][j];
        }
        for(int j=0;j<=2*m;++j)
        {
            if(j==0) ff[j]=f[m*2]-f[m*2-1];
            else ff[j]=ff[j-1]+f[min(m+j,m*2)]-f[m-1];
        }
    }
    ll ans=0;
    for(int i=0;i<=2*m;++i) ans=ans+dp[n][i];
    cout<<ans<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
