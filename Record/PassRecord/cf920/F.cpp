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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define int long long

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int p = sqrt(n);
    while ((p + 1) * (p + 1) <= n) p++;
    vector<vector<vector<int>>> pre1(p + 1), pre2(p + 1);
    for (int i = 1; i * i <= n; ++i) {
        pre1[i].pb(vector<int>());
        pre2[i].pb(vector<int>());
        for (int j = 1; j <= i; ++j) {
            pre1[i].pb(vector<int>((n + i - 1) / i + 1));
            pre2[i].pb(vector<int>((n + i - 1) / i + 1));
            for (int k = j, b = 1; k <= n; k += i, ++b) {
                pre1[i][j][b] = a[k] * b;
                pre2[i][j][b] = a[k];
            }
            for (int k = 2; k < SZ(pre1[i][j]); ++k) {
                pre1[i][j][k] += pre1[i][j][k - 1];
                pre2[i][j][k] += pre2[i][j][k - 1];
            }
        }
    }

    while (q--) {
        int s, d, k; cin >> s >> d >> k;
        if (d * d >= n) {
            int ans = 0;
            for (int i = 0; i < k; ++i) {
                ans += a[s + i * d] * (i + 1);
            }
            cout << ans << ' ';
        } else {
            int st = (s + d - 1) / d;
            cout << pre1[d][(s - 1) % d + 1][st + k - 1] - pre1[d][(s - 1) % d + 1][st - 1]
                    - (st - 1) * (pre2[d][(s - 1) % d + 1][st + k - 1] - pre2[d][(s - 1) % d + 1][st - 1]) << " ";
        }
    }
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
