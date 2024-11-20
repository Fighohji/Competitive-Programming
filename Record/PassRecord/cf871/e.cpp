#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <cstdio>
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

bool BEGIN;

int a[1005][1005];
int vis[1005][1005];
int n, m;
int id;
void dfs(int x, int y, int sum) {
    if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || !a[x][y]) return ;
    vis[x][y] = sum;
    for (int i = 0; i < 8; i += 2) {
        dfs(x + dir[i][0], y + dir[i][1], sum);
    }
}

int sum[1005 * 1005];

void solve(int cas) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            vis[i][j] = 0;
            sum[(i - 1) * m + j] = 0;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j] || !a[i][j]) continue;
            dfs(i, j, (i - 1) * m + j);
        }
    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[vis[i][j]] += a[i][j];
        }
    } 
    cout << *max_element(sum + 1, sum + 1 + n * m) << '\n';
}


bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
