
#include <locale>
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

void solve() {
    int n, m, s; cin >> n >> m >> s;
    map<pii, int> edge;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edge[{u, v}]++;
    }
    vector<int> e(1 << n);
    for (int i = 1; i < (1 << n); ++i) {
        for (auto [x, y] : edge) {
            int a = x.fir - 1, b = x.sec - 1;
            if (((1 << a) & i) && ((1 << b) & i)) {
                e[i] += y;
            }
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(s + 1));
    vector<vector<pair<int, int>>> pre(1 << n, vector<pair<int,int>>(s + 1));
    for(int i = 0; i < (1 << n); ++i)
    {
        int cnt = 0;
        for(int j = 0; j < n; ++j)
        {
            if((i >> j) & 1)
            {
                cnt++;
                for(int ps = 0; ps <= s; ++ps)
                {
                    if(dp[i][ps] < dp[i ^ (1 << j)][ps])
                    {
                        dp[i][ps] = dp[i ^ (1 << j)][ps];
                        pre[i][ps] = make_pair(i ^ (1 << j), ps);
                    }

                }
            }
        }
        for(int ps = cnt; ps <= s; ++ps)
        {
            if(dp[i][ps] < dp[i][ps - cnt] + e[i])
            {
                dp[i][ps] = dp[i][ps - cnt] + e[i];
                pre[i][ps] = {i, ps - cnt};
            }
        }
    }
    // cout << dp[(1 << n) - 1][s] << '\n';
    int x = (1 << n) - 1, y = s;
    vector<int> a(n);
    while(x)
    {
        int px = pre[x][y].fir, py = pre[x][y].sec;
        if(x == px)
        {
            for(int i = 0; i < n; ++i)
            {
                if((x >> i) & 1)
                {
                    a[i]++;
                }
            }
        }
        x = px, y = py;
    }
    int sum = 0;
    for(auto x : a) sum += x;
    a[0] += s - sum;
    for(auto x : a) cout << x << ' ';
}
/*
4 4 6
1 2
2 3
3 1
1 4

3 7 7
1 2
1 2
1 2
1 3
1 3
2 3
2 3
*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
