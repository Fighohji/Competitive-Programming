#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <random>
#include <tuple>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

int dp[2][101][101], vis[2][101][101];

void solve() {
    memset(dp, 0x3f, sizeof dp);
    int inf = dp[0][0][0];
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    dp[0][x][y] = 0;
    queue<tuple<int, int, int>> que;
    que.push({0, x, y});
    while (!que.empty()) {
        auto [s, a, b] = que.front();
        que.pop();
        if (vis[s][a][b]) continue;
        vis[s][a][b] = 1;
        for (int tot = 0; tot <= min(a + b, p); ++tot) {
            for (int she = max(tot - b, 0); she <= min(a, tot); ++she) {
                int wof = tot - she;
                if ((a - she + q >= b - wof || a - she == 0) && dp[s ^ 1][x - (a - she)][y - (b - wof)] > dp[s][a][b] + 1) {
                    dp[s ^ 1][x - (a - she)][y - (b - wof)] = dp[s][a][b] + 1;
                    que.push({s ^ 1, x - (a - she), y - (b - wof)});
                }
            }
        }
    }
    int Ans = inf;
    for (int i = 0; i <= y; ++i) {
        Ans = min(Ans, dp[1][x][i]);
    }
    if (Ans != inf) {
        cout << Ans << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
