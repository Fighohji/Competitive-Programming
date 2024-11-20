#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct Edge {
    int u, v;
    ll w;
};

namespace DSU
{
    int fa[100];
    void init(int n) { for (int i = 1; i <= n; ++i) fa[i] = i; }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y)
    {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        fa[yy] = xx;
    }
}
using namespace DSU;


void solve() {
    int n, m; cin >> n >> m;
    ll k; cin >> k;
    vector<Edge> G(m);
    for (int i = 0; i < m; ++i) {
        cin >> G[i].u >> G[i].v >> G[i].w;
    }
    ll ans = LINF;
    auto check = [&](int sta) -> ll {
        ll sum = 0;
        for (int i = 1; i <= n; ++i) fa[i] = i;
        for (int i = 0; i < m; ++i) {
            if (sta & (1 << i)) {
                if (find(G[i].u) != find(G[i].v)) sum = (G[i].w + sum) % k;
                merge(G[i].u, G[i].v);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (find(i) != find(1)) return LINF;
        }
        return sum;
    };
    auto dfs = [&](auto &&dfs, int pre, int pos, int sta) -> void {
        if (pre == m && pos != n - 1) return ;
        if (m - pre < n - 1 - pos) return ;
        if (pos == n - 1) {
            ans = min(ans, check(sta));
            return ;
        }
        for (int i = pre; i < m; ++i) {
            dfs(dfs, i + 1, pos + 1, sta | (1 << i));
        }
    };
    dfs(dfs, 0, 0, 0);
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
