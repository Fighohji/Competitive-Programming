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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /*998244353;*/ /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;



void solve(int cas) {
    int n; cin >> n;
    ll ans, sum = 0;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        sum += abs(a[i] - b[i]);
    }
    vector<pll> S, T;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > b[i]) {
            T.eb(b[i], a[i]);
        } else {
            S.eb(a[i], b[i]);
        }
    }
    sort(all(S));
    ans = sum;
    vector<ll> sx, sy, len;
    ll pre = -LINF;
    for (auto [x, y] : S) {
        if (y <= pre) continue;
        pre = y;
        sx.pb(x);
        sy.pb(y);
        len.pb(y - x);
    } 
    for (auto [x, y] : T) {
        ll res = 0;
        int l = upper_bound(all(sx), x) - sx.begin();
        if (l) res = max(res, 2 * (min(sy[l - 1], y) - x));
        int r = lower_bound(all(sy), y) - sy.begin();
        if (r < SZ(sx)) res = max(res, 2 * (y - max(sx[r], x)));
        if (l < r) res = max(res, 2 * *(max_element(len.begin() + l, len.begin() + r)));
        ans = min(ans, sum - res);
    }
    cout << ans << '\n';
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
