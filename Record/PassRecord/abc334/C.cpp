
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


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 2);
    for (int i = 1; i <= k; ++i) {
        int x; cin >> x;
        a[x]--;
    }
    vector<int> b = {0};
    for (int i = 1; i <= n; ++i) {
        while (a[i]) {
            b.pb(i);
            a[i]--;
        }
    }
    if (k % 2 == 0) {
        ll ans = 0;
        for (int i = 2; i <= 2 * n - k; i += 2) {
            ans += b[i] - b[i - 1];
        }
        cout << ans << '\n';
        return ;
    }
    vector<ll> pre(2 * n + 4), suf(2 * n + 4);
    for (int i = 2; i <= 2 * n - k; i += 2) {
        pre[i] = pre[i - 2] + b[i] - b[i - 1];
        pre[i + 1] = pre[i];
    }
    for (int i = 2 * n - k - 1; i >= 1; i -= 2) {
        suf[i] = suf[i + 2] + b[i + 1] - b[i];
        suf[i - 1] = suf[i];
    }
    ll ans = LINF;
    if (2 * n - k == 1) {
        ans = 0;
    }
    for (int i = 1; i <= 2 * n - k; ++i) {
        ll res = pre[i - 1] + suf[i + 1];
        if (i % 2 == 0) {
            res += b[i + 1] - b[i];
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
