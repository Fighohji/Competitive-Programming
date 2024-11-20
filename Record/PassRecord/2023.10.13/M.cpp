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


class Point {
public:
  ll x, y;

  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(ll a) { return Point(a * x, a * y); }
  Point operator/(ll a) { return Point(x / a, y / a); }

};
typedef Point Vector;
typedef vector<Point> Polygon;

il ll cross(Vector a, Vector b) { return abs(a.x * b.y - a.y * b.x); } // 外积


void solve() {
    int n, k; cin >> n >> k;
    Polygon G;
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        G.pb({x, y});
    }
    ll Area = 0;
    for (int i = 2; i <= k; ++i)
        Area += cross(G[i] - G[0], G[i - 1] - G[0]);
    ll ans = 0;
    for (int i = 0, j = k, now = k; i < n; ++i, ++now) {
        now %= n;
        if (i) {
            Area += cross(G[now] - G[i], G[(now - 1 + n) % n] - G[i]);
            Area -= cross(G[i] - G[(now - 1 + n) % n],
                          G[(i - 1 + n) % n] - G[(now - 1 + n) % n]);
        }
        while (abs(cross(G[now] - G[j], G[(now - k + n) % n] - G[j]))
             < abs(cross(G[now] - G[(j + 1) % n], G[(now - k + n) % n] - G[(j + 1) % n]))) {
            j++;
            j %= n;
        }
        ans = max(ans, Area + abs(cross(G[now] - G[j], G[(now - k + n) % n] - G[j])));
        if (j == now) j = (j + 1) % n;
    }
    cout << (db)ans / 2 << '\n';
}

signed main() {
    cout << fixed << setprecision(1);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
