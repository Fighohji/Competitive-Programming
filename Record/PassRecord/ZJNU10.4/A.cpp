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
#define db long double
#define il inline
#define fir first
#define sec second
#define eps (1e-12)
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
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll n,t;
struct mat
{
    ll m[110][110];//结构体存矩阵
};
mat A,e;//输入输出矩阵
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
                c.m[i][j]=c.m[i][j]%mod+x.m[i][k]%mod*y.m[k][j]%mod;
            }
        }
    }
    return c;
}

ll mpow(mat x,ll y,ll mod)
{
    mat ans=e;//一般是一个对角为1的初始矩阵 ，记得初始化
    //x是变换矩阵
    while(y)
    {
        if(y&1) ans=mul(ans,x,2);
        x=mul(x,x,2);
        y>>=1;
    }
    return ans.m[1][1]*(mod-1)%mod;
    //之前得到的是变换矩阵的y次幂，最后将其与初始矩阵相乘即可
}

ll qpow(ll base, ll power, ll p) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}



void solve() {
    ll a, b, n; cin >> a >> b >> n;
    ll x = (-1) % mod, y = 0;
    ll inv = qpow((a * a % mod + b * b % mod) % mod, mod - 2, mod);
    ll Sin = 2 * a * b % mod * inv % mod;
    ll Cos = (a * a % mod - b * b % mod + mod) % mod * inv % mod;
    e.m[1][1]=e.m[2][2]=1;
    A.m[1][1]=Cos,A.m[1][2]=(mod-Sin)%mod,A.m[2][1]=Sin,A.m[2][2]=Cos;
    cout<<mpow(A,n+1,mod)<<'\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
