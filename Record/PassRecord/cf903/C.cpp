#include <iterator>
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
    vector<string> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    b = a, c = a, d = a;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            b[j][n - i - 1] = a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            c[j][n - i - 1] = b[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[j][n - i - 1] = c[i][j];
    int ans = 0;
    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n / 2; ++j) {
            int mx = max({a[i][j], b[i][j], c[i][j], d[i][j]});
            ans += 4 * mx - a[i][j] - b[i][j] - c[i][j] - d[i][j];
        }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
