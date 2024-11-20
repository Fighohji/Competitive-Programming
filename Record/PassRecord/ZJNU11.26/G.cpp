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

  bool operator<(const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return x == p.x && y == p.y;
  }
};
struct Segment {
  Point p1, p2;
};
typedef Segment Line;
typedef Point Vector;
il ll norm(Point c) { return c.x * c.x + c.y * c.y; }
il ll dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }   // 内积
il ll cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外积
il bool isOrthogonal(Vector a, Vector b) { return dot(a, b) == 0; }
il bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}
il bool isOrthogonal(Segment s1, Segment s2) {
  return dot(s1.p1 - s1.p2, s2.p1 - s2.p2) == 0;
}
il bool isParallel(Vector a, Vector b) { return cross(a, b) == 0; }
il bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
il bool isParallel(Segment s1, Segment s2) {
  return cross(s1.p1 - s1.p2, s2.p1 - s2.p2) == 0;
}
void solve() {
    vector<Point> p(4);
    for (int i = 0; i < 4; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    vector<Line> l(4);
    for (int i = 0; i < 4; ++i) {
        l[i] = {p[i], p[(i + 1) % 4]};
    }
    if (norm(p[0] - p[1]) == norm(p[0] - p[3]) && norm(p[2] - p[1]) == norm(p[2] - p[3]) && norm(p[1] - p[0]) != norm(p[1] - p[2]) ||
        norm(p[1] - p[0]) == norm(p[1] - p[2]) && norm(p[3] - p[0]) == norm(p[3] - p[2]) && norm(p[0] - p[1]) != norm(p[0] - p[3])) {
        cout << "kite\n";
        return ;
    }
    int cnt = 0;
    for (int i = 0; i < 2; ++i) {
        if (isParallel(l[i], l[i + 2])) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "none\n";
        return ;
    }
    if (cnt == 1) {
        cout << "trapezium\n";
        return ;
    }
    if (norm(p[0] - p[1]) == norm(p[1] - p[2])) {
        if (isOrthogonal(l[0], l[1])) {
            cout << "square\n";
            return ;
        }
        cout << "rhombus\n";
    } else {
        if (isOrthogonal(l[0], l[1])) {
            cout << "rectangle\n";
            return ;
        }
        cout << "parallelogram\n";
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
