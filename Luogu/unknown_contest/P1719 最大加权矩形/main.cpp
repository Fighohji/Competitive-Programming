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

void solve() {
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            // a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    int Ans = -INF;
    for (int x1 = 1; x1 <= n; ++x1)
        for (int y1 = 1; y1 <= n; ++y1)
            for (int x2 = x1; x2 <= n; ++x2)
                for (int y2 = y1; y2 <= n; ++y2) {
                    // Ans = max(Ans, a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1]);
                    int sum = 0;
                    for (int i = x1; i <= x2; ++i)
                        for (int j = y1; j <= y2; ++j)
                            sum += a[i][j];
                    Ans = max(Ans, sum);
                }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
