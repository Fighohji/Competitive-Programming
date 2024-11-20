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
bool judge(string s)
{
    ll len=s.size();
    if(len%2==0)
    {
        ll num1=0,num2=0;
        for(int i=0;i<len/2;++i) if(s[i]=='1') num1++;
        for(int i=len/2;i<len;++i) if(s[i]=='1') num2++;
        if(num1==0||num2==0) return 0;
    }
    else
    {
        ll num1=0,num2=0;
        for(int i=0;i<len/2;++i) if(s[i]=='1') num1++;
        for(int i=len/2+1;i<len;++i) if(s[i]=='1') num2++;
        if(s[len/2]=='0')
        {
            if(num1==0||num2==0) return 0;
        }
    }
    return 1;
}
ll sg(string s)
{
    if(vvis[s]) return mp[s];
    for(int i=0;i<=100;++i) vis[i]=0;
    for(int i=0;i<s.size();++i)
    {
        if(s[i]=='0') continue;
        s[i]='0';
        // cout<<"s "<<s<<endl;
        if(!judge(s))
        {
            s[i]='1';
            continue;
        }
        ll g=sg(s);
        s[i]='1';
        vis[g]=1;
    }
    ll ans=0;
    for(int i=0;i<=100;++i)
    {
        if(!vis[i])
        {
            ans=i;
            break;
        }
    }
    vvis[s]=1;
    mp[s]=ans;
    return ans;
}
// bool judge(string s)
// {
//     ll cnt=0;
//     for(int i=0;i<s.size();++i)
//     {
//         if(s[i]=='1') cnt++;
//     }
//     if((s.size()%2)==0)
//     {
//         return cnt%2;
//     }
//     int len=s.size();
//     if(s[len/2]=='0')
//     {
//         return cnt%2;
//     }
//     ll num1=0,num2=0;
//     for(int i=0;i<len/2;++i)
//     {
//         if(s[i]=='1') num1++;
//     }
//     for(int i=len/2+1;i<len;++i)
//     {
//         if(s[i]=='1') num2++;
//     }
//     if(cnt%2) return cnt>1;
//     if(num1==1||num2==1) return 1;
//     return 0;
// }
ll n,m;

void solve()
{
    // cout<<sg("11")<<endl;
    for(int s=0;s<(1<<10);++s)
    {
        string ss="";
        ll k=s;
        while(k)
        {
            ss+=(char)(k%2+'0');
            k/=2;
        }
        if(judge(ss)==0) continue;
        cout<<ss<<' '<<sg(ss)<<endl;
    }
    // cin>>n>>m;
    // ll ans=0;
    // string s;
    // for(int i=1;i<=n;++i)
    // {
    //     cin>>s;
    //     ans^=judge(s);
    //     cout<<" l "<<judge(s)<<endl;
    // }
    // if(ans!=0) cout<<"Alice"<<endl;
    // else cout<<"Bob"<<endl;
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
