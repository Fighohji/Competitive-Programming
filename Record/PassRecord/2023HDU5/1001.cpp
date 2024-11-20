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

#define N 10000010
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
constexpr int mod = 1e9 + 7; /* 998244353 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
bool BEGIN;

class Point {
public:
  db x, y;

  Point(db x = 0, db y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(db a) { return Point(a * x, a * y); }
  Point operator/(db a) { return Point(x / a, y / a); }

  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
  }
};
class Circle {
public:
  Point c;
  db r;
  Circle(Point c = Point(), db r = 0.0) : c(c), r(r){};
};
struct Segment {
  Point p1, p2;
};
struct Triangle {
  Point aa, bb, cc;
  Segment a, b, c;
  db alen, blen, clen;
  db A, B, C;
};
typedef Segment Line;
typedef Point Vector;
typedef vector<Point> Polygon;
il db mysqrt(db x) { return sqrt(max(0.0, x)); }
il db norm(Point c) { return c.x * c.x + c.y * c.y; }
il db abs(Point c) { return sqrt(norm(c)); }
il db abs(Segment a) {
  Point k = a.p1 - a.p2;
  return abs(k);
}
il db arg(Vector p) { return atan2(p.y, p.x); } // 与x轴夹角
il Vector polar(db a, db r) {
  return Point(cos(r) * a, sin(r) * a);
} // 求向量（与x轴夹角为a，长度为r的向量）
il db dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }   // 内积
il db cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外积
il bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
il bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}
il bool isOrthogonal(Segment s1, Segment s2) {
  return equals(dot(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
il bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
il bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
il bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
il Vector getUnitVector(Vector p) { return p / abs(p); }
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
  if (cross(a, b) > eps)
    return CCW;
  if (cross(a, b) < -eps)
    return CW;
  if (dot(a, b) < -eps)
    return BACK;
  if (norm(a) < norm(b))
    return FRONT;
  return ON;
}
il Point project(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  db r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
} // 投影终点所在坐标
il db projectlength(Segment s, Point p) {
  Vector base = s.p2 - s.p1;
  db r = dot(p - s.p1, base) / abs(base);
  return r;
} // 投影长度
il Point reflect(Segment s, Point p) {
  return p + (project(s, p) - p) * 2.0;
} // 对称点坐标
il db getDistance(Point a, Point b) { return abs(a - b); }
il db getDistanceLP(Line l, Point p) {
  return fabs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
il db getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0)
    return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0)
    return abs(p - s.p2);
  return getDistanceLP(s, p);
}
il bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
} // 不规范相交
il bool intersect(Segment s1, Segment s2) {
  return (intersect(s1.p1, s1.p2, s2.p1, s2.p2));
}
il db getDistanceSS(Segment s1, Segment s2) {
  if (intersect(s1, s2))
    return 0.0;
  return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
             min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
il Point getCrossPoint(Segment s1, Segment s2) {
  Vector base = s2.p2 - s2.p1;
  db d1 = fabs(cross(base, s1.p1 - s2.p1));
  db d2 = fabs(cross(base, s1.p2 - s2.p1));
  db t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
il Point getCrossPoint(Point p1, Point p2, Point p3, Point p4) {
  Segment s1, s2;
  s1.p1 = p1, s1.p2 = p2;
  s2.p1 = p3, s2.p2 = p4;
  return getCrossPoint(s1, s2);
}
il Point getCrossPointLL(Line l1, Line l2) {
  if (intersect(l1, l2))
    return getCrossPoint(l1, l2);
  db x, y;
  db a1 = cross(l1.p2 - l1.p1, l2.p1 - l1.p1),
     a2 = cross(l1.p2 - l1.p1, l2.p2 - l1.p1);
  x = (a2 * l2.p1.x - a1 * l2.p2.x) * 1.0 / (a2 - a1);
  y = (a2 * l2.p1.y - a1 * l2.p2.y) * 1.0 / (a2 - a1);
  return Point(x, y);
}
il pair<Point, Point> getCrossPoints(Circle c, Line l) {
  Vector pr = project(l, c.c);
  Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  db base = sqrt(c.r * c.r - norm(pr - c.c));
  return mkp(pr + e * base, pr - e * base);
}
il pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
  db d = abs(c1.c - c2.c);
  db a = acos((c1.r * c1.r + d * d - c2.r * c2.r) /
              ((db)2 * c1.r * d)); // 余弦定理求角度
  db t = arg(c2.c - c1.c);
  return mkp(c1.c + polar(c1.r, t - a), c1.c + polar(c1.r, t + a));
}

void solve(int cas) {
    int n, m; cin >> m >> n;
    vector<Segment> s(m + 1);
    vector<Point> p(n + 1), tmp(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> tmp[i].x >> tmp[i].y;
    }
    for (int i = 1; i < m; ++i) {
        s[i] = {tmp[i], tmp[i + 1]};
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    for (int i = 1; i <= n; ++i) {
        db ans = 1231239821412;
        for (int j = 1; j < m; ++j) {
            ans = min(ans, getDistanceSP(s[j], p[i]));
        }
        cout << ans << '\n';
    }
}

bool END;
signed main() {
    cout << fixed << setprecision(4);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
