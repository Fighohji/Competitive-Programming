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

/*

case: k > 1
    li != l(i % k + 1)
    if a_li = i
    index = i的位置 只能被lj = i的项修改 修改成任意一个与lj不同的项
*/


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (k == 1) {
        vector<int> b(n + 1);
        iota(all(b), 0);
        if (a == b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i == a[i]) {
                cout << "NO\n";
                return ;
            }
        }

        vector<int> sz(n + 1), vis(n + 1);
        vector cir(n + 1, vector<int>());
        vector<int> las;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            int now = i;
            cnt++;
            while (!vis[now]) {
                cir[cnt].pb(now);
                vis[now] = 1;
                now = a[now];
                if (vis[now]) {
                    las.pb(now);
                }
            }
        }
        // cout << cnt << '\n';
        for (int i = 1; i <= cnt; ++i) {
            for (int j = 0; j < SZ(cir[i]); ++j) {
                if (las[i - 1] == cir[i][j]) {
                    int len = SZ(cir[i]) - j;
                    // cout << len << '\n';
                    if (len != k) {
                        cout << "NO\n";
                        return ;
                    }
                    break;
                }
            }
        }
        cout << "YES\n";
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
