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
    ll t,l,next;
}edge[N<<1];
ll cn=0;
ll head[N];
void add(ll a,ll b)
{
    edge[++cn].t=b;
    edge[cn].next=head[a];
    head[a]=cn;
}
ll n;
ll dep[N];
ll dfs(ll id,ll fa)
{
    ll ma=0;
    for(int i=head[id];i!=-1;i=edge[i].next)
    {
        ll y=edge[i].t;
        if(y==fa) continue;
        ma=max(ma,dfs(y,id));
    }
    return ma+1;
}
void solve()
{
    memset(head,-1,sizeof head);
    cin>>n;
    for(int i=1;i<n;++i)
    {
        ll a,b;cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    ll ans=0;
    for(int i=head[1];i!=-1;i=edge[i].next)
    {
        ll y=edge[i].t;
        ans+=dfs(y,1);
    }
    cout<<ans<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
