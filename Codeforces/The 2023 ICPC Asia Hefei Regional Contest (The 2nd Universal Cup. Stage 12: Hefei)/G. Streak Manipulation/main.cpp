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

int dp[N][6], dp2[N][6];
void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    s = '~' + s;
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        pre[i] = pre[i - 1] + (s[i] == '0');
    }
    auto check = [&](int len) -> bool 
    {
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 0; j <= k; ++j)
            {
                dp[i][j] = dp2[i][j] = INF;
            }
        }
        dp2[0][0] = 0;
        int tot = INF;
        for(int i = 1; i <= n; ++i)
        {
            if(s[i] == '0')
            {
                for(int j = 0; j <= k; ++j) dp2[i][j] = dp[i - 1][j];
                // dp2[i] = dp[i - 1];
                for(int j = 0; j <= k; ++j) dp2[i][j] = min(dp2[i][j], dp2[i - 1][j]);
            }
            else 
            {
                for(int j = 0; j <= k; ++j) dp[i][j] = dp[i - 1][j];
                for(int j = 0; j <= k; ++j) dp2[i][j] = dp2[i - 1][j];
                // dp[i] = dp[i - 1];÷
                // dp2[i] = dp2[i - 1];
            }
            if(i < len) continue;
            for(int j = 1; j <= k; ++j)
            {
                dp[i][j] = dp2[i - len][j - 1] + pre[i] - pre[i - len];
            }
            
            tot = min(tot, dp[i][k]);
        }
        return tot <= m;

    };
    // check(2);
    int l = 1, r = n;
    int ans = -1;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) 
        {
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
