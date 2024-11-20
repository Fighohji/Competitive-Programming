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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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

#define int long long

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n + 1), cost(m + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= m; ++i)
        cin >> cost[i];
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j * i <= m; ++j)
            cost[j * i] = min({cost[j * i], cost[j] + cost[i]});
    cost[m + 1] = LINF;
    for (int i = m; i >= 1; --i)
        cost[i] = min(cost[i + 1], cost[i]);
    int j = 2;
    for (int i = m; i >= 2; --i) {
        while (i * j <= m) j++;
        cost[m + 1] = min(cost[i] + cost[j], cost[m + 1]);
    }
    for (int i = 1; i <= m; ++i) {
        cost[i] = min(cost[i], cost[m + 1]);
    }
    int ans = *max_element(all(a));
    int l = 0, r = *max_element(all(a));
    auto check = [&](int x) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] <= x)
                cnt++;
        }
        int nd = (n + 1) / 2;
        ll cos = 0;
        while (cnt < nd) {
            if (x == 0) cos += cost[a[cnt + 1] + 1];
            else {
                // int X = (a[cnt + 1] + x - 1) / x;
                // int Y = (a[cnt + 1]) / x;
                // if (a[cnt + 1] / Y == x) cos += cost[Y];
                // else cos += cost[X];
                cos += cost[a[cnt + 1] / (x + 1) + 1];
            }
            cnt++;
        }
        return cos <= k;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
}
/*
3
3 5 0
2 5 2
3 2 4 6 13
3 5 3
2 5 3
3 2 4 6 13
3 5 6
2 5 2
3 2 4 6 13
*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
