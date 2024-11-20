#include <map>
#include <pthread.h>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, m, q;

int a[2005][2005];
int pre[6][2005][2005];

int get(int id, int r2, int c2, int r1, int c1) {
    return pre[id][r2][c2] - pre[id][r1 - 1][c2] - pre[id][r2][c1 - 1] + pre[id][r1 - 1][c1 - 1];
}

void solve(int cas) {
    cin >> n >> m >> q;
    memset(a, -1, sizeof a);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (a[i + 1][j] - a[i][j] == 1) {
                pre[1][i][j] = 1;
            }
            if (a[i][j + 1] - a[i][j] == 1) {
                pre[2][i][j] = 1;
            }
            if (a[i - 1][j] - a[i][j] == 1) {
                pre[3][i][j] = 1;
            }
            if (a[i][j - 1] - a[i][j] == 1) {
                pre[4][i][j] = 1;
            }
        }
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= m; ++k)
                pre[i][j][k] += pre[i][j - 1][k] + pre[i][j][k - 1] - pre[i][j - 1][k - 1];
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int sum = 0;
        for (int i = 1; i <= 4; ++i) {
            sum += pre[i][r2][c2] - pre[i][r1 - 1][c2] - pre[i][r2][c1 - 1] + pre[i][r1 - 1][c1 - 1];
        }
        if (sum < (r2 - r1 + 1) * (c2 - c1 + 1) - 1) {
            cout << "NO\n";
        } else {
            sum -= get(4, r2, c1, r1, c1);
            // sum -= pre[4][r2][c1] - pre[4][r1 - 1][c1] - pre[4][r2][c1 - 1] + pre[4][r1 - 1][c1 - 1];
            sum -= get(3, r1, c2, r1, c1);
            // sum -= pre[3][r1][c2] - pre[3][r1 - 1][c1] - pre[3][r1][c1 - 1] + pre[3][r1 - 1][c1 - 1];
            sum -= get(2, r2, c2, r1, c2);
            // sum -= pre[2][r2][c2] - pre[2][r1 - 1][c2] - pre[2][r2][c2 - 1] + pre[2][r1 - 1][c2 - 1];
            sum -= get(1, r2, c2, r2, c1);
            // sum -= pre[1][r2][c2] - pre[1][r2 - 1][c2] - pre[1][r2][c1 - 1] + pre[1][r2 - 1][c1 - 1];
            if (sum == (r2 - r1 + 1) * (c2 - c1 + 1) - 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
