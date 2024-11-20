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
#define eps (1e-10)
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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

struct Nxt {
    int v, b, c;
};

void solve() {
    int n, m; cin >> n >> m;
    vector G(n + 1, vector<Nxt>());
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        int b, c; cin >> b >> c;
        G[u].eb(v, b, c);
    }
    db l = 0, r = 1e4;
    auto check = [&](db k) -> bool {
        vector<db> dp(n + 1, -LINF);
        dp[1] = 0;
        for (int i = 1; i < n; ++i)
            for (auto [v, b, c] : G[i])
                dp[v] = max(dp[v], dp[i] + b - k * c);
        return dp[n] >= 0;
    };
    while (r - l > eps) {
        db mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << r << '\n';
}

signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
