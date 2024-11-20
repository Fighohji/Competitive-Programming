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
struct ty
{
    ll w,v;
}a[N],b[N];
bool cmp1(ty a,ty b)
{
    return a.v+a.w>b.v+b.w;
}
bool cmp2(ty a,ty b)
{
    return a.w>b.w;
}
ll n;
queue<ll> q1,q2;
bool judge(ll x)
{
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();

    for(int i=1;i<=n;++i)
    {
        if(a[i].v>=x) q1.push(a[i].v+a[i].w-x);
    }
    for(int i=1;i<=n;++i)
    {
        if(b[i].v<x) q2.push(b[i].w);
    }
    if(q1.size()<q2.size()) return 0;
    while(!q1.empty())
    {
        if(q2.empty()) return 1;
        if(q1.front()<q2.front()) return 0;
        q1.pop();q2.pop();
    }
    return 1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].v>>a[i].w;
        b[i].v=a[i].v;
        b[i].w=a[i].w;
    }
    sort(a+1,a+1+n,cmp1);
    sort(b+1,b+1+n,cmp2);
    ll l=0,r=2e9;
    while(l<=r)
    {
        ll mid=l+r>>1;
        if(judge(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<l-1<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
