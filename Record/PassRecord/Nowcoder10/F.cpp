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

int a[110];
int dp[2][310][1100];
void solve() {
    int n, t, k, m;
    cin >> n >> t >> k >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for(int i=a[1];i<=t;++i)
    {
        dp[1][i][0]=1;
    }
    for(int i=a[1];i<=t;++i)
    {
        ll det=(1<<(k-1));
        dp[1][i][det]=1;
        for(int j=i+1;j<=t;++j)
        {
            det>>=1;
            if(det) dp[1][j][det]++;
        }
    }
    for(int z=2;z<=n;++z)
    {
        //member
        ll tim=a[z];
        for(int i=tim;i<=t;++i)
        {
            for(int sta=0;sta<(1<<k);++sta)
            {
                ll num=0;
                for(int j=0;j<k;++j) if((sta&(1<<j))) num++;
                if(num>(z-1)) continue;
                if(num>m) continue;
                if(sta&(1<<(k-1))) continue;
                dp[z%2][i][sta|(1<<(k-1))]+=dp[(z-1)%2][i][sta];
                ll tt=sta|(1<<(k-1));
                ll ts=tt;
                for(int j=i+1;j<=t;++j)
                {
                    tt>>=1;
                    dp[z%2][j][tt]+=dp[z%2][i][ts];
                }
            }

        }
    }
    ll ans=0;
    for(int i=a[n];i<=t;++i)
    {
        //time
        for(int sta=0;sta<(1<<k);++sta)
        {
            ll num=0;
            for(int j=0;j<k;++j) if(sta&(1<<j)) num++;
                if(num>m) continue;
            ans+=dp[n%2][i][sta];
        }
    }
    cout<<ans<<endl;
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
