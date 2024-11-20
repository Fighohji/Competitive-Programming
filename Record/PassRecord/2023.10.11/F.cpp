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

int dis[405][405];
int dp[405][405];

void solve() {
    int n, m; cin >> n >> m;
    vector<int> s(n), t(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int j = 0; j < n; ++j)
        cin >> t[j];
    memset(dis, 0x3f, sizeof dis);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1;  i <= 400; ++i)
        dp[i][i] = 0;
    for (int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
    }
    for (int k = 1; k <= 400; ++k)
        for (int i = 1; i <= 400; ++i)
            for (int j = 1; j <= 400; ++j)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 1; i <= 400; ++i)
        for (int j = 1; j <= 400; ++j)
            for (int k = 1; k <= 400; ++k)
                dis[i][j] = min(dis[i][j], dp[i][k] + dp[j][k]);
    // for (int i = 1; i <= n; ++i)
    //     for (int j = 1; j <= n; ++j)
    //         cout << dis[i][j] << " \n"[j == n];
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        int res = 0;
        for (int j = 0; j < n; ++j) {
            if (dis[s[(i + j) % n]][t[j]] == dis[0][0]) {
                res = INF;
                break;
            }
            res += dis[s[(i + j) % n]][t[j]];
        }
        ans = min(ans, res);
    }
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
