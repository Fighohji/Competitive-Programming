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
    int n, m, k; cin >> n >> m >> k;
    vector<string> G(n);
    for (int i = 0; i < n; ++i)
        cin >> G[i];
    int Ans = INF;
    vector<vector<int>> pre1(n, vector<int>(m)), pre2(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        pre1[i][0] = (G[i][0] == '.');
        pre2[i][0] = (G[i][0] == 'x');
        for (int j = 1; j < m; ++j) {
            pre1[i][j] = pre1[i][j - 1] + (G[i][j] == '.');
            pre2[i][j] = pre2[i][j - 1] + (G[i][j] == 'x');
        }
        for (int j = 0; j + k - 1 < m; ++j) {
            if (pre2[i][j + k - 1] - (j ? pre2[i][j - 1] : 0) == 0) {
                Ans = min(Ans, pre1[i][j + k - 1] - (j ? pre1[i][j - 1] : 0));
            }
        }
    }
     vector<vector<int>> suf1(m, vector<int>(n)), suf2(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        suf1[i][0] = (G[0][i] == '.');
        suf2[i][0] = (G[0][i] == 'x');
        for (int j = 1; j < n; ++j) {
            suf1[i][j] = suf1[i][j - 1] + (G[j][i] == '.');
            suf2[i][j] = suf2[i][j - 1] + (G[j][i] == 'x');
        }
        for (int j = 0; j + k - 1 < n; ++j) {
            if (suf2[i][j + k - 1] - (j ? suf2[i][j - 1] : 0) == 0) {
                Ans = min(Ans, suf1[i][j + k - 1] - (j ? suf1[i][j - 1] : 0));
            }
        }
    }
    cout << (Ans == INF ? -1 : Ans) << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
