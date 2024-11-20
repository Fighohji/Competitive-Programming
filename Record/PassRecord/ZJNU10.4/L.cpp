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
#define db long double
#define il inline
#define fir first
#define sec second
#define eps (1e-12)
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
  Point operator/(db a) { return Point(x / a, y / a); }

};
typedef Point Vector;
typedef vector<Point> Polygon;

ll cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外积
db mysqrt(ll x) { return sqrt(max((long double)0.0, (db)x)); }

ll norm(Point c) { return c.x * c.x + c.y * c.y; }

db abs(Point c) { return mysqrt(norm(c)); }

Vector getUnitVector(Vector p) { return p / abs(p); }


void solve() {
    int n; cin >> n;
    Polygon G(n);
    for (int i = 0; i < n; ++i)
        cin >> G[i].x >> G[i].y;

    ll tot = 0;
    for (int i = 1; i < n - 1; ++i)
        tot += cross(G[i] - G[0], G[i + 1] - G[0]);


    ll Area = 0;
    for (int i = 1; i < n - 1; ++i) {

        ll nd = tot - Area * 2;
        if (cross(G[i] - G[0], G[i + 1] - G[0]) * 2 < nd) {
            Area += cross(G[i] - G[0], G[i + 1] - G[0]);
            continue;
        }
        if (cross(G[i] - G[0], G[i + 1] - G[0]) * 2 == nd) {
            cout << G[i + 1].x << ' ' << G[i + 1].y << '\n';
            break;
        }
        Vector unit = (G[i + 1] - G[i]);
        db ux = unit.x / abs(unit), uy = unit.y / abs(unit);

        Vector tmp = G[0] - G[i];
        db l = -nd * 0.5 / (tmp.x * uy - tmp.y * ux);
        cout << G[i].x + l * ux << ' ' << G[i].y + l * uy << '\n';
        return ;
    }
}

/*
3
0 1
1 0
-1 0
*/
bool END;
signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
