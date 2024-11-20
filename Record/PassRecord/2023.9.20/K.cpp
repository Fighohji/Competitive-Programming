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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


ll cost[N];//长度为i的区间需要的箱子数
ll nd[N];//长度为i的区间最少要做几次
ll n,m;
void init()
{
    cost[1]=0;
    for(int i=2;i<=5000;++i)
    {
        cost[i]=cost[i/2]+1;
    }
    nd[1]=0;
    for(int i=2;i<=5000;++i)
    {
        nd[i]=(int)ceil(log(i)/log(2));
    }
}
void solve()
{
    init();
    cin>>n>>m;
    if(m==1)
    {
        cout<<n<<' '<<1<<endl;
        return;
    }
    ll len=n+1;
    if(cost[len]<=m)
    {
        ll l=0,r=0;
        for(int i=1;i<=n;++i)
        {
            ll c1=cost[i]+1;
            ll c2=cost[n-i+1];
            ll t1=nd[i]+1;
            ll t2=nd[n-i+1]+1;
            if(max(c1,c2)>m) continue;
            if(max(t1,t2)>nd[len]) continue;
            r=i;
            if(l==0) l=i;
        }
        if(l<r) cout<<nd[len]<<' '<<l<<'-'<<r<<endl;
        else cout<<nd[len]<<' '<<l<<endl;
        return;
    }
    int ma=0;
    // for(int i=1;i<=10;++i) cout<<cost[i]<<' ';
    //     cout<<endl;
    for(int i=1;i<=5000;++i)
    {
        //枚举合法区间长度
        if(cost[i]+1<=m)
        {
            ma=max(ma,i);
        }
    }
    ll det=n/ma;
    if(n%ma) cout<<det+nd[ma]<<' '<<ma<<endl;
    else cout<<det+nd[n-(det-1)*ma+1]-1<<' '<<ma<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
