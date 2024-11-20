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

int dp[60][60][60][60];

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    vector<pii> st;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'P')
                st.pb({i, j});
        }
    }
    queue<array<pii, 2>> q;
    memset(dp, 0x3f, sizeof dp);
    dp[st[0].fir][st[0].sec][st[1].fir][st[1].sec] = 0;
    q.push({st[0], st[1]});
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        auto [sx, sy] = p[0];
        auto [tx, ty] = p[1];
        // cout << sx << ' ' << sy << ' ' << tx << ' ' << ty << '\n';
        if (sx == tx && sy == ty) {
            cout << dp[sx][sy][tx][ty] << '\n';
            return ;
        }
        for (int i = 0; i < 8; i += 2) {
            int nx0 = sx + dir[i][0];
            int ny0 = sy + dir[i][1];
            int nx1 = tx + dir[i][0];
            int ny1 = ty + dir[i][1];
            auto judge = [&](int x, int y) {
                if (x < 0 || x >= n || y < 0 || y >= n) return 0;
                if (s[x][y] == '#') return 0;
                return 1;
            };
            if (!judge(nx0, ny0)) {
                nx0 = sx;
                ny0 = sy;
            }
            if (!judge(nx1, ny1)) {
                nx1 = tx;
                ny1 = ty;
            }
            if (dp[nx0][ny0][nx1][ny1] > dp[sx][sy][tx][ty] + 1) {
                dp[nx0][ny0][nx1][ny1] = dp[sx][sy][tx][ty] + 1;
                q.push({mkp(nx0, ny0), mkp(nx1, ny1)});
            }
        }
    }
    cout << -1 << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
