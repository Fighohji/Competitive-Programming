#include <cstdlib>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

db dp[105][105];

void solve() {
    int n, m; cin >> n >> m;
    vector<db> p(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i] = p[i] / 180 * pi;
        p[i + n] = p[i] + 2 * pi;
    }
    // sort(all(p));
    db ans = 0;
    // cout << sqrt(3) / 2 << '\n';
    for (int s = 0; s < 1; ++s) {
        for(int i = 0; i <= 2 * n; ++i)
        {
            for(int j = 0; j <= m; ++j)
                dp[i][j] = -1e9;
        }
        dp[s][0] = 0;
        // memset(dp, 0, sizeof dp);
        for (int i = 1 ; i <= n; ++i) { //第几个
            for (int j = 1; j <= m; ++j) { //选几个
                for (int k = 0; k < i; ++k) { //从哪个位置转移
                    int x = s + i;
                    int y = s + k;
                    dp[x][j] = max(dp[x][j], dp[y][j - 1] + (sin(p[y] - p[x])) * 1000000);

                }
                // cout << s << ' ' << i << ' ' << j << ' ' << dp[(s + i) % n][j] << '\n';
            }
            // ans = max(ans, dp[s + i][m - 1] + (sin(p[s] - p[s + i])) * 1000000);
        }
        // cout << s << ' ' << dp[s][m] << '\n';
        ans = max(ans, dp[s + n][m]);
    }
    cout << ans / 2 << '\n';
}

signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
