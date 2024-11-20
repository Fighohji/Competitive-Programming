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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
#define db double
#define il inline
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

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


void solve() {
    int n, m; cin >> n >> m;
    vector G(n + 1, vector<int>());
    vector<int> dep(n + 1);
    vector<bool> imp(n + 1);
    vector P(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        int fa; cin >> fa;
        G[fa].pb(i);
        dep[i] = dep[fa] + 1;
        P[dep[i]].pb(i);
    }
    for (int i = 1; i <= m; ++i) {
        int x; cin >> x;
        imp[x] = 1;
    }
    vector<int> rank(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        vector<pair<vector<int>, int>> vec;
        for (auto u : P[i]) {
            vector<int> rk;
            if (imp[u]) rk.pb(0);
            for (auto v : G[u])
                rk.pb(rank[v]);
            sort(all(rk));
            vec.pb({rk, u});
        }
        sort(all(vec), [&](pair<vector<int>, int> a, pair<vector<int>, int> b) {
            for (int i = 0; i < min(SZ(a.fir), SZ(b.fir)); ++i) {
                if (a.fir[i] != b.fir[i])
                    return (a.fir[i] < b.fir[i]);
            }
            return SZ(a.fir) > SZ(b.fir);
        });
        int now = 1;
        for (int i = 0; i < SZ(vec); ++i) {
            rank[vec[i].sec] = now;
            if (i < SZ(vec) - 1 && vec[i].fir != vec[i + 1].fir) now++;
        }
    }
    vector<char> ans(n + 1);
    auto dfs = [&](auto &&dfs, int u) -> void {
        vector<pii> tmp;
        for (auto v : G[u]) {
            tmp.pb({rank[v], v});
        }
        sort(all(tmp));
        for (int i = 0; i < SZ(tmp); ++i) {
            ans[tmp[i].sec] = i + 'a';
        }
        for (auto v : G[u])
            dfs(dfs, v);
    };
    dfs(dfs, 0);
    for (int i = 1; i <= n; ++i)
        cout << ans[i];
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
