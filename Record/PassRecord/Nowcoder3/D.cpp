#include <map>
#include <pthread.h>
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

#define N 2010
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


char mp[N][N];
ll n;
char pre[N][N];
struct ty
{
    ll id;
    ll tp;
    ll val;
}mas[N<<1],ppre[N<<1];
bool cmp(ty a,ty b)
{
    return a.val>b.val;
}
map<pii,ll> ps;
void changeh(ll id,char val)
{
    for(int i=1;i<=n;++i)
    {
        if(pre[id][i]==val)
        {
            // cout<<ps[make_pair(1,id)]<<endl;
            mas[ps[make_pair(1,id)]].val--;
            mas[ps[make_pair(2,i)]].val--;
        }
        else
        {
            mas[ps[make_pair(1,id)]].val++;
            mas[ps[make_pair(2,i)]].val++;
        }
        pre[id][i]^=1;
    }
}
void changel(ll id,char val)
{
    // cout<<id<<endl;
    for(int i=1;i<=n;++i)
    {
        if(pre[i][id]==val)
        {
            mas[ps[make_pair(1,i)]].val--;
            mas[ps[make_pair(2,id)]].val--;
        }
        else
        {
            mas[ps[make_pair(1,i)]].val++;
            mas[ps[make_pair(2,id)]].val++;
        }
        pre[i][id]^=1;
    }
}
bool judge()
{
    for(int i=1;i<=n*2;++i) if(mas[i].val>0) return 0;
        return 1;
}

ll cf(char val)
{
    ll sum=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j) pre[i][j]=mp[i][j];
    }
    for(int i=1;i<=n;++i)
    {
        mas[i].id=i;mas[i].tp=1;mas[i].val=0;
        ps[make_pair(1,i)]=i;
    }
    for(int i=n+1;i<=n*2;++i)
    {
        mas[i].id=i-n;mas[i].tp=2;mas[i].val=0;
        ps[make_pair(2,i-n)]=i;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(pre[i][j]==val)
            {
                mas[ps[make_pair(1,i)]].val++;
                mas[ps[make_pair(2,j)]].val++;
            }
        }
    }
    for(int i=1;i<=n*2;++i) ppre[i]=mas[i];

    for(int s=1;s<=n*2;++s)
    {
        if(judge())
        {
            return sum;
        }
        sum++;
        sort(ppre+1,ppre+1+n*2,cmp);
        // for(int i=1;i<=n*2;++i) cout<<ppre[i].val<<" ";
        //         cout<<endl;
        ll typ=ppre[1].tp;ll id=ppre[1].id;
        // cout<<typ<<" "<<id<<endl;
        if(typ==1)//hang
        {
            changeh(id,val);
        }
        else if(typ==2)
        {
            changel(id,val);
        }
        for(int i=1;i<=n*2;++i) ppre[i]=mas[i];

        // for(int i=1;i<=n*2;++i) cout<<mas[i].val<<" ";
        // cout<<endl;

    }
    return -1;
}


void solve(int cas) {
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j) cin>>mp[i][j];
    }
    ll f1=cf('0');
    ll f2=cf('1');

    ll ans=1e9;
    if(f1!=-1) ans=min(ans,f1);
    if(f2!=-1) ans=min(ans,f2);

    if(ans==1e9) cout<<-1<<endl;
    else cout<<ans<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
