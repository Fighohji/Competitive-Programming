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

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int k = 5000;
    vector<vector<int>> G(5002, vector<int>(5002));
    for (int i = 1; i <= n; ++i) {
        int x, y, v;
        cin >> x >> y >> v;
        x++, y++;
        G[x][y] += v;
    }
    for (int i = 1; i <= k + 1; ++i)
        for (int j = 1; j <= k + 1; ++j)
            G[i][j] += G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1];
    int Ans = 0;
    auto getVal = [&](int x1, int x2, int y1, int y2) -> int {
        return G[x2][y2] - G[x2][y1 - 1] - G[x1 - 1][y2] + G[x1 - 1][y1 - 1];
    };
    for (int i = 1; i <= k + 1; ++i)
        for (int j = 1; j <= k + 1; ++j)
            Ans = max(Ans, getVal(max(1ll, i - m + 1), i, max(1ll, j - m + 1), j));
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
