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


int a[10][10];
pair<int, int> dp[10][10];
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first * b.second >= a.second * b.first;
}
void solve() {
    int n = 6;
    for(int i = 1; i <= 3; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= 3; ++i)
    {
        for(int j = 1; j <= 3; ++j)
        {
            if(i == j) continue;
            dp[i][j] = {0, 36};
            for(int k1 = 1; k1 <= n; ++k1)
            {
                for(int k2 = 1; k2 <= n; ++k2)
                {
                    if(a[i][k1] > a[j][k2]) dp[i][j].first += 1;
                    else if(a[i][k1] == a[j][k2]) dp[i][j].second -= 1;
                }
            }
        }
    }
    pair<int, int> fr = {1, 2};
    for(int i = 1; i <= 3; ++i)
    {
        int f = 1;
        for(int j = 1; j <= 3; ++j)
        {
            if(i == j) continue;
            if(dp[i][j].second == 0) f = 0;
            // cout << i << ' ' << j << ' ' << dp[i][j].first << ' ' << dp[i][j].second << '\n';
            if(!cmp(dp[i][j], fr)) f = 0;
        }
        if(f)
        {
            cout << i << '\n';
            return ;
        }
    }
    cout << "No dice\n";

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
