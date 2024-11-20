#include <climits>
#include <iostream>
#include <random>
#include <iomanip>
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

#define int long long
double dp[5010];
double dis[5010][5010];
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> p(n + 1);
    for(int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    auto clc = [&](int x, int y) -> double
    {
        int d2 = (p[x].first - p[y].first) * (p[x].first - p[y].first) + (p[x].second - p[y].second) * (p[x].second - p[y].second);
        return sqrt(d2);
    };
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;
    for(int i = 1; i + 1 <= n; ++i) dis[i][i + 1] = clc(i, i + 1);
    for(int len = 3; len <= n; ++len)
    {
        for(int l = 1, r = len; r <= n; l++, r++)
        {
            dis[l][r] = max({dis[l + 1][r], dis[l][r - 1], clc(l, r)});
            // cout << dis[l][r] << ' ' << l << ' ' << r << '\n';
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            dp[i] = max(dp[i], dp[j] + dis[j + 1][i]);
        }
    }
    cout << fixed << setprecision(10) << dp[n] << '\n';
    // cout << dis[3][7] << '\n';
}
/*
7
1 0
0 1
0 0
1 1
1 2
3 2
3 3
 */
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

