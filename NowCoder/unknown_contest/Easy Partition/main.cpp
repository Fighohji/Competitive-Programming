#include <climits>
#include <iostream>
#include <numeric>
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (k == 1) {
        cout << accumulate(all(a), 0ll) << '\n';
        return;
    }
    vector<vector<int>> f(n + 1, vector<int>(2, -LINF));
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        if (i >= k) {
            f[i][1] = max(f[i - k][1] + a[i], f[i][1]);
            f[i][1] = max(f[i - k][0] + a[i], f[i][1]);
        }
        f[i][1] = max(f[i - 1][1] + a[i], f[i][1]);
    }
    cout << max(f[n][0], f[n][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
