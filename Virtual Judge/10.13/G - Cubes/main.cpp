#include <climits>
#include <iostream>
#include <random>
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

constexpr int N = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)


ll dp[N][5];
void solve() {
    int n, r1, r2, r3;
    cin >> n >> r1 >> r2 >> r3;
    dp[1][1] = dp[1][2] = dp[1][3] = 1;
    dp[r1 + 1][1] = (mod - 1);
    dp[r2 + 1][2] = mod - 1;
    dp[r3 + 1][3] = mod - 1;
    for(int i = 1; i <= n; ++i)
    {
        ll s = 0;
        for(int j = 1; j <= 3; ++j)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j]) % mod;
            s = (s + dp[i][j]) % mod;
        }
        for(int j = 1; j <= 3; ++j)
        {
            dp[i + 1][j] = (dp[i + 1][j] + s - dp[i][j] + mod) % mod;
        }
        dp[i + r1 + 1][1] = (dp[i + r1 + 1][1] - (s - dp[i][1] + mod) % mod + mod) % mod;
        dp[i + r2 + 1][2] = (dp[i + r2 + 1][2] - (s - dp[i][2] + mod) % mod + mod) % mod;
        dp[i + r3 + 1][3] = (dp[i + r3 + 1][3] - (s - dp[i][3] + mod) % mod + mod) % mod;
    }
    ll Ans = (dp[n][1] + dp[n][2] + dp[n][3]) % mod;
    cout << Ans << '\n';
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
