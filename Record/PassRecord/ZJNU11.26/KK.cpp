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


int query(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    int h; cin >> h;
    cin >> h;
    return h;
}
int query2(int x, int y, int d, int dd)
{
    int maxx = x + d / 2, maxy = y + dd / 2;
    int h = 0;

}
void ck(int n)
{
    int tx = 1, ty = 1;
    int w = n, d = n;
    set<pair<int, int>> s;
    int h = query2(tx, ty, w, d);
}
void solve() {
    int n; cin >> n;
    int height = 0;
    int maxx, maxy;
    int x = 1, y = 1;

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
    ck(n);
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
