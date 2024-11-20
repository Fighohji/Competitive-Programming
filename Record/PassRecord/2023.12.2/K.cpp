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
constexpr int mod = 1e9 + 7; /*  */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll n,L;
set<ll> st;
ll num[N];
ll ans=0;
vector<ll> vt;
ll dp[100][100];
ll p[100][100];
bool chck(ll sum)
{
    return 1;
    if(sum==0) return 0;
    vector<ll> nw;
    nw.push_back(0);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=num[i];++j) nw.push_back(vt[i]);
    }
    for(int i=0;i<=30;++i)
    {
        for(int j=0;j<=30;++j) dp[i][j]=0;
    }
    dp[0][0]=1;
    for(int i=1;i<=sum;++i)
    {
        for(int j=0;j<=sum;++j)
        {
            if(dp[i-1][j]*nw[i]>L) return 0;
            dp[i][j]+=dp[i-1][j];
            dp[i][j+1]+=dp[i-1][j]*nw[i];
            if(dp[i][j]>L||dp[i][j+1]>L) return 0;
        }
    }
    ll sux=0;
    for(int i=1;i<=sum;++i) sux+=dp[sum][i];
        return sux<=L;
}
void dfs(ll id,ll sum)
{
    if(id==n+1)
    {
        if(chck(sum))
        {
            ans++;
        }
        return;
    }

    for(int i=0;i+sum<=11;++i)
    {
        num[id]=i;
        dfs(id+1,sum+i);
    }
}
ll fs(ll n,ll k)
{
    memset(p, 0, sizeof(p));
    p[0][0] = 1;
    int i;
    for (i = 1; i <= n; ++i) {
      int j;
      for (j = 1; j <= k; ++j) {
        if (i - j >= 0) /*p[i-j][j]所有部分大于1*/
        {
          p[i][j] = (p[i - j][j] + p[i - 1][j - 1]) ;
        }
      }
    }
    return p[n][k];
}
void solve() {
    cin>>n>>L;
    for(int i=1;i<=n;++i)
    {
        ll a;cin>>a;
        st.insert(a);
    }
    vt.push_back(0);
    for(auto s:st) vt.push_back(s);
    n=st.size();
    dfs(1,0);
    cout<<ans<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
