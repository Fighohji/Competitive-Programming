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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector vec(20, vector<int>(n + 1));
    vector G(n + 1, vector<pii>());
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 20; ++j) {
            vec[j][i] = ((a[i] >> j) & 1);
        }
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].eb(v, 0); G[v].eb(u, 0);
    }
    vector<ll> Ans(n + 1);
    for (int j = 0; j < 20; ++j) {
        vector<int> sz(n + 1);
        ll tot = 0;
        auto dfs = [&](auto self, int u, int p) -> void {
            sz[u] = 1;
            for (auto &[v, flag] : G[u]) {
                if (v == p) continue;
                flag = (vec[j][u] ^ vec[j][v]);
                self(self, v, u);
                if (flag) tot += sz[v];
                sz[u] += sz[v];
            }
        };
        dfs(dfs, 1, 0);
        auto DFS = [&](auto self, int u, int p) -> void {
            Ans[u] += tot * (1 << j);
            for (auto [v, flag] : G[u]) {
                if (v == p) continue;
                if (flag) {
                    tot += n - sz[v];
                    tot -= sz[v];
                }
                self(self, v, u);
                if (flag) {
                    tot -= n - sz[v];
                    tot += sz[v];
                }
            }
        };
        DFS(DFS, 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << " \n"[i == n];
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
