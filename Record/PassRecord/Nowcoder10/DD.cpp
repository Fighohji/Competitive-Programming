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
map<string,ll> mp;
map<string,ll> vvis;
ll vis[N];
ll n,m;
int judge(string s)
{
    ll cnt=0;
    if(m%2==0)
    {
        for(int i=1;i<=m;++i)
        {
            if(s[i]=='1')cnt++;
        }
        return cnt%2;
    }
    else
    {
        if(s[(m+1)/2]=='1')
        {
            int cntl=0,cntr=0;
            for(int i=1;i<(m+1)/2;++i)
            {
                if(s[i]=='1')cntl++;
            }

            for(int i=(m+1)/2+1;i<=m;++i)
            {
                if(s[i]=='1')cntr++;
            }
            if(cntl>cntr)swap(cntl,cntr);
            if(cntl==0||cntr==0)
            {
                return (cntl+cntr)%2;
            }
            if(cntl==1&&cntr==1)
            {
                return 0;
            }
            if(cntl==1&&cntr==2)
            {
                return 0;
            }
            if(cntl==1&&cntr%2==0)
            {
                return 1;
            }
            if(cntl==1&&cntr%2)
            {
                return 2;
            }
            if(cntl%2==0&&cntr%2==0)
            {
                if(cntl==2)
                {
                    if(cntr==2)return 1;
                    return 2;
                }
                return 1;
            }
            if(cntl%2==0)swap(cntl,cntr);
            if(cntr%2==0)
            {
                return 0;
            }
            return 1;

        }
        else
        {
            for(int i=1;i<=m;++i)
            {
                if(s[i]=='1')cnt++;
            }
            return cnt%2;
        }
    }

}


void solve()
{
    cin>>n>>m;
    ll ans=0;
    string s;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        s='~'+s;
        ll res=judge(s);
        ans^=res;
        // cout<<" l "<<res<<endl;
    }
    if(ans!=0) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
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
