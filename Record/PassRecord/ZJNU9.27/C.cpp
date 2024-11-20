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
// constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
ll mod;
mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

string x,b;

bool cmp(const string &a, const string &b)
{
    //a<=b;
    if(a.size()<b.size()) return 1;
    if(a.size()>b.size()) return 0;
    for(int i=0;i<a.size();++i)
    {
        if(a[i]<b[i]) return 1;
        if(a[i]>b[i]) return 0;
    }
    return 1;
}
map<string,ll> dp[N];
void solve()
{
    cin>>x>>b;
    if(x[0]=='0')
    {
        cout<<0<<endl;
        return;
    }
    string now;
    // string sw="";
    // sw+=x[0];
    // dp[0][sw]=0;
    for(int i=0;i<x.size();++i)
    {
        // if(x[i]=='0') continue;
        string ss="";
        now="";
        ll det_cnt=0;
        for(int j=i;j>=max(0,i-20);--j)
        {
            if(x[j]=='0')
            {
                det_cnt++;
                continue;
            }
            string det="";
            det+=x[j];
            for(int k=1;k<=det_cnt;++k) det+='0';
            det_cnt=0;
            ss=det+now;
            if(cmp(ss,b)==0) break;
            ll ma=1e9;
            if(j==0)
            {
                dp[i][ss]=0;
                now=ss;
                continue;
            }
            for(auto xx : dp[j-1])
            {
                if(cmp(xx.first,ss))
                {
                    ma=min(ma,xx.second);
                }
            }
            dp[i][ss]=ma+1;
            now=ss;
        }
    }
    // for(int i=0;i<x.size();++i)
    // {
    //     cout<<i<<endl;
    //     for(auto [a,b]:dp[i])
    //     {
    //         cout<<a<<' '<<b<<endl;
    //     }
    // }
    ll ans=1e9;
    for(auto xx:dp[x.size()-1])
    {
        if(cmp(xx.first,b))
        {
            ans=min(ans,xx.second);
        }
    }
    if(ans>=1e9) cout<<"NO WAY"<<endl;
    else cout<<ans<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
