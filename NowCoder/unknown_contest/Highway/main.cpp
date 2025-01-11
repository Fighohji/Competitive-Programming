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
    vector G(n + 1, vector<pii>());
    for (int i = 1; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    vector<int> d1(n + 1), d2(n + 1); 
    int tmp, Max = 0;
    auto dfs = [&](auto self, int u, int p, vector<int> &dis) -> void {
        if (dis[u] > Max) {
            Max = dis[u];
            tmp = u;
        }
        for (auto &[v, w] : G[u]) {
            if (v == p) continue;
            dis[v] = dis[u] + w;
            self(self, v, u, dis);
        }
    };
    dfs(dfs, 1, 0, d1);
    d1[tmp] = 0;
    Max = 0;
    dfs(dfs, tmp, 0, d1);
    Max = 0;
    dfs(dfs, tmp, 0, d2);
    int Ans = -Max;
    for (int i = 1; i <= n; ++i) {
        Ans += max(d1[i], d2[i]);
    }
    cout << Ans << '\n';
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
