#include <algorithm>
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
    int n, m, K;
    cin >> n >> m >> K;
    vector<int> s(n + 1);
    vector<vector<int>> a(n + 1, vector<int>(m));
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        tmp.push_back(s[i]);
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 1; i <= n; ++i) {
        s[i] = lower_bound(all(tmp), s[i]) - tmp.begin();
    }
    int k = tmp.size();
    vector<vector<int>> id(k);
    for (int i = 1; i <= n; ++i) {
        id[s[i]].push_back(i);
    }
    int las = -1;
    for (int i = 0; i < k; ++i) {
        int Max = 0;
        for (int j : id[i]) {
            int sum = 0;
            for (int p = 0; p < m; ++p)
                sum += (a[j][p] != -1 ? a[j][p] : 0);
            int res = max(0ll, las + 1 - sum);
            for (int p = 0; p < m; ++p) {
                if (a[j][p] == -1) {
                    a[j][p] = min(res, K);
                    res -= min(res, K);
                }
            }
            if (res > 0) {
                cout << "No\n";
                return;
            }
            Max = max(Max, accumulate(all(a[j]), 0ll));
        }
        las = Max;
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " \n"[j == m - 1];
        }
    }
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
