#include <map>
#include <pthread.h>
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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

string s[2005], t[2005];
struct Hash {
    ull hs[2005][2005], power_x[2005], power_y[2005];
    void init(int n, int m, ull base_x, ull base_y, string *S) {
        power_x[0] = 1;
        for (int i = 1; i <= max(n, m); ++i)
            power_x[i] = power_x[i - 1] * base_x,
            power_y[i] = power_y[i - 1] * base_y;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                hs[i][j] = hs[i][j - 1] * base_x + S[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                hs[i][j] = hs[i - 1][j] * base_y + hs[i][j];
            }
        }
    }
    ull get(int x1, int y1, int x2, int y2) {
        return hs[x2][y2] - hs[x2][y1 - 1] * power_x[y2 - y1 + 1] - hs[x1 - 1][y2] * power_y[x2 - x1 + 1] - hs[x1 - 1][y1 - 1] * power_x[y2 - y1 + 1] * power_y[x2 - x1 + 1];
    }
};
Hash hs1, hs2;

void solve(int cas) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        t[n - i + 1] = s[i];
        reverse(all(t[n - i + 1]));
        s[i] = "~" + s[i];
        t[n - i + 1] = "~" + t[n - i + 1];
    } 
  
    hs1.init(n, m, 487, 233, s); hs2.init(n, m, 487, 233, t); 
    int ans = 0;
    auto check = [&](int a, int b, int c, int d) -> bool {
        ull h1 = hs1.get(a, b, c, d);  
        int na = n - c + 1, nb = m - d + 1, nc = n - a + 1, nd = m - b + 1;
        ull h2 = hs2.get(na, nb, nc, nd);
        return h1 == h2;
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int l = 1, r = min({n - i, i - 1, m - j, j - 1});
            int len = 0;
            while (l <= r) {
                int mid = l + r >> 1;
                if (check(i - mid, j - mid, i + mid, j + mid)) {
                    l = mid + 1;
                    len = mid;
                } else r = mid - 1;
            }
            ans += len + 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int a = i, b = j, c = i + 1, d = j + 1;
            int l = 0, r = min({n - c, i - 1, m - d, j - 1});
            int len = -1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (check(a - mid, b - mid, c + mid, d + mid)) {
                    l = mid + 1;
                    len = mid;
                } else r = mid - 1;
            }
            ans += len + 1;
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
