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
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
#define endl '\n'
struct ty
{
    ll t,l,next;
}edge[N<<1];
ll cn=0;
ll val[N];
ll head[N];
void add(ll a,ll b,ll c)
{
    edge[++cn].t=b;
    edge[cn].l=c;
    edge[cn].next=head[a];
    head[a]=cn;
}
map<ll,ll> mp;
ll cnt=0;
ll siz[N];
void dfs(ll id,ll fa)
{
    siz[id]=1;
    ll fl=0;
    for(int i=head[id];i!=-1;i=edge[i].next)
    {
        ll y=edge[i].t;
        if(y==fa) continue;
        fl=1;
        dfs(y,id);
        siz[id]+=siz[y];
        val[id]+=val[y];
    }
    if(fl==0) val[id]=1,cnt++;
    mp[siz[id]]+=val[id];
}
ll n;
void solve() {
   cn=0;
   cnt=0;
   cin>>n;
   mp.clear();
   for(int i=0;i<=n+5;++i) head[i]=-1,val[i]=0;
    for(int i=1;i<n;++i)
    {
        ll a,b;
        cin>>a>>b;
        add(a,b,1);add(b,a,1);
    }
    dfs(1,0);
    vector<ll> vt;
    for(int i=1;i<=n;++i)
    {
        if(mp[i]==cnt) vt.push_back(i);
    }
    cout<<vt.size()<<endl;
    for(auto i:vt) cout<<i<<' ';
        cout<<endl;
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
