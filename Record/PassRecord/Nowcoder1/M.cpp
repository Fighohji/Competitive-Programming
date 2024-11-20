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

bool BEGIN;


ll exgcd(ll a,ll b, ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;return a;
    }
    int d=exgcd(b,a%b,x,y);
    int z=x;x=y;y=z-y*(a/b);
    return d;
}
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
int A=10,B=3;
void solve(int cas) {
   ll A,B,x;
   cin>>A>>B>>x;
   if(A<B)swap(A,B);
   ll g=gcd(A,B);
   if(x%g!=0)
   {
        cout<<"-1\n";
        return ;
   }
   ll ans=LINF;
   // if (x % A == 0) {
   //  ans = min(ans, x / A * 2);
   // }
   // if (ans % B == 0) {
   //  ans = min(ans, x / B * 2);
   // }
   ll r1,r2;
   exgcd(A,B,r1,r2);

   ll t=x/g;
   ll x1=t*r1;
   ll x2=t*r2;



   x1=(x1%(B/g)+B/g)%(B/g);
   x2=(x-A*x1)/B;
   // cout<<"   "<<x1<<' '<<x2<<'\n';
   if(x2>=0)ans=min(ans,2*x1+2*x2);
   else {
        // ans=min(ans,x1-2*x2);
        ans = min(ans, 2 * x1 - 2 * x2 - 1);
    }

   x1-=B/g;
   x2+=A/g;
   // cout<<"   "<<x1<<' '<<x2<<'\n';
   if(x1<0&&x2>0){
        // ans=min(ans,2*x2-x1);
    ans = min(ans, -2 * x1 + 2 * x2 - 1);
    }

   x2=(x2%(A/g)+A/g)%(A/g);
   x1=(x-B*x2)/A;
   // cout<<"   "<<x1<<' '<<x2<<'\n';
   if(x1>=0)ans=min(ans,2*x1+2*x2);
   else {
        // ans=min(ans,2*x2-x1);
        ans = min(ans, -2 * x1 + 2 * x2 - 1);
    }

   x2-=A/g;
   x1+=B/g;
   // cout<<"   "<<x1<<' '<<x2<<'\n';
   if(x1>0&&x2<0) {
        ans=min(ans,2 * x1 - 2 * x2 - 1);
    }

   cout<<ans<<'\n';

}


bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
