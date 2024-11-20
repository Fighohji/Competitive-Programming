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


struct po {
    int x, y;
};
struct Mat {
    int h, w;
    po ul, dl, ur, dr;
    po nxtul, nxtdl, nxtur, nxtdr;
    Mat (po a, po b, po c, po d) {
        ul = a, dl = b, ur = c, dr = d;
        nxtul = {ul.x - 1, ul.y - 1};
        nxtdl = {dl.x + 1, dl.y - 1};
        nxtur = {ur.x - 1, ur.y + 1};
        nxtdr = {dr.x + 1, dr.y + 1};
        h = dl.x - ul.x + 1;
        w = ur.y - ul.y + 1;
    }
};
int n;
bool check(po now) {
    return now.x >= 1 && now.x <= n && now.y >= 1 && now.y <= n;
}
struct Info {
    int x, y, h, w;
};
void solve() {
    int x, y;
    cin >> n >> x >> y;
    cout << "Yes\n";
    Mat now = Mat({x, y}, {x, y}, {x, y}, {x, y});
    vector<Info> Ans;
    while (1) {
        if (now.h == n && now.w == n) break;
        // cerr << now.h << ' ' << now.w << '\n';
        // cerr << now.ul.x << ' ' << now.ul.y << ' ' << now.dr.x << ' ' << now.dr.y << '\n';
        // cerr << now.nxtdr.x << ' ' << now.nxtdr.y << '\n';
        // cerr << now.nxtul.x << ' ' << now.nxtul.y << '\n';
        // cerr << now.nxtur.x << ' ' << now.nxtur.y << '\n';
        // cerr << now.nxtdl.x << ' ' << now.nxtdl.y << '\n';

        if (check(now.nxtul)) {
            Ans.eb(now.nxtul.x, now.nxtul.y, now.h, now.w);
            now = Mat(now.nxtul, {now.dl.x, now.dl.y - 1},
                      {now.ur.x - 1, now.ur.y}, now.dr);
            continue;
        }
        if (check(now.nxtdl)) {
            Ans.eb(now.nxtdl.x, now.nxtdl.y, -now.h, now.w);
            now = Mat({now.ul.x, now.ul.y - 1}, now.nxtdl,
                      now.ur, {now.dr.x + 1, now.dr.y});
            continue;
        }
        if (check(now.nxtur)) {
            Ans.eb(now.nxtur.x, now.nxtur.y, now.h, -now.w);
            now = Mat({now.ul.x - 1, now.ul.y}, now.dl,
                       now.nxtur, {now.dr.x, now.dr.y + 1});
            continue;
        }
        if (check(now.nxtdr)) {
            Ans.eb(now.nxtdr.x, now.nxtdr.y, -now.h, -now.w);
            now = Mat(now.ul, {now.dl.x + 1, now.dl.y},
                      {now.ur.x, now.ur.y + 1}, now.nxtdr);
            continue;
        }
    }
    cout << Ans.size() << '\n';
    for (auto [a, b, c, d] : Ans) {
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
