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
constexpr int maxn = (1<<24);
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll n;
ll mas[N];
ll sum[N],b[N];
ll dp[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>mas[i];
    for(int i=0;i<n;++i) b[i]=mas[i+1]-mas[i];
    // for(int i=0;i<n;++i) cout<<b[i]<<' ';
    //     cout<<endl;
    for(int s=1;s<(1<<n);++s)
    {
        for(int j=0;j<n;++j)
        {
            if((s>>j)&1)
            {
                sum[s]=sum[s^(1<<j)]+b[j];
                break;
            }
        }
    }
    dp[0] = 0;
    for(int sta = 1; sta < (1 << n); ++sta)
    {
        dp[sta] = INF;
        int p = 0;
        for(int i = 0; i < n; ++i)
        {
            if((sta >> i) & 1)
            {
                p++;
                dp[sta] = min(dp[sta], dp[sta ^ (1 << i)] + (sum[sta] != 0));
            }
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
