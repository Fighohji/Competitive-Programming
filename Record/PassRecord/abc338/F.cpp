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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

#define int long long

int dis[50][50];
int dp[22][1 << 22];
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dis[i][j] = LINF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << n); ++j)
            dp[i][j] = LINF;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = w;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                if (dis[i][k] == LINF || dis[k][j] == LINF) continue;
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    for (int i = 1; i <= n; ++i) {
        dp[i][1 << (i - 1)] = 0;
    }
    for (int i = 1; i < (1 << n) - 1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if ((1 << (j - 1)) & i) {
                for (int k = 1; k <= n; ++k) {
                    if ((1 << (k - 1)) & i) continue;
                    if (dis[j][k] == LINF || dp[j][i] == LINF) continue;
                    dp[k][i | 1 << (k - 1)] = min(dp[k][i | 1 << (k - 1)], dp[j][i] + dis[j][k]);
                }
            }
        }
    }
    int Ans = LINF;
    for (int i = 1; i <= n; ++i) {
        Ans = min(Ans, dp[i][(1 << n) - 1]);
    }
    if (Ans == LINF) cout << "No\n";
    else cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
