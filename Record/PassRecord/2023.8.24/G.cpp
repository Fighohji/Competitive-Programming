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
#define eps (1e-10)
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
#define endl '\n'
il int dcmp(long double x) {
  if (equals(x, 0.0))
    return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}




struct Point {
    __int128 x, v;
    bool operator<(const Point &t) const {
        if (x != t.x) return x < t.x;
        return v > t.v;
    }
};

struct point {
    __int128 x, v;
};

void solve() {
    vector<Point> pl, pr;
    int n, v; cin >> n >> v;
#define i128 __int128
    for (int i = 1; i <= n; ++i) {
        ll pos, ve; cin >> pos >> ve;
        if (pos < 0) pl.eb((i128)pos * 1000000000000000000ll, ve);
        else pr.eb((i128)pos * 1000000000000000000ll, ve);
    }

        i128 l = 0, r = 2;
        for (int i = 0; i < 30; ++i) r *= 10;
        while (l <= r) {
            i128 mid = (l + r) / 2;
            auto check = [&](i128 t) -> bool {
                i128 L = pl[0].x + pl[0].v * t, R = pr[0].x - pr[0].v * t;
                for (auto [x, sp] : pl) {
                    L = max(L, x + sp * t);
                }
                for (auto [x, sp] : pr) {
                    R = min(R, x - sp * t);
                }
                return L >= R;
            };
            if (check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << (long double)(r + 1) * v / 1000000000000000000ll << '\n';
}

bool END;
signed main() {
    cout << fixed << setprecision(20);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
