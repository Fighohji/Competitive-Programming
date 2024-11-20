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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
int n,m,q;string s;
struct Tree
{
    ll tr[N];
    void add(ll x,ll y)
    {
        while(x<N)
        {
            tr[x]+=y;
            x+=lowbit(x);
        }
    }
    ll sum(ll x)
    {
        ll ans=0;
        while(x)
        {
            ans+=tr[x];
            x-=lowbit(x);
        }
        return ans;
    }
}T;

struct ty
{
    string s;
    ll id;
    string op;
}Q[N];
pair<ll,ll> p[N];
pair<ll,ll> qq[N];
void solve(int cas) 
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;++i)
    {
        p[i]=make_pair(1,0);
        qq[i]=make_pair(1,0);
    }

    for(int i=1;i<=q;++i)
    {
        cin>>Q[i].s>>Q[i].id>>Q[i].op;
        if(Q[i].s=="row")
        {
            if(Q[i].op=="on") p[Q[i].id]=make_pair(i+1,1);
            else p[Q[i].id]=make_pair(i+1,0);
        }
        else if(Q[i].s=="column")
        {
            if(Q[i].op=="on")
            qq[Q[i].id]=make_pair(i+1,1);
            else qq[Q[i].id]=make_pair(i+1,0);
        }
        // if(Q[i].s=="row"&&Q[i].op=="on")
        // {
        //     T.add(i,1);
        // }
    }
    for(int i=1;i<=n;++i)
    {
        T.add(p[i].first,p[i].second);
    }
    ll ans=0;
    ll sum1=T.sum(q+1);
    ll cnt=0;
    for(int i=1;i<=m;++i)
    {
        if(qq[i].first==1) continue;
        cnt++;
        if(qq[i].second==1)
        {
            ans+=qq[i].first+T.sum(q+1)-T.sum(qq[i].first);
            continue;
        }
        else
        {
            ans+=T.sum(q+1)-T.sum(qq[i].first+1);
        }
    }
    cout<<ans+sum1*(m-cnt)<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
