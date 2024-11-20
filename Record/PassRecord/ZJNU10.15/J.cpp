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
ll a[N],b[N];
bool ck()
{
    if(a[1]>b[1]) return 0;
    for(int i=2;i<=n;++i)
    {
        if(a[i]-a[i-1]!=(b[i]-b[i-1])) return 0;
    }
    return 1;
}
bool judge()
{
    ll fl=0;
    for(int i=1;i<=n;++i) if(a[i]) fl=1;
    return fl;
}
void solve()
{
    int n, k; cin >> n >> k;
    vector<ll> w(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> w[i];
        w[i] += w[i - 1];
    }
    vector dp(k + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; ++i) dp[0][i] = i;
    for(int i = 1; i <= k; ++i)
    {
        ll s; cin >> s;
        int pl = 1, pr = 1;
        for(int j = 1; j <= n; ++j)
        {
            while(pl < j && w[j - 1] - w[pl - 1] > s) pl++;
            // while(pl > 1 && w[j - 1] - w[pl - 2] <= s) pl--;
            while(pr < n && w[pr + 1] - w[dp[i - 1][j]] <= s) pr++;
            dp[i][j] = max({dp[i - 1][j], pr, dp[i][j]});
            dp[i][pl] = max({dp[i - 1][pl], dp[i - 1][j], dp[i][pl]});
            // cout << j << ' ' << pl << ' ' << pr << '\n';
        }
        // for(int j = 1; j <= n; ++j)
        // {
        //     cout << dp[i][j] << ' ';
        // }
        // cout << '\n';
    }
    cout << (dp[k][1] == n ? "Yes\n" : "No\n");
}
/*
5
1 2 3 4 5
6 6 6 6 7
*/

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
