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
#define endl '\n'
map<ll,ll> mp;
ll a,b,c,d,v,t;
ll ans=0;
/*
2
8 2 5 1 2 18
10 2 5 1 2 10
*/
void solve()
{
    mp.clear();
    cin>>a>>b>>c>>d>>v>>t;
    ll Lcm=a*c/__gcd(a,c);

    if(Lcm>t)
    {
        for(ll i=0;i<=t;i+=a) mp[i]+=b;
        for(ll i=0;i<=t;i+=c) mp[i]+=d;

        ll pre=-1e18;
        ans=0;
        for(auto i:mp)
        {
            ll tim=i.first,val=i.second;
            if(pre+v<tim) val--;
            ans+=val;
            pre=tim;
        }
        cout<<ans<<endl;
        return;
    }

    for(ll i=0;i<Lcm;i+=a) mp[i]+=b;
    for(ll i=0;i<Lcm;i+=c) mp[i]+=d;

    ans=0;
    ll pre=-1e18;
    ll ma=0;//最后的时间
    for(auto i:mp)
    {
        ll tim=i.first,val=i.second;
        if(pre+v<tim) val--;
        ans+=val;
        pre=tim;
        ma=max(ma,tim);
    }
    //ans 一个循环节的结果
    ll det=0;//额外的共享
    if(ma+v>=Lcm) det=1;
    ll sum=t/Lcm*ans+max(0ll,t/Lcm-1)*det;
    t%=Lcm;
    pre=-1e18;
    for(auto i:mp)
    {
        ll tim=i.first,val=i.second;
        if(tim>t) break;
        if(pre+v<tim) val--;
        sum+=val;
        pre=tim;
        ma=max(ma,tim);
    }
    cout<<sum+det<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
