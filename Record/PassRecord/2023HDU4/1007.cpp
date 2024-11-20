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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


//·ÀÒç³öÈ¡Ä£³Ë·¨
inline ll ksc(ull x,ull y ,ll p){return (x*y-(ull)((long double)x/p*y)*p+p)%p;}
inline ll ksm(ll x,ll y,ll p){ll res=1;for(;y;y>>=1,x=ksc(x,x,p))if(y&1)res=ksc(res,x,p);return res;}
inline bool mr(ll x,ll p)
{
    if(ksm(x,p-1,p)!=1)return 0;
    ll y=p-1,z;
    while(!(y&1))
    {
        y>>=1;z=ksm(x,y,p);
        if(z!=1&&z!=p-1)return 0;
        if(z==p-1)return 1;
    }
    return 1;
}
//ÉúÈÕ¹¥»÷ µÚÒ»¸öÖØ¸´µÄÊýÇ°ÃæÆÚÍû´óÔ¼ÓÐsqrt(PI*N/2)¸ö
ll te_per[20]={0,2,3,5,7,433,61,24251};//{0,2,325,9375,28178,450775,9780504,1795265022};
int te_num=7;
inline bool isprime(ll x)
{
    if(x<3)return x==2;
    if(x&1==0)return 0;
    ll d=x-1,r=0;
    for(int i=1;i<=te_num;++i)if(x==te_per[i])return 1;
    for(int i=1;i<=te_num;++i)
        if(!(x%te_per[i])||!mr(te_per[i],x))return 0;
    return 1;
}
//¿ìËÙÉ¸ÖÊÒòÊý prho,½á¹û´æÔÚysÀïÃæ
ll ys[N];
int ind;//Ê¹ÓÃÇ°Çå¿Õ
inline ll rho(ll p)
{
    ll x,y,z,c,g;
    int i,j;
    while(1)
    {
        y=x=rand()%p;//Ê¹ÓÃÇ°¼ÇµÃsrand(time(0))
        z=1,c=rand()%p;
        i=0,j=1;
        while(++i)
        {
            x=(ksc(x,x,p)+c)%p;
            z=ksc(z,abs(y-x),p);
            if(x==y||!z)break;
            if(!(i%127)||i==j)
            {
                g=__gcd(z,p);
                if(g>1)return g;
                if(i==j)y=x,j<<=1;
            }
        }

    }
}
inline void prho(ll p)
{
    if(p==1)return ;
    if(isprime(p)){ys[++ind]=p;return ;}
    ll pi=rho(p);
    while(p%pi==0)p/=pi;
    prho(pi);
    prho(p);
}
void solve(int cas)
{
    ll n;
    cin>>n;
    if (n == 1) {
        cout << 1 << ' ';
        return ;
    }
    ind=0;
    prho(n);
    sort(ys + 1, ys + 1 + ind);
    int len = unique(ys + 1, ys + 1 + ind) - ys - 1;
    // for (int i = 1; i <= ind; ++i) {
    //     cout << ys[i] << ' ';
    // }
    if(len>1)cout<<1<<' ';
    else cout<<ys[1]%998244353<<' ';
}

//38579489651
bool END;
signed main() {
    srand(time(0));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // cout << (ll)131 * 131 * 131 * 131 * 131 << '\n';
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
