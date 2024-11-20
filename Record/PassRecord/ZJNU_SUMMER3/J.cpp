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

ll qpow(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)res=res*y;
        y>>=1;
    }
    return res;
}


bool vis[maxn];
int prime[maxn];
int cnt;
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if(!vis[i]) prime[++cnt] = i;
        for (int j = 1;j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

bool check(ll x)
{
    if(x<=1)return 0;
    for(int i=1;i<=cnt&&1ll*prime[i]*prime[i]<=x;++i)
    {
        if(x%prime[i]==0)
        {

            while(x%prime[i]==0&&x>1)x/=prime[i];
            // cout<<" x "<<x<<'\n';
            return (x==1);
        }

    }
    return 1;
}
int a[maxn];
void solve(int cas) {
    //1
    // cout<<"check(5) "<<check(5)<<'\n';
    // check(5);
    int k;cin>>k;
    set<int>s;
    int cnt=0;
    for(int i=1;1ll*i*i<=k;++i)
    {
        if(k%i==0)
        {
            a[++cnt]=i;
            if(i*i!=k)a[++cnt]=k/i;
        }
    }
    for(int i=1;i<=cnt;++i)
    {
        int x=a[i];
        // cout<<" x "<<x<<'\n';
        int cur=x,nw=cur+1;
        ll m;
        // cout<<nw<<'\n';
        if((nw+1)%(k/cur)==0)
        {
            m=(nw+1)/(k/cur);
            // cout<<"m  "<<m<<" nw "<<nw<<'\n';
            if(check(m))s.insert(nw);
        }

        // n+1=i
        cur=x,nw=cur-1;
        // cout<<nw<<'\n';
        if((nw-1)%(k/cur)==0)
        {
            m=(nw-1)/(k/cur);
            // cout<<"m  "<<m<<" nw "<<nw<<'\n';
            if(check(m))s.insert(nw);
        }

        // n=2i-1
        cur=x,nw=2*cur-1;
        // cout<<nw<<'\n';
        if((1ll*nw*nw-1)%(k)==0)
        {
            m=(1ll*nw*nw-1)/(k);
            // cout<<"m  "<<m<<" nw "<<nw<<'\n';
            if(check(m))s.insert(nw);
        }

        // n=2i+1
        cur=x,nw=2*cur+1;
        // cout<<nw<<'\n';
        if((1ll*nw*nw-1)%(k)==0)
        {
            m=(1ll*nw*nw-1)/(k);
            // cout<<"m  "<<m<<" nw "<<nw<<'\n';
            if(check(m))s.insert(nw);
        }
    }
    // for(auto x:s)cout<<x<<' ';
    // cout<<'\n';
    cout<<s.size()<<'\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    isprime(1e5);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
