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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

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

class Point
{
    public:
    db x,y;

    Point(db x=0,db y=0):x(x),y(y) {}
    Point operator + (Point p){return Point(x+p.x,y+p.y); }
    Point operator - (Point p){return Point(x-p.x,y-p.y); }
    Point operator * (db a){return Point(a*x,a*y); }
    Point operator / (db a){return Point(x/a,y/a); }

    bool operator<(const Point &p)const{ return !equals(x,p.x) ? x<p.x : y<p.y; }
    bool operator==(const Point &p)const{ return fabs(x-p.x)<eps&&fabs(y-p.y)<eps; }
};
class Circle
{
    public:
    Point c;db r;
    Circle(Point c=Point(),db r=0.0):c(c),r(r){};
};
struct Segment
{
    Point p1,p2;
};
struct Triangle
{
    Point aa,bb,cc;
    Segment a,b,c;
    db alen,blen,clen;
    db A,B,C;
};
typedef Segment Line;
typedef Point Vector;
typedef vector<Point> Polygon;

il db norm(Point c) {return c.x*c.x+c.y*c.y;}
il db abs(Point c) {return sqrt(norm(c));}
il db abs(Segment a)
{
    Point k=a.p1-a.p2;
    return abs(k);
}
il db arg(Vector p) {return atan2(p.y,p.x); }//与x轴夹角
il Vector polar (db a,db r){return Point(cos(r)*a,sin(r)*a); }//求向量（与x轴夹角为a，长度为r的向量）
il db dot(Vector a,Vector b){ return a.x*b.x+a.y*b.y; }//内积
il db cross(Vector a, Vector b){ return a.x*b.y-a.y*b.x; }//外积
il bool isOrthogonal(Vector a,Vector b){return equals(dot(a,b),0.0);}
il bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){return isOrthogonal(a1-a2,b1-b2);}
il bool isOrthogonal(Segment s1,Segment s2){return equals(dot(s1.p1-s1.p2,s2.p1-s2.p2),0.0);}
il bool isParallel(Vector a,Vector b){return equals(cross(a,b),0.0);}
il bool isParallel(Point a1,Point a2,Point b1,Point b2){return isParallel(a1-a2,b1-b2);}
il bool isParallel(Segment s1,Segment s2){return equals(cross(s1.p1-s1.p2,s2.p1-s2.p2),0.0);}
il Vector getUnitVector(Vector p){return p/abs(p); }
il int dcmp(db x)
{
    if(equals(x,0.0))return 0;
    if(x<0)return -1;
    else return 1;
}
il int ccw(Point p0,Point p1,Point p2)
{
    Vector a=p1-p0,b=p2-p0;
    if(cross(a,b)>eps)return CCW;
    if(cross(a,b)<-eps)return CW;
    if(dot(a,b)<-eps)return BACK;
    if(norm(a)<norm(b))return FRONT;
    return ON;
}
il Point project(Segment s,Point p)
{
    Vector base=s.p2-s.p1;
    db r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}//投影终点所在坐标
il db projectlength(Segment s,Point p)
{
    Vector base=s.p2-s.p1;
    db r=dot(p-s.p1,base)/abs(base);
    return r;
}//投影长度
il Point reflect(Segment s,Point p){return p+(project(s,p)-p)*2.0;}//对称点坐标
il db getDistance(Point a,Point b){return abs(a-b);}

void solve() {
    Point P, A, B, O;
    cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;
    O = {0, 0};
    db ans = 12391203210381;
    ans = min(ans, max(getDistance(P, A), getDistance(O, A)));
    ans = min(ans, max(getDistance(P, B), getDistance(O, B)));
    ans = min(ans, max({getDistance(O, A), getDistance(P, B), getDistance(A, B) / 2}));
    ans = min(ans, max({getDistance(P, A), getDistance(O, B), getDistance(A, B) / 2}));
    cout << ans << '\n';
}

signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
