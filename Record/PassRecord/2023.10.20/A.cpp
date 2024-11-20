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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll n,m;
ll sum,a;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll gt(ll a,ll b,ll c)
{
    //求解满足方程组ax+by=c的最小非负数解x(若要正整数解在最后特判x=0即可)
    //无解返回-1
    ll x,y;
    ll Gcd=exgcd(a,b,x,y);
    if(c%Gcd) return -1;
    x=x*(c/Gcd);
    ll mo=b/Gcd;
    x=(x%mo+mo)%mo;
    return x;
    //x为特解，通解为(x+kb',y-ka'),b'=b/(a,b),a'=a/(a,b)
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a;sum+=a;
    }
    sum%=m;

    ll g1=__gcd(n,n*(n+1)/2);
    ll g3=__gcd(g1,m);

    ll num=(m-sum+g3-1)/g3;

    ll x=gt(g1,m,g3*num);
    ll a=gt(n,n*(n+1)/2,x*g1);
    a=(a%m+m)%m;
    ll b=(x*g1-a*n)/(n*(n+1)/2);
    b=(b%m+m)%m;
    cout<<(a*n%m+n*(n+1)/2%m*b%m+sum)%m<<endl;
    cout<<a<<' '<<b<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
