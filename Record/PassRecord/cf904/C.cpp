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
    int n, m; cin >> n >> m;
    vector<pii> a(n + 1);
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fir >> a[i].sec;
        tmp.pb(a[i].fir);
        tmp.pb(a[i].sec);
    }
    tmp.pb(1); tmp.pb(m);
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 1; i <= n; ++i) {
        a[i].fir = lower_bound(all(tmp), a[i].fir) - tmp.begin();
        a[i].sec = lower_bound(all(tmp), a[i].sec) - tmp.begin();
    }
    vector L(SZ(tmp) + 1, vector<int>()), R(SZ(tmp) + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        if (a[i].fir == 0 && a[i].sec == SZ(tmp) - 1) continue;
        L[a[i].fir].pb(a[i].sec);
        R[a[i].sec].pb(a[i].fir);
    }
    int ans = 0;
    int l = 0, r = 0, now = 0;
    for (int i = 0; i < SZ(tmp); ++i) {
        for (auto j : L[i]) {
            now++;
            if (i == 0) l++;
            if (j == SZ(tmp) - 1) r++;
        }
        ans = max(ans, now - min(l, r));
        for (auto j : R[i]) {
            now--;
            if (j == 0) l--;
            if (i == SZ(tmp) - 1) r--;
        }
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

