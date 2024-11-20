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
#define endl '\n'

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
struct Segment {
  Point p1, p2;
};
typedef Segment Line;
typedef Point Vector;
typedef vector<Point> Polygon;
il db mysqrt(db x) { return sqrt(max(0.0, x)); }
il db norm(Point c) { return c.x * c.x + c.y * c.y; }
il db abs(Point c) { return mysqrt(norm(c)); }
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
void solve() {
    Point p;
    vector<Point> t(3);
    for (int i = 0; i < 3; ++i)
        cin >> t[i].x >> t[i].y;
    cin >> p.x >> p.y;

}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
