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

struct node {
    int r, g, b;
    bool operator<(const node &t) const {
        return r < t.r && g < t.g && b < t.b;
    }
}mas[N];
struct ty
{
    ll t,l,next;
}edge[N<<1];
ll cn=0;
ll head[N];
void add(ll a,ll b,ll c)
{
    edge[++cn].t=b;
    edge[cn].l=c;
    edge[cn].next=head[a];
    head[a]=cn;
}
bool judge(node a,node b)
{
    return a.b>b.b&&a.g>b.g&&a.r>b.r;
}
ll du[N],dd[N];
ll col[N];
void solve() {
    memset(head,-1,sizeof head);
    int n; cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin>>mas[i].r>>mas[i].g>>mas[i].b;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(judge(mas[i],mas[j]))
            {
                // cout<<i<<' '<<j<<endl;
                add(i,j,1);
                du[j]++;
            }
        }
    }
    for(int i=1;i<=n;++i) dd[i]=du[i],col[i]=255;
    queue<ll> q;
    for(int i=1;i<=n;++i) if(du[i]==0) q.push(i);
    while(!q.empty())
    {
        ll id=q.front();q.pop();
        for(int i=head[id];i!=-1;i=edge[i].next)
        {
            ll y=edge[i].t;
            col[y]=min(col[y],col[id]-1);
            du[y]--;
            if(du[y]==0) q.push(y);
        }
    }
// for(int i=1;i<=n;++i) cout<<col[i]<<' ';
//     cout<<endl;
    ll det=min(col[1],col[2]);
    col[1]=det;col[2]=det;
    for(int i=1;i<=n;++i) du[i]=dd[i];
    for(int i=1;i<=n;++i) if(du[i]==0) q.push(i);
    while(!q.empty())
    {
        ll id=q.front();q.pop();
        for(int i=head[id];i!=-1;i=edge[i].next)
        {
            ll y=edge[i].t;
            col[y]=min(col[y],col[id]-1);
            du[y]--;
            if(du[y]==0) q.push(y);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(col[i]<0)
        {
            cout<<-1<<endl;
            return;
        }
    }
    if(col[1]!=col[2])
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=1;i<=n;++i) cout<<col[i]<<endl;
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
