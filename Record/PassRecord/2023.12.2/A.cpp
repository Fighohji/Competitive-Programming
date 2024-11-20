
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

string a,b,c;
ll ans[300];

ll gt(char x)
{
    if(x>='0'&&x<='9') return (ll)(x-'0');
    return (ll)(x-'A')+10;
}

bool judge(ll x)
{
    memset(ans,0,sizeof ans);
    for(int i=0;i<min(a.size(),b.size());++i)
    {
        ll x1=gt(a[i]),x2=gt(b[i]);
        if(x1>=x||x2>=x) return 0;
        ll x3=x1+x2;
        ans[i+1]+=x3/x;
        ans[i]+=x3%x;
    }
    if(a.size()<b.size())
    {
        for(int i=a.size();i<b.size();++i)
        {
            ll xx=gt(b[i]);
            if(xx>=x) return 0;
            ans[i]+=xx;
        }
    }

    if(a.size()>b.size())
    {
        for(int i=b.size();i<a.size();++i)
        {
            ll xx=gt(a[i]);
            if(xx>=x) return 0;
            ans[i]+=xx;
        }
    }
    for(int i=0;i<=260;++i)
    {
        ans[i+1]+=ans[i]/x;
        ans[i]%=x;
    }

    for(int i=0;i<c.size();++i)
    {
        ll xx=gt(c[i]);
        if(xx>=x) return 0;
        if(ans[i]!=xx) return 0;
    }
    return 1;
}

void solve()
{
    cin>>a>>b>>c;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    ll an=0;
    for(int i=1;i<=100;++i)
    {
        if(judge(i))
        {
            if(an)
            {
                cout<<0<<endl;
                return;
            }
            an=i;
        }
    }
    cout<<an<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
