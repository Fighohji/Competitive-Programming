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

struct node {
    int t, d, id;
    bool operator<(const node &p) const {
        return t < p.t;
    }
} gun[105];

void solve(int cas) {
    int n, m, r; cin >> n >> m >> r;
    for (int i = 1; i <= r; ++i)
        cin >> gun[i].t >> gun[i].id >> gun[i].d;
    vector<vector<node>> buc(n * m * (r + 1) + 2);
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(r + 1, INF)));
    for (int i = 1; i <= r; ++i)
        if (gun[i].t <= n * m * (r + 1) + 1)
            buc[gun[i].t].eb(gun[i]);
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    dp[0][0][0] = 0;
    while (!q.empty()) {
        auto [x, y, k] = q.front(); q.pop();
        if (x == n && y == m) break;
        int T = dp[x][y][k];
        if (k < r && dp[x][y][k + 1] > T + 1) {
            bool f = 0;
            for (auto [t, d, id] : buc[T + 1]) {
                if (id == 1 && d == x || id == 2 && d == y) {
                    f = 1;
                    break;
                }
            }
            if (!f) {
                dp[x][y][k + 1] = T + 1;
                q.emplace(x, y, k + 1);
            }
        }
        if (x + 1 <= n) {
            if (dp[x + 1][y][k] > T + 1) {
                bool f = 0;
                for (auto [t, d, id] : buc[T + 1]) {
                    if (id == 1 && d == x + 1 || id == 2 && d == y) {
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    dp[x + 1][y][k] = T + 1;
                    q.emplace(x + 1, y, k);
                }
            }
        }
        if (y + 1 <= m) {
            if (dp[x][y + 1][k] > T + 1) {
                bool f = 0;
                for (auto [t, d, id] : buc[T + 1]) {
                    if (id == 1 && d == x || id == 2 && d == y + 1) {
                        f = 1;
                        break;
                    }
                }
                if (!f) {
                    dp[x][y + 1][k] = T + 1;
                    q.emplace(x, y + 1, k);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= r; ++i)
        ans = min(ans, dp[n][m][i]);
    if (ans == INF) cout << "-1\n";
    else cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}


