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
#define eps 0
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
#define equals(a, b) (abs((a) - (b)) == eps)

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
class Point {
public:
  ll x, y;

  Point(ll x = 0, ll y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(db a) { return Point(a * x, a * y); }
  Point operator/(ll a) { return Point(x / a, y / a); }

  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return abs(x - p.x) < eps && abs(y - p.y) < eps;
  }
};
struct Segment {
  Point p1, p2;
};
typedef Segment Line;
typedef Point Vector;
typedef vector<Point> Polygon;

il ll cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外积

il bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
il bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
il bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
il int dcmp(db x) {
  if (equals(x, 0.0))
    return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
il int ccw(Point p0, Point p1, Point p2) {
  Vector a = p1 - p0, b = p2 - p0;
  if (cross(a, b) > 0)
    return CCW;
  if (cross(a, b) < 0)
    return CW;
  return 0;
}

il bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
} // 不规范相交
il bool intersect(Segment s1, Segment s2) {
  return (intersect(s1.p1, s1.p2, s2.p1, s2.p2));
}

il Point getCrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  ll d1 = abs(cross(base, s1.p1 - s2.p1));
  ll d2 = abs(cross(base, s1.p2 - s2.p1));
  db t = 1.0 * d1 / (d1 + d2);
  // cout << t << '\n';
  return s1.p1 + (s1.p2 - s1.p1) * t;
}

il Point getCrossPointLL(Line l1, Line l2) {
  if (abs(ccw(l1.p1, l1.p2, l2.p1)) != 1 && abs(ccw(l1.p1, l1.p2, l2.p2)) != 1) {
    return {LINF, LINF};
  }
  if (cross(l1.p2 - l1.p1, l2.p2 - l2.p1) == 0) {
    return {LINF, LINF};
  }
  if (intersect(l1, l2))
    return getCrossPoint(l1, l2);
  db x, y;
  ll a1 = cross(l1.p2 - l1.p1, l2.p1 - l1.p1),
     a2 = cross(l1.p2 - l1.p1, l2.p2 - l1.p1);
  x = (a2 * l2.p1.x - a1 * l2.p2.x) / (a2 - a1);
  y = (a2 * l2.p1.y - a1 * l2.p2.y) / (a2 - a1);
  return Point(x, y);
}


void solve() {
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    if (n == 1) {
        cout << "YES\n";
        cout << p[0].x << ' ' << p[0].y << '\n';
        return ;
    }
    vector<Line> l;
    l.pb(Line({{p[0].x, p[0].y}, {p[0].x + 1, p[0].y}}));
    l.pb(Line({{p[0].x, p[0].y}, {p[0].x, p[0].y + 1}}));
    l.pb(Line({{p[0].x, p[0].y}, {p[0].x + 1, p[0].y + 1}}));
    l.pb(Line({{p[0].x, p[0].y}, {p[0].x + 1, p[0].y - 1}}));
    l.pb(Line({{p[1].x, p[1].y}, {p[1].x + 1, p[1].y}}));
    l.pb(Line({{p[1].x, p[1].y}, {p[1].x, p[1].y + 1}}));
    l.pb(Line({{p[1].x, p[1].y}, {p[1].x + 1, p[1].y + 1}}));
    l.pb(Line({{p[1].x, p[1].y}, {p[1].x + 1, p[1].y - 1}}));
    for (int k = 0; k < 4; ++k) {
        for (int j = 4; j < 8; ++j) {
            Point cr = getCrossPointLL(l[k], l[j]);
            if (cr.x == LINF && cr.y == LINF) continue;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (cr.x == p[i].x || cr.y == p[i].y || abs(cr.x - p[i].x) == abs(cr.y - p[i].y)) {
                    cnt++;
                }
            }
            if (cnt == n) {
                cout << "YES\n";
                cout << cr.x << ' ' << cr.y << '\n';
                return ;
            }
        }
    }
    // for (int i = 0; i < 4; ++i) {
    //   for (int j = 0; j < 8; ++j) {
    //     if (abs(ccw(l[i].p1, l[i].p2, l[j].p1)) != 1 && abs(ccw(l[i].p1, l[i].p2, l[j].p2)) != 1) {
    //       if (n == 2) {
    //         cout << "YES\n";
    //         cout << p[0].x << ' ' << p[0].y << '\n';
    //         return ;
    //       }
    //       if (abs(ccw(l[i].p1, l[i].p2, l[j].p1)) != 1 && abs(ccw(l[i].p1, l[i].p2, l[j].p2)) != 1)
    //     }
    //   }
    // }
    for (int j = 0; j < 4; ++j) {
      bool f = 1;
      for (int i = 1; i < n; ++i) {
        if (abs(ccw(l[j].p1, l[j].p2, p[i])) == 1) {
          f = 0;
          break;
        }
      }
      if (f) {
        cout << "YES\n";
        cout << p[0].x << ' ' << p[0].y << '\n';
        return ;
      }
    }
    cout << "NO\n";
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
