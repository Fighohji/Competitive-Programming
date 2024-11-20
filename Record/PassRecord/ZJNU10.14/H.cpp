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

struct ty
{
    ll x,y;
    ll r;
    ll id;
}mas[N],pre[N];
ll n;
ll pf(ll x)
{
    return x*x;
}
double dis(ty a,ty b)
{
    return sqrt(pf(a.x-b.x)*1.0+pf(a.y-b.y)*1.0);
}
ll fa[N];
ll find(ll x)
{
    return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
bool cmp1(ty a,ty b)
{
    return a.x-a.r<b.x-b.r;
}
bool cmp2(ty a,ty b)
{
    return a.x+a.r<b.x+b.r;
}
bool cmp3(ty a,ty b)
{
    return a.y-a.r<b.y-b.r;
}
bool cmp4(ty a,ty b)
{
    return a.y+a.r<b.y+b.r;
}
struct Edge
{
    ll x,y;
    double val;
}E[N];
bool cmp(Edge a,Edge b)
{
    return a.val<b.val;
}
ll cnt=0;
void init()
{
    for(int i=1;i<n;++i)
    {
        E[++cnt]={mas[i].id,mas[i+1].id,dis(mas[i],mas[i+1])-mas[i].r-mas[i+1].r};
    }
}
struct Ans
{
    ll a,b,c,d;
};
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>mas[i].x>>mas[i].y>>mas[i].r;
        mas[i].id=i;
        pre[i].x=mas[i].x,pre[i].y=mas[i].y;
    }
    for(int i=1;i<=n;++i) fa[i]=i;
    sort(mas+1,mas+1+n,cmp1);
    init();
    sort(mas+1,mas+1+n,cmp2);
    init();
    sort(mas+1,mas+1+n,cmp3);
    init();
    sort(mas+1,mas+1+n,cmp4);
    init();
    sort(E+1,E+1+cnt,cmp);
    vector<Ans> vt;
    for(int i=1;i<=cnt;++i)
    {
        ll fx=find(E[i].x),fy=find(E[i].y);
        // cout<<E[i].val<<endl;
        if(fx==fy) continue;
        fa[fx]=fy;
        ll x=E[i].x,y=E[i].y;
        vt.push_back({pre[x].x,pre[x].y,pre[y].x,pre[y].y});
    }
    cout<<"YES"<<endl;
    for(auto [a,b,c,d]:vt)
    {
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    }


}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
