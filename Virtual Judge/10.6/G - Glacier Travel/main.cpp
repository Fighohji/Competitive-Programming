#include <climits>
#include <iomanip>
#include <ios>
#include <iostream>
#include <random>
#include <cmath>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

constexpr int CW = 1;
constexpr int CCW = -1;
constexpr int ON = 0;
constexpr int BACK = -2;
constexpr int FRONT = 2;
constexpr double eps = 1e-8;
#define equals(x, y) (fabs(x - y) < eps)
class Point {
  public:
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double a) { return Point(a * x, a * y); }
    Point operator/(double a) { return Point(x / a, y / a); }

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
    double r;
    Circle(Point c = Point(), double r = 0.0) : c(c), r(r){};
};
struct Segment {
    Point p1, p2;
};
typedef Segment Line;
typedef Point Vector;
typedef vector<Point> Polygon;

double norm(Point c) { return c.x * c.x + c.y * c.y; }
double abs(Point c) { return sqrt(norm(c)); }
double abs(Segment a) {
    Point k = a.p1 - a.p2;
    return abs(k);
}
double arg(Vector p) { return atan2(p.y, p.x); } // 与x轴夹角
Vector polar(double a, double r) {
    return Point(cos(r) * a, sin(r) * a);
} // 求向量（与x轴夹角为a，长度为r的向量）
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }   // 内积
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; } // 外积
bool isOrthogonal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
    return isOrthogonal(a1 - a2, b1 - b2);
}
bool isOrthogonal(Segment s1, Segment s2) {
    return equals(dot(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
    return isParallel(a1 - a2, b1 - b2);
}
bool isParallel(Segment s1, Segment s2) {
    return equals(cross(s1.p1 - s1.p2, s2.p1 - s2.p2), 0.0);
}
Vector getUnitVector(Vector p) { return p / abs(p); }
int dcmp(double x) {
    if (equals(x, 0.0)) return 0;
    if (x < 0)
        return -1;
    else
        return 1;
}
int ccw(Point p0, Point p1, Point p2) {
    Vector a = p1 - p0, b = p2 - p0;
    if (cross(a, b) > eps) return CCW;
    if (cross(a, b) < -eps) return CW;
    if (dot(a, b) < -eps) return BACK;
    if (norm(a) < norm(b)) return FRONT;
    return ON;
}
Point project(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / norm(base);
    return s.p1 + base * r;
} // 投影终点所在坐标
double projectlength(Segment s, Point p) {
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / abs(base);
    return r;
} // 投影长度
Point reflect(Segment s, Point p) {
    return p + (project(s, p) - p) * 2.0;
} // 对称点坐标
double getDistance(Point a, Point b) { return abs(a - b); }
double getDistanceLP(Line l, Point p) {
    return fabs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
double getDistanceSP(Segment s, Point p) {
    if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
    if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
    return getDistanceLP(s, p);
}
bool intersect(Point p1, Point p2, Point p3, Point p4) {
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0
            && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
} // 不规范相交
bool intersect(Segment s1, Segment s2) {
    return (intersect(s1.p1, s1.p2, s2.p1, s2.p2));
}
double getDistanceSS(Segment s1, Segment s2) {
    if (intersect(s1, s2)) return 0.0;
    return min(min(getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2)),
               min(getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)));
}
Point getCrossPoint(Segment s1, Segment s2) {
    Vector base = s2.p2 - s2.p1;
    double d1 = fabs(cross(base, s1.p1 - s2.p1));
    double d2 = fabs(cross(base, s1.p2 - s2.p1));
    double t = d1 / (d1 + d2);
    return s1.p1 + (s1.p2 - s1.p1) * t;
}
Point getCrossPoint(Point p1, Point p2, Point p3, Point p4) {
    Segment s1, s2;
    s1.p1 = p1, s1.p2 = p2;
    s2.p1 = p3, s2.p2 = p4;
    return getCrossPoint(s1, s2);
}
Point getCrossPointLL(Line l1, Line l2) {
    if (intersect(l1, l2)) return getCrossPoint(l1, l2);
    double x, y;
    double a1 = cross(l1.p2 - l1.p1, l2.p1 - l1.p1),
           a2 = cross(l1.p2 - l1.p1, l2.p2 - l1.p1);
    x = (a2 * l2.p1.x - a1 * l2.p2.x) * 1.0 / (a2 - a1);
    y = (a2 * l2.p1.y - a1 * l2.p2.y) * 1.0 / (a2 - a1);
    return Point(x, y);
}
pair<Point, Point> getCrossPoints(Circle c, Line l) {
    Vector pr = project(l, c.c);
    Vector e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
    double base = sqrt(c.r * c.r - norm(pr - c.c));
    return make_pair(pr + e * base, pr - e * base);
}
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
    double d = abs(c1.c - c2.c);
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r)
                    / ((double)2 * c1.r * d)); // 余弦定理求角度
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r, t - a), c1.c + polar(c1.r, t + a));
}
void solve() {
    double s;
    cin >> s;
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    vector<Segment> seg(n);
    for (int i = 1; i < n; ++i) {
        seg[i - 1] = {p[i - 1], p[i]};
    }
    int idx = 0;
    double tot = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (dcmp(abs(seg[i].p1 - seg[i].p2) + tot - s) >= 0) {
            idx = i;
            break;
        }
        tot += abs(seg[i].p1 - seg[i].p2);
    }
    Point x = p[0];
    Point y = seg[idx].p1 + getUnitVector(seg[idx].p2 - seg[idx].p1) * (s - tot);
    vector<Point> q;
    q.push_back(y);
    for (int i = idx; i < n - 1; ++i) {
        q.push_back(seg[i].p2);
    }
    int i = 0, j = 0;
    double Ans = getDistance(x, y);
    while (i + 1 < p.size() && j + 1 < q.size()) {
        if (dcmp(getDistance(x, p[i + 1]) - getDistance(y, q[j + 1])) >= 0) {
            double tim = getDistance(y, q[j + 1]);
            Vector vx = getUnitVector(p[i + 1] - x);
            Vector vy = getUnitVector(q[j + 1] - y);
            Vector v = vy - vx;
            Segment per = {y, v * tim + y};
            Ans = min(Ans, getDistanceSP(per, x));
            x = x + vx * tim;
            y = q[j + 1];
            j++;
        } else {
            double tim = getDistance(x, p[i + 1]);
            Vector vx = getUnitVector(p[i + 1] - x);
            Vector vy = getUnitVector(q[j + 1] - y);
            Vector v = vy - vx;
            Segment per = {y, v * tim + y};
            Ans = min(Ans, getDistanceSP(per, x));
            x = p[i + 1];
            y = y + vy * tim;
            i++;
        }
    }
    cout << Ans << '\n';
}

signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
