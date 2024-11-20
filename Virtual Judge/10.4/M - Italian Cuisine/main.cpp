#include <climits>
#include <iostream>
#include <random>
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

#define int long long
class Point {
  public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(int a) { return Point(a * x, a * y); }
    Point operator/(int a) { return Point(x / a, y / a); }

    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const { return x == p.x && y == p.y; }
};
class Circle {
  public:
    Point c;
    int r;
    Circle(Point c = Point(), int r = 0.0) : c(c), r(r){};
};
typedef Point Vector;
int norm(Point c) { return c.x * c.x + c.y * c.y; }
int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; } // 外积
int valid(Point p1, Point p2, Point p, int r) {
    return (__int128)cross(p2 - p1, p - p1) * cross(p2 - p1, p - p1) >=
           (__int128)r * r * norm(p2 - p1);
}
void solve() {
    int n;
    cin >> n;
    Circle cir;
    cin >> cir.c.x >> cir.c.y >> cir.r;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    int area = 0;
    int Ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (valid(p[i], p[(j + 1) % n], cir.c, cir.r) && cross(p[(j + 1) % n] - p[i], cir.c - p[i]) > 0) {
            area -= cross(p[(j + 1) % n], p[j]);
            j = (j + 1) % n;
        }
        // cerr << i << ' ' << j << ' ' << area << ' ' << area - cross(p[i], p[j]) << '\n';
        Ans = max(Ans, area - cross(p[i], p[j]));
        area -= cross(p[i], p[(i + 1) % n]);
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
