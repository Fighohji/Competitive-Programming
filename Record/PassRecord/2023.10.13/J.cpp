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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
ll n,m,q,v;
struct ty
{
    int a,b,vis;
    ll val;
}E[N];
int fa[61][N];
ll find(ll x,ll idx)
{
    return fa[idx][x]==x?fa[idx][x]:fa[idx][x]=find(fa[idx][x],idx);
}
void Solve(ll idx)
{
    for(int i=1;i<=n;++i) fa[idx][i]=i;
    for(int i=1;i<=m;++i)
    {
        if(E[i].vis==0) continue;
        ll val=E[i].val;
        if((v>>idx)&1)
        {
            if(((val>>idx)&1)==0)
            {
                E[i].vis=0;
                continue;
            }
        }
        if((val>>idx)&1)
        {
            ll fx=find(E[i].a,idx),fy=find(E[i].b,idx);
            fa[idx][fx]=fy;
        }

    }
}
bool judge(ll x,ll y)
{
    ll Fl=0;
    for(int i=60;i>=0;--i)
    {
        ll fl=0;//是否连通
        ll fx=find(x,i),fy=find(y,i);
        if(fx==fy) fl=1,Fl=1;
        if(fl==1)
        {
            if(((v>>i)&1)==0) return 1;
        }
        else
        {
            if((v>>i)&1) return 0;
        }
    }
    return Fl;
}
void solve()
{
    cin>>n>>m>>q>>v;
    for(int i=1;i<=m;++i)
    {
        cin>>E[i].a>>E[i].b>>E[i].val;
        E[i].vis=1;
    }
    for(int i=60;i>=0;--i)
    {
        Solve(i);
    }
    ll a,b;
    while(q--)
    {
        cin>>a>>b;
        cout<<(judge(a,b)?"Yes":"No")<<endl;
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
