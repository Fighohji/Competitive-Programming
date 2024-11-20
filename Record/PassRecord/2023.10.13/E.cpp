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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
ll n,k,m,a,b;
ll judge(__int128 l,__int128 r)
{
    l%=m; r%=m;
    if(l<r)
    {
        return l==0;
    }
    return 1;
}
ll gt(__int128 x)
{
    __int128 pro=1;
    ll res=0;
    for(int i=1;i<=100;++i)
    {
        pro=pro*k;
        res+=a;
        if(pro>=m) return res;
        ll fl=judge(x*pro,x*pro+pro-1);
        if(fl) return res;
    }
    return res;
}
void solve()
{
    cin>>n>>k>>m>>a>>b;
    if(k==1)
    {
        if(n%m==0)
        {
            cout<<0<<endl;
            return;
        }
        cout<<-1<<endl;
        return;
    }
    if(n%m==0)
    {
        cout<<0<<endl;
        return;
    }
    ll now=n;
    ll ans=1e18;
    for(int i=0;i<=100;++i)
    {
        if(i>0) now=now/k;
        if(now%m==0)
        {
            ans=min(ans,1ll*i*b);
        }
        ans=min(ans,gt(now)+1ll*i*b);
        if(now==0) break;
    }
    cout<<ans<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
