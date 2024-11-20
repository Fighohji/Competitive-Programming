#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <cstdio>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool BEGIN;
ll x, y, z;
ll dp[maxn][2][2];
string s;
void solve(int cas) {
    cin >> x >> y >> z;
    cin >> s;
    int n = SZ(s);
    s = "!" + s;
    dp[0][0][1] = dp[0][1][1] = LINF;
    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = dp[i][1][0] = LINF;
        dp[i][0][1] = dp[i][1][1] = LINF;
    }
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'a') {
            dp[i][0][0] = min({dp[i - 1][0][0] + x, dp[i - 1][0][1] + z + x, dp[i][0][0]});
            dp[i][0][1] = min({dp[i - 1][0][0] + z + y, dp[i - 1][0][1] + y, dp[i][0][1]});

            dp[i][0][0] = min({dp[i - 1][1][0] + x, dp[i - 1][1][1] + z + x, dp[i][0][0]});
            dp[i][0][1] = min({dp[i - 1][1][0] + z + y, dp[i - 1][1][1] + y, dp[i][0][1]});
            // cout << i << '\n';
            // cout << dp[i][0][1] << ' ' << dp[i][0][0] << '\n';
        } else {
            // cout << dp[i - 1][0][1] << ' ' << dp[i - 1][0][0] << '\n';
            dp[i][1][0] = min({dp[i - 1][0][0] + y, dp[i - 1][0][1] + z + y, dp[i][1][0]});
            dp[i][1][1] = min({dp[i - 1][0][0] + z + x, dp[i - 1][0][1] + x, dp[i][1][1]});

            dp[i][1][0] = min({dp[i - 1][1][0] + y, dp[i - 1][1][1] + z + y, dp[i][1][0]});
            dp[i][1][1] = min({dp[i - 1][1][0] + z + x, dp[i - 1][1][1] + x, dp[i][1][1]});
            // cout << i << '\n';
            // cout << dp[i][1][1] << ' ' << dp[i][1][0] << '\n';
        }
    }
    cout << min({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]}) << '\n';
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
