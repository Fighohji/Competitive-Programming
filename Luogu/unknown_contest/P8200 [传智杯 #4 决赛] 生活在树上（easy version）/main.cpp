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

constexpr int N = 5e5 + 50;
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

#define int unsigned long long

int dep[N], pre[N];
void dfs(int u, int p, const vector<vector<pii>> &G) {
    dep[u] = dep[p] + 1;
    for (const auto &[v, w] : G[u])
        if (v != p) {
            pre[v] = pre[u] ^ w;
            dfs(v, u, G);
        }
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<pii>());
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dfs(1, 0, G);
    for (int i = 0; i < m; ++i) {
        int a, b, k;
        cin >> a >> b >> k;
        cout << ((pre[a] ^ pre[b]) == k ? "Yes\n" : "No\n");
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
