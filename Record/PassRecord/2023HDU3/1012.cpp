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
struct ty
{
    ll x,y,op,vis,id,ans;
}mas[N];
vector<ty> vt[N];
ll vis[N];
ll n,q;
struct tee
{
    ll t,next;
}edge[N<<1];
ll cn=0;
ll head[N];
set<ll> st;
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = ex_gcd(b, a%b, x, y);
    int tmp = x; x = y; y = tmp - a / b * y;
    return g;
}
void gt(ll a,ll b,ll tar,ll &x,ll &y)
{
    ll Gcd=ex_gcd(a,b,x,y);
    x=x*(tar/Gcd);
    ll mo=b/Gcd;
    x=(x%mo+mo)%mo;
    if(x==0) x+=mo;
    y=(tar-a*x)/b;
    // cout<<a<<" "<<b<<" "<<x<<" "<<y<<" "<<tar<<endl;
}
void up(ll &a,ll &b,ll &c,ll &d)
{
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    // if(a==0||b==0||c==0||d==0) return;
    ll cnt=0;
    if(a==0) cnt++;if(b==0) cnt++;if(c==0) cnt++;if(d==0) cnt++;
    if(cnt>=2)
    {
        // cout<<cnt<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        return;
    }
    if(a>=c&&b>=d)
    {
        ll det=min((c==0?1e18:a/c),(d==0?1e18:b/d));
        a=a-c*det;b=b-d*det;
        up(a,b,c,d);
        return;
    }
    else if(a<=c&&b<=d)
    {
        ll det=min((a==0?1e18:c/a),(b==0?1e18:d/b));
        c=c-a*det;d=d-b*det;
        up(a,b,c,d);
        return;
    }
    a=0,b=0,c=0,d=0;
    return;
}
bool judge(ty a,ty b)
{
    ll x1,y1,x2,y2;
    cout<<a.x<<" "<<a.y<<" "<<b.x<<' '<<b.y<<endl;
    if(b.x%__gcd(a.x,a.y)) return 0;
    if(b.y%__gcd(a.x,a.y)) return 0;
    gt(a.x,a.y,b.x,x1,y1);
    gt(a.x,a.y,b.y,x2,y2);
    ////
    if(y1<0||y2<0) return 0;
    if(x1==x2&&y1==y2) return 0;
    if(!((x1>=x2&&y1>=y2)||(x1<=x2&&y1<=y2))) return 0;
    // cout<<x1<<" "<<y1<<" "<<x2<<' '<<y2<<' ';
    up(x1,y1,x2,y2);
    // cout<<x1<<' '<<y1<<" "<<x2<<' '<<y2<<endl;
    if(!(x1==1&&y1==0&&x2==0&&y2==1)) return 0;
    // if(__gcd(x1,x2)!=1||__gcd(y1,y2)!=1) return 0;
    return 1;
}
void add(ll a,ll b)
{
    edge[++cn].t=b;
    edge[cn].next=head[a];
    head[a]=cn;
}
void dfs(ll id,ll idx,ll flag)
{
    vt[id][idx].vis=flag;
    //gcd=id
    for(int i=idx+1;i<vt[id].size();++i)
    {
        if(vt[id][i].x==vt[id][idx].x&&vt[id][i].y==vt[id][idx].y)
        {
            add(vt[id][idx].id,vt[id][i].id);
            cout<<vt[id][idx].x<<" "<<vt[id][idx].y<<" "<<vt[id][i].x<<" "<<vt[id][i].y<<endl;
            dfs(id,i,flag);
            continue;
        }
        // cout<<vt[id][idx].x<<" "<<vt[id][idx].y<<" "<<vt[id][i].x<<" "<<vt[id][i].y<<endl;
        if(vt[id][i].y<vt[id][idx].y) continue;
        if(vt[id][i].vis==flag) continue;
        if(!judge(vt[id][idx],vt[id][i])) continue;
        add(vt[id][idx].id,vt[id][i].id);
        cout<<vt[id][idx].x<<" "<<vt[id][idx].y<<" "<<vt[id][i].x<<" "<<vt[id][i].y<<endl;
        dfs(id,i,flag);
    }
}
void tr_dfs(ll id)
{
    if(mas[id].vis) return;
    mas[id].vis=1;
    for(int i=head[id];i!=-1;i=edge[i].next)
    {
        ll y=edge[i].t;
        tr_dfs(y);
        mas[id].ans+=mas[y].ans+1;
    }
}
bool cmp(ty a,ty b)
{
    return a.x<=b.x;
}
void solve(int cas) {
    memset(head,-1,sizeof head);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    {
        cin>>mas[i].x>>mas[i].y;
        mas[i].id=i;
    }
    for(int i=n+1;i<=n+q;++i)
    {
        cin>>mas[i].x>>mas[i].y;
        mas[i].id=i;
    }
    for(int i=1;i<=n+q;++i)
    {
        ll Gcd=__gcd(mas[i].x,mas[i].y);
        vt[Gcd].push_back(mas[i]);
        st.insert(Gcd);
    }

    // ll a=1,b=0,c=1,d=1;
    // up(a,b,c,d);
    // cout<<a<<" "<<b<<' '<<c<<" "<<d<<endl;

    ////
    for(auto i:st)
    {
        if(vt[i].size()==0) continue;
        sort(vt[i].begin(),vt[i].end(),cmp);
        //
        // cout<<i<<"d fd"<<endl;
        for(int a=0;a<vt[i].size();++a)
        {
            // cout<<vt[i][a].x<<' '<<vt[i][a].y<<endl;
            dfs(i,a,i);
        }
    }

    // ////
    for(int i=1;i<=n+q;++i)
    {
        if(mas[i].vis) continue;
        tr_dfs(i);
    }
    for(int i=n+1;i<=n+q;++i) cout<<mas[i].ans<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
