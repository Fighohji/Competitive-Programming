#include <climits>
#include <iomanip>
#include <iostream>
#include <random>
#include <cmath>
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
const double PI = acos(-1.0);
mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, p; cin >> n >> p;
    vector<double> a(2 * n + 1);
    for(int i = 1; i <= n; ++i)
    {
        // int Angle; 
        cin >> a[i];
        // a[i] = {1000.0 * cos(1.0 * Angle / 180.0 * PI), 1000.0 * sin(1.0 * Angle / 180.0 * PI)};
        a[i + n] = a[i];

    }
    auto Cross = [&](int p1, int p2) -> double
    {
        double Angle = (a[p2] - a[p1]) / 180.0 * PI;
        return 1000000.0 * sin(Angle);
    };
    vector dp(2 * n + 1, vector<vector<double>>(2 * n + 1, vector<double>(p + 1, -1e18)));
    for(int i = 1; i <= 2 * n; ++i) dp[i][i][1] = 0;
    double ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= 2 * n && j <= i + n; ++j)
        {
            for(int k = i; k < j; ++k)
            {
                for(int r = 1; r < p; ++r)
                {
                    if(dp[i][k][r] < -1e17) continue;
                    dp[i][j][r + 1] = max(dp[i][j][r + 1], dp[i][k][r] + Cross(k, j));
                    if(r + 1 == p) 
                    {
                        // cout << i << ' ' << j << '\n';
                        // cout << fixed << setprecision(10) << dp[i][j][p] << ' ' << Cross(j, i) << '\n';
                        ans = max(ans, dp[i][j][p] + Cross(j, i));
                    }
                }
            }
        }
    }
    // ans *= 1000000.0;
    cout << fixed << setprecision(20) << ans / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
