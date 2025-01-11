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

void solve() {
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++, deg[v]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2 == 0) {
            vector<pii> Ans;
            vector<int> dep(n + 1), id(n + 1), d(n + 1);
            for (int j = 0; j <= n; ++j)
                id[j] = j;
            auto dfs = [&](auto self, int u, int p) -> void {
                d[u] = d[u] + 1;
                // cerr << u << '\n';
                for (auto v : G[u]) {
                    if (v == p) continue;
                    self(self, v, u);
                    dep[u] = max(dep[u], dep[v] + 1);
                }
                sort(all(G[u]), [&](int x, int y) {
                    return dep[x] < dep[y];
                });
                vector<int> vec;
                for (int v : G[u]) {
                    if (v == p) continue;
                    vec.push_back(v);
                }
                // cerr << "siz " << u << ' ' << vec.size() << '\n';
                for (int j = 1; j < vec.size(); j += 2) {
                    Ans.emplace_back(id[vec[j - 1]], id[vec[j]]);
                } 
                if (vec.size() % 2) {
                    id[u] = id[vec.back()];
                } else {
                    dep[u] = 0;
                }
            };
            dfs(dfs, i, 0);
            cout << Ans.size() << '\n';
            for (auto &[x, y] : Ans) {
                cout << x << ' ' << y << '\n';
            }
            return;
        }
    }
    cout << "-1\n";
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
