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
    int n; ll m; cin >> n >> m;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    if (m < n) {
        cout << 0 << '\n';
        return ;
    }
    ll l = 0, r = 1e17;
    while (l <= r) {
        ll mid = l + r >> 1;
        auto check = [&](ll x) {
            vector<ll> cnt(n + 2), tmp(n + 2);
            for (int i = 1; i <= n; ++i) {
                cnt[i] = (x + d[i] - 1) / d[i];
            }
            __int128 tot = 0;
            for (int i = 1; i <= n; ++i) {
                if (cnt[i] > tmp[i]) {
                    tot += (cnt[i] - tmp[i]) * 2 - 1;
                    tmp[i + 1] += (cnt[i] - tmp[i] - 1);
                } else {
                    if (i == n) continue;
                    tot += 1;
                }
            }
            return tot <= m;
        };
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1 << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
