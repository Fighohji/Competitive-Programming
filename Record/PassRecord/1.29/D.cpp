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

constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int st_max[11][17][maxn];

int lg[maxn];
int a[11][maxn];

void build_st(int id, int n) {

    for (int i = 1; i <= n; ++i)
        st_max[id][0][i] = a[id][i];
    for (int j = 1; j < 17; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st_max[id][j][i] = max(st_max[id][j - 1][i], st_max[id][j - 1][i + (1 << (j - 1))]);
}

int query_max(int id, int l, int r) {
    int k = lg[r - l + 1];
    return max(st_max[id][k][l], st_max[id][k][r - (1 << k) + 1]);
}

ll dp[maxn][11][11];
/*
dp[i][j][k] 第i次op 第j个arr 取第k个数
*/
void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 2; i <= m; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        build_st(i, m);
    memset(dp, -0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= m - k + 1; ++i)
        for (int j = 1; j <= n; ++j) {
            // Max[i + k] = 0;
            // for (int p = i + k - 1; p >= i; --p) {
            //     if (Max[p + 1] < a[j][p]) {
            //         Max[p] = a[j][p];
            //         idx[p] = p;
            //     } else {
            //         Max[p] = Max[p + 1];
            //         idx[p] = idx[p + 1];
            //     }
            // }
            for (int p = i; p <= i + k - 1; ++p) {
                for (int las = i - 1; las <= i + k - 2; ++las) {
                    dp[i][j][p] = max(dp[i][j][p], dp[i - 1][j])
                }
            }
        }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
