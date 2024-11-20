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
constexpr int maxn = 2e3 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 998244353 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)



void solve() {
    int n; cin >> n;
    int height = 0;
    int maxx, maxy;
    int x = 1, y = 1;
    set<pair<int, int>> s;
    uniform_int_distribution<ull> dist(1, n);
    if(n * n <= 10 * n + 100)
    {
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cout << "? " << i << ' ' << j << endl;
                int h; cin >> h;
                if(h > height)
                {
                    maxx = x, maxy = y;
                    height = h;
                }
            }
        }
        cout << "! " << height << endl;
        return ;
    }
    for(int i = 1; i <= 7 * n + 102; ++i)
    {
        x = dist(rnd), y = dist(rnd);
        if(s.count(make_pair(x, y)))
        {
            i--;
            continue;
        }
        cout << "? " << x << ' ' << y << endl;
        int h; cin >> h;
        s.insert(make_pair(x, y));
        if(h > height)
        {
            maxx = x, maxy = y;
            height = h;
        }
    }
    int nowx = maxx, nowy = maxy;
    int nxtx = maxx, nxty = maxy;
    while(1)
    {
        int f = 0;
        for(int i = 0; i < 8; i += 2)
        {
            int px = nowx + dir[i][0];
            int py = nowy + dir[i][1];
            if(px < 1 || py < 1 || px > n || py > n) continue;
            if(s.count(make_pair(px, py))) continue;
            cout << "? " << px << ' ' << py << endl;
            int h; cin >> h;
            s.insert(make_pair(px, py));
            if(h > height)
            {
                f = 1;
                nxtx = px, nxty = py;
                height = h;
            }
        }
        if(!f)
        {
            cout << "! " << height << endl;
            return ;
        }
        nowx = nxtx, nowy = nxty;
    }
    cout << "!!!!!!!\n";
}

signed main() {
    srand(time(0));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
