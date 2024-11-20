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


void solve() {
    ll n, k; cin >> n >> k;
    vector<ll>vp(100);
    vp[0] = 0;
    // vp[1] = 1;
    for(int i = 1; i < 70; ++i) vp[i] = vp[i - 1] * 2 + 1;
    int lg = log2(n);
    ll res = n - ((1ll << lg) - 1);
    ll cnt0 = 0, cnt1 = res, cnt2 = 0;
    ll sz0 = 0, sz1 = 1, sz2 = 0;
    ll ans = 0;
    if(k >= lg + 1 && n - k + 1 >= 1) ans += res;
    int dep = lg + 1;
    ll rk = n;
    for (int i = lg - 1; i >= 0; --i) {
        // cout << ans << '\n';
        ll L = (1ll << i);
        ll R = (1ll << (i + 1)) - 1;
        rk /= 2;
        sz0 = (1ll << (lg - i + 1)) - 1;
        sz2 = (1ll << (lg - i)) - 1;
        sz1 = n - vp[i] - sz0 * (rk - L) - sz2 * (R - rk);
        // cout << "*" << vp[i - 1] << '\n';
        // cout << rk << ' ' << sz0 << ' ' << sz1 << ' ' << sz2 << '\n';
        // cout << L << ' ' << R << '\n';
        if(k <= i) continue;
        if (sz0 <= n - k + 1) {
            ans += rk - L;
        }
        if (sz1 <= n - k + 1) {
            ans += 1;
        }
        if (sz2 <= n - k + 1) {
            ans += R - rk;
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
