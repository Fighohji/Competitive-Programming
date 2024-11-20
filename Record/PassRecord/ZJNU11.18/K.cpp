#include <cstdlib>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

vector<int> G[maxn];
pii e[maxn];
int in[maxn], idx;
void dfs(int u) {
    if (in[u]) return ;
    in[u] = ++idx;
    for (auto v : G[u])
        dfs(v);
}
void solve() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v);
        e[i] = {u, v};
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i);
    }
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        auto [u, v] = e[i];
        if (in[u] < in[v]) cnt++;
    }
    cout << "YES\n";
    cout << max(cnt, m - cnt) << '\n';
    if (cnt <= m / 2) {
        for (int i = 1; i <= m; ++i) {
            auto [u, v] = e[i];
            if (in[u] > in[v]) {
                cout << i << ' ';
            }
        }
    } else {
        for (int i = 1; i <= m; ++i) {
            auto [u, v] = e[i];
            if (in[u] < in[v]) {
                cout << i << ' ';
            }
        }
    }

}

signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
