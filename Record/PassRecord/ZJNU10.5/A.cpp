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


ll dp[10][810][810];
ll ans[50][50];
// ll ans[30][8] = {11664 ,15816 ,20736 ,0 ,1444 ,3218 ,5776 ,9008 ,12996 ,17666 ,23104 ,0 ,1600 ,3584 ,6400 ,9984 ,14400 ,19584 ,25600 ,0 ,1764 ,3912 ,7056 ,10942 ,15876 ,21500 ,28224 ,0 ,1936 ,4344 ,7744 ,12080 ,17424 ,23688 ,30976 ,0 ,2116 ,4712 ,8464 ,13144 ,19044 ,25808 ,33856 ,0 ,2304 ,5138 ,9216 ,14326 ,20736 ,28122 ,36864 ,0 ,2500 ,5612 ,10000 ,15624 ,22500 ,30624 ,40000 ,0 ,2704 ,6062 ,10816 ,16896 ,24336 ,33120 ,43264 ,0 ,2916 ,6536 ,11664 ,18184 ,26244 ,35664 ,46656 ,0 ,3136 ,6984 ,12544 ,19488 ,28224 ,38266 ,50176 ,0 ,3364 ,7520 ,13456 ,20968 ,30276 ,41200 ,4294967295 ,0 ,3600 ,8084 ,14400 ,22480 ,32400 ,44076 ,57600};
void solve() {


    // cin >> n >> r;
    // n--, r--;
    // cout << ans[r][n] << '\n';
    for(int r = 1; r <= 30; ++r)
    {
            for(int u = 0; u <= 8; u++)
            for(int p = 0; p <= 800; ++p)
                for(int k = 0; k <= 800; ++k)
                    dp[u][p][k] = -1e9;
            // memset(dp, -0x3f, sizeof(dp));
            dp[0][400][400] = 0;
        for(int i = 1; i <= 8; ++i)
        {

            for(int x = -r; x <= r; ++x)
            {
                for(int y = -r; y <= r; ++y)
                {
                    if(y * y + x * x <= r * r)
                    {
                        for(int p = -(i) * r; p <= (i) * r; ++p)
                        {
                            for(int k = -(i) * r; k <= (i) * r; ++k)
                            {
                                dp[i][p + x + 400][k + y + 400] = max(dp[i][p + x + 400][k + y + 400], dp[i - 1][p + 400][k + 400] + x * x + y * y);
                            }
                        }
                    }
                }
            }
            // ans[i][r]
            for(int p = 0; p <= 800; ++p)
            {
                for(int j = 0; j <= 800; ++j)
                {
                    ans[i][r] = max(ans[i][r], i * dp[i][p][j] - (p - 400) * (p - 400) - (j - 400) * (j - 400));
                }
            }
            cout << ans[i][r] << " ,";
        }

    }
    // int q; cin >> q;
    // while(q--)
    // {
    //     int n, r; cin >> n >> r;
    //     cout << dp[n][r] << '\n';
    // }
    // ll res = 0;
    // for(int i = 0; i <= 600; ++i)
    // {
    //     for(int j = 0; j <= 600; ++j)
    //     {
    //         res = max(res, n * dp[n][i][j] - (i - 300) * (i - 300) - (j - 300) * (j - 300));
    //     }
    // }
    // cout << res << '\n';
}


signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
