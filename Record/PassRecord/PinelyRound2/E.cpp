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
#define GG { cout << "NO\n"; return; }
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

bool BEGIN;

#define int long long


void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    vector G(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        G[u].eb(v);
        deg[v]++;
    }
    vector<int> dis(n + 1);
    vector<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            q.pb(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        int p = q[i];
        for (auto v : G[p]) {
            deg[v]--;
            if (deg[v] == 0) q.pb(v);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int u = q[i];
        for (auto v : G[u]) {
            dis[u] = max(dis[u], dis[v] + (h[v] - h[u] + k) % k);
        }
    }
    int Ans = LINF;
    for (int i = 1; i <= n; ++i) {
        dis[i] += h[i];
    }
    vector<int> id(n + 1);
    iota(all(id), 0);
    sort(id.begin() + 1, id.end(), [&](int x, int y) {
        return h[x] < h[y];
    });
    int Max = *max_element(all(dis));
    for (int i = 1; i <= n; ++i) {
        Ans = min(Ans, Max - h[id[i]]);
        Max = max(Max, dis[id[i]] + k);
    }
    cout << Ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
