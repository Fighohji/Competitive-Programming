#include <algorithm>
#include <array>
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

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {
        fa.resize(n + 1);
        iota(all(fa), 0);
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    bool merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return 0;
        fa[yy] = xx;
        return 1;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<array<int, 3>> b(n * n + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            b[(i - 1) * n + j] = {x, i, j};
        }
    sort(all(b));
    DSU d(n);
    vector<bool> vis(n + 1);
    int Ans = 0;
    for (int i = 1; i <= n * n; ++i) {
        const auto &[w, u, v] = b[i]; 
        if (u == v) {
            if (vis[u]) continue;
            vis[u] = 1;
            Ans += (a[u] - 1) * w;
            continue;
        }
        int num = (vis[u] ? 1 : a[u]) + (vis[v] ? 1 : a[v]);
        if (!d.merge(u, v)) continue;
        d.merge(u, v);
        Ans += (num - 1) * w;
        vis[u] = vis[v] = 1;
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
