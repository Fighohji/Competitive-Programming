#include <algorithm>
#include <climits>
#include <functional>
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
constexpr int mod = 10007;
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
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int Max = 0, sum = 0; 
    vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    vector<int> fa(n + 1);
    auto dfs = [&](auto self, int u, int p) -> void {
        fa[u] = p;
        sum += w[u] * w[fa[fa[u]]] * 2;
        Max = max(Max, w[u] * w[fa[fa[u]]]);
        vector<int> val;
        int tot = 0;
        for (auto v : G[u]) {
            if (v == p) continue;
            val.push_back(w[v]);
            sum += tot * w[v] * 2;
            tot += w[v];
            self(self, v, u);
        }
        sort(all(val), greater());
        if (val.size() > 1) {
            Max = max(Max, val[0] * val[1]);
        }
    };
    dfs(dfs, 1, 0);
    cout << Max << ' ' << sum % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
