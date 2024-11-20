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


void solve() {
    int n; cin >> n;
    vector G(n + 1, vector<int>(n + 1, 0));
    int now = 0;
    pii po = {1, 1};
    vector<pii> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int id = 0;
    int T = 10;
    for (; now < n * n - 1;) {
        // cerr << now << '\n';
        if (G[po.fir][po.sec] == 0) {
            G[po.fir][po.sec] = ++now;
        }
        auto [nx, ny] = po;
        nx += d[id].fir, ny += d[id].sec;
        // cerr << nx << ' ' << ny << '\n';
        if (nx <= 0 || ny <= 0 || nx > n || ny > n || G[nx][ny]) {
            // cout << "@@@\n";
            id = (id + 1) %  4;
        }
        else
            po = {nx, ny};
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (G[i][j]) {
                cout << G[i][j] << ' ';
            } else {
                cout << "T ";
            }
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
