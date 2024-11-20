#include <cstdlib>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define int long long

void solve() {
    int n, c; cin >> n >> c;
    vector<int> d(n << 1), pre(n << 1);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        pre[i] = pre[i - 1] + d[i - 1];
    }
    vector<array<int, 21>> fa(n), dis(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 21; ++j)
            fa[i][j] = n, dis[i][j] = INF;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i + n - 1;
        int pos = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (pre[mid + 1] - pre[i] >= c) {
                pos = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if (pos != -1) {
            fa[i][0] = (pos + 1) % n;
            dis[i][0] = pos + 1 - i;
        }
    }
    for (int j = 1; j < 21; ++j)
        for (int i = 0; i < n; ++i) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            dis[i][j] = dis[i][j - 1] + dis[fa[i][j - 1]][j - 1];
        }
    for (int i = 0; i < n; ++i) {
        int Ans = 0, now = 0;
        int u = i;
        for (int j = 20; j >= 0; --j) {
            if (dis[u][j] + now < n) {
                Ans += (1 << j);
                now += dis[u][j];
                u = fa[u][j];
            }
        }
        cout << Ans << ' ';
    }
    cout << '\n';
}

signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
