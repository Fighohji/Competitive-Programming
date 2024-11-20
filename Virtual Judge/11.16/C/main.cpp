#include <algorithm>
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
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    vector<int> a(n + 1);
    a[0] = 2200;
    for (int i = 1; i <= n; ++i) {
        int f;
        cin >> f >> a[i];
        G[f].push_back(i);
    }
    vector<int> dp(n + 1), leaf(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
        int cnt = 0;
        for (auto v : G[u]) {
            if (v == p) continue;
            cnt++;
            self(self, v, u);
        }
        if (!cnt) leaf[u] = 1, dp[u] = a[u];
    };
    auto DFS = [&](auto self, int u, int p) -> void {
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            dp[u] += dp[v];
        }
    };
    dfs(dfs, 0, -1);
    DFS(DFS, 0, -1);
    vector<int> x, y;
    for (int i = 1; i <= n; ++i) {
        if (!leaf[i]) {
            x.push_back(a[i]);
            y.push_back(dp[i]);
        }
    }
    sort(all(x)), sort(all(y));
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] < y[i]) {
            cout << "NO\n";
            return;
        }
    }
    if (dp[0] <= 2200) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

