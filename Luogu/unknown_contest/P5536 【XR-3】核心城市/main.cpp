#include <climits>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
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
    int n, k;
    cin >> n >> k;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int Max = 0, id;
    auto dfs = [&](auto self, int u, int p, int dep) -> void {
        if (Max < dep) {
            Max = dep;
            id = u;
        }    
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u, dep + 1);
        }
    };
    dfs(dfs, 1, 0, 1);
    dfs(dfs, id, 0, 1);
    vector<int> link;
    auto DFS = [&](auto self, int u, int p, int dep) -> bool {
        link.push_back(u);
        if (dep == Max) return 1;
        for (auto v : G[u]) {
            if (v == p) continue;
            if (self(self, v, u, dep + 1)) return 1;
        }
        link.pop_back();
        return 0;
    };
    DFS(DFS, id, 0, 1);
    int cen = link[(int)link.size() / 2];
    vector<int> h(n + 1);
    auto dfs1 = [&](auto self, int u, int p) -> void {
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            h[u] = max(h[v] + 1, h[u]);
        }
    };
    dfs1(dfs1, cen, 0);
    sort(all(h));
    h[0] = -1;
    cout << h[n - k] + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
