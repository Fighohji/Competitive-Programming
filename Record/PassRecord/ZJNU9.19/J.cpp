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
#define GG { cout << "NO\n"; return; }
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

bool BEGIN;

struct node {
    int op, x, y;
};

vector<pii> g[510][510];
int dis[505][505];
node pre[505][505];
void solve() {
    memset(dis, 0x3f, sizeof dis);
    int n, t; cin >> n >> t;
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    if (xs == xt && ys == yt) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return ;
    }
    for(int i = 1; i <= n; ++i) {
        int x, y; cin >> x >> y;
        for(int j = 0; j <= 100; ++j) {
            g[i + 100][i + 100].push_back({j, y});
            g[j][y].push_back({i + 100, i + 100});

            g[x][j].push_back({i + 100, i + 100});
            g[i + 100][i + 100].push_back({x, j});
        }
    }
    db ans = sqrt((xs - xt) * (xs - xt) + (ys - yt) * (ys - yt));
    queue<pii> q;
    q.push({xs, ys});
    dis[xs][ys] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (x <= 100 && y <= 100) {
            for (int _ = 0; _ < 8; _ += 2) {
                auto [ax, ay] = dir[_];
                int nx = ax + x, ny = ay + y;
                if (nx >= 0 && nx <= 100 && ny >= 0 && ny <= 100) {
                    if (dis[nx][ny] > dis[x][y] + 1) {
                        dis[nx][ny] = dis[x][y] + 1;
                        pre[nx][ny] = {0, x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }
        for (auto [id, _] : g[x][y]) {
            if (dis[id][id] > dis[x][y] + t) {
                dis[id][id] = dis[x][y] + t;
                for (auto [nx, ny] : g[id][id]) {
                    if (dis[nx][ny] > dis[id][id]) {
                        dis[nx][ny] = dis[id][id];
                        pre[nx][ny] = {id - 100, x, y};
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    if (ans < (db)dis[xt][yt]) {
        cout << ans << '\n';
        cout << 1 << '\n';
        cout << 0 << ' ' << xt << ' ' << yt << '\n';
        return ;
    }
    cout << dis[xt][yt] << '\n';
    vector<node> Ans;
    pii tmp = {xt, yt};
    while (xt != xs || yt != ys) {
        Ans.pb(pre[xt][yt]);
        auto [op, x, y] = pre[xt][yt];
        xt = x, yt = y;
    }
    reverse(all(Ans));
    cout << SZ(Ans) << '\n';
    auto [Op, _x, _y] = Ans[0];
    cout << Op << ' ';
    for (int i = 1; i < SZ(Ans); ++i) {
        auto [op, x, y] = Ans[i];
        cout << x << ' ' << y << '\n';
        cout << op << ' ';
    }
    cout << tmp.fir << ' ' << tmp.sec << '\n';
}


bool END;
signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
