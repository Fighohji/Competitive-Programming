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
constexpr int maxn = 110;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+9; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
ll n,m,k,d;
ll mas[30];
ll vis[30];//每一座城市是否被禁止访问
ll mp[N][N];
struct mat
{
    ll m[110][110];//结构体存矩阵
};
mat a,e;//输入输出矩阵
mat mul(mat x,mat y,ll n) //矩阵乘法，n代表矩阵的规模
{
    mat c;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            c.m[i][j]=0;//初始化
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                c.m[i][j]=(c.m[i][j]%mod+x.m[i][k]%mod*y.m[k][j]%mod)%mod;
            }
        }
    }
    return c;
}

mat qpow(mat x,ll y,ll mod,ll num)
{
    mat ans=e;//一般是一个对角为1的初始矩阵 ，记得初始化
    //x是变换矩阵
    while(y)
    {
        if(y&1) ans=mul(ans,x,num);
        x=mul(x,x,num);
        y>>=1;
    }
    return ans;
    //之前得到的是变换矩阵的y次幂，最后将其与初始矩阵相乘即可
}
ll Solve()
{
    for(int i=1;i<=n;++i) e.m[i][i]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(vis[i]||vis[j]) a.m[i][j]=0;
            else a.m[i][j]=mp[i][j];
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j)
    //     {
    //         cout<<a.m[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    mat x=qpow(a,d-1,mod,n);
    ll sum=0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        for(int j=1;j<=n;++j)
        {
            if(vis[j]) continue;
            sum=(sum+x.m[i][j])%mod;
        }
    }
    return sum;
}
void solve()
{
    cin>>n>>m>>k>>d;
    for(int i=1;i<=k;++i) cin>>mas[i];
    for(int i=1;i<=m;++i)
    {
        ll a,b;cin>>a>>b;
        mp[a][b]=mp[b][a]=1;
    }
    ll ans=0,cnt=0,det;
    for(int s=0;s<(1<<k);++s)
    {
        for(int i=1;i<=n;++i) vis[i]=0;
        cnt=0;
        for(int i=1;i<=k;++i) if((s>>(i-1))&1) vis[mas[i]]=1,cnt++;
        det=Solve();
        // cout<<s<<' '<<det<<endl;
        if(cnt%2==0) ans=(ans+det)%mod;
        else ans=((ans-det)%mod+mod)%mod;
    }
    cout<<ans<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
