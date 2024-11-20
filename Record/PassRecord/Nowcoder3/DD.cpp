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


string mp;
int a[2010][2010];
int n;
bool check()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((a[1][1]+a[i][j])%2!=(a[i][1]+a[1][j])%2)return 0;
        }
    }
    return 1;
}
ll calc1(int x)
{
    ll ans=a[x][1];
    for(int i=1;i<=n;++i)if(x!=i)ans+=a[i][1];
    for(int i=1;i<=n;++i)ans+=a[1][i];
    return ans;
}
ll calc2(int x)
{
    ll ans=a[1][x];
    for(int i=1;i<=n;++i)if(x!=i)ans+=a[1][i];
    for(int i=1;i<=n;++i)ans+=a[i][1];
    return ans;
}
void solve(int cas) {
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>mp;
        for(int j=0;j<n;++j)
        {
            a[i][j+1]=mp[j]-'0';
        }
    }
    

    ll ans=1e9;
    if(!check())
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=1;i<=n;++i)ans=min(ans,calc1(i));
    for(int i=1;i<=n;++i)ans=min(ans,calc2(i));

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            a[i][j]^=1;
        }
    }
    for(int i=1;i<=n;++i)ans=min(ans,calc1(i));
    for(int i=1;i<=n;++i)ans=min(ans,calc2(i));

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
