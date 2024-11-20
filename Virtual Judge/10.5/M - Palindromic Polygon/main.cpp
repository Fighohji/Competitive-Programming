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
typedef Point Vector;
int norm(Point c) { return c.x * c.x + c.y * c.y; }
int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; } // 外积

void solve() {
    int n;
    cin >> n;
    vector<int> f(n << 1);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
        f[i + n] = f[i];
    }
    vector<Point> p(n << 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = p[i + n] = {x, y};
    }
    vector<vector<int>> dp(n << 1, vector<int>(n << 1, -LINF));
    int Ans = 0;
    auto clc = [&](int p1, int p2, int p3, int p4) -> int
    {
        return cross(p[p1], p[p2]) + cross(p[p2], p[p3]) + cross(p[p3], p[p4]) + cross(p[p4], p[p1]);
    };
    for(int i = 0; i < (n << 1); ++i) 
    {
        dp[i][i] = 0;
        if(i + 1 < (n << 1) && f[i] == f[i + 1]) dp[i][i + 1] = 0;
    }
    for(int len = 3; len <= n; ++len)
    {
        unordered_map<int, int> mp, mmp;
        mp[f[0]] = 1;
        mp[f[1]] = 2;
        for(int l = 0; l + len - 1 < (n << 1); ++l)
        {
            int r = l + len - 1;
            // cerr << l << ' ' << r << '\n';
            if(f[l] != f[r]) continue; 
            for(int pl = l + 1; pl < r; ++pl)
            {
                int pr = mp[f[pl]] - 1;
                if(l == 4 && r == 7)
                {
                    cout << "*** " << pl << ' ' << pr << '\n';
                }
                if(pr < 0 || pl > pr) continue;
                dp[l][r] = max(dp[l][r], dp[pl][pr] + clc(l, pl, pr, r));
            }
            Ans = max(Ans, dp[l][r]);
            mp[f[r]] = r + 1;

        }

        mmp[f[(n << 1) - 1]] = (n << 1);
        mmp[f[(n << 1) - 2]] = (n << 1) - 1;
        for(int r = (n << 1) - 1; r >= 0; --r)
        {
            int l = r - len + 1;
            if(l < 0) continue;
            // cerr << l << ' ' << r << '\n';
            if(f[l] != f[r]) continue;
            for(int pr = r - 1; pr > l; --pr)
            {
                int pl = mmp[f[pr]] - 1;
                // cerr << l << ' ' << r << ' ' << pl << ' ' << pr << '\n';
                if(pl < 0 || pl > pr)
                    continue;
                dp[l][r] = max(dp[l][r], dp[pl][pr] + clc(l, pl, pr, r));
            }
            mmp[f[l]] = l + 1;
            Ans = max(Ans, dp[l][r]);
        }

    }
    cout << dp[4][7] << '\n';
    cout << dp[3][9] << '\n';
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
