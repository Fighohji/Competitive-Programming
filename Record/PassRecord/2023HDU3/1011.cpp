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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

char ans[805][805];

void solve(int cas) {
    int n, z; cin >> n >> z;
    vector<string> mp(n + 1);
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; ++i) {
        cin >> mp[i];
        mp[i] = "~" + mp[i];
    }
    if (n * z % 100) {
        cout << "error\n";
        return ;
    }
    z = z * 4 / 100;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int nowx = (i - 1) * z + 1, nowy = (j - 1) * z + 1;
            for (int x = nowx; x < nowx + z; ++x) {
                for (int y = nowy; y < nowy + z; ++y) {
                    ans[x][y] = mp[i][j];
                }
            }
        }
    }
    // for (int i = 1; i <= n * z; ++i) {
    //     for (int j = 1; j <= n * z; ++j) {
    //         cout << ans[i][j];
    //     }
    //     cout << '\n';
    // }
    for (int i = 1; i <= n * z / 4; ++i) {
        for (int j = 1; j <= n * z / 4; ++j) {
            int nowx = (i - 1) * 4 + 1, nowy = (j - 1) * 4 + 1;
            set<char> tmp;
            // cout << nowx << ' ' << nowy << '\n';
            for (int x = nowx; x < nowx + 4; ++x) {
                for (int y = nowy; y < nowy + 4; ++y) {
                    tmp.insert(ans[x][y]);
                }
            }
            // for (auto p : tmp) cout << p << ' ';
            // cout << '\n';
            if (SZ(tmp) > 1) {
                cout << "error\n";
                return ;
            }
        }
    }
    for (int i = 1; i <= n * z / 4; ++i) {
        for (int j = 1; j <= n * z / 4; ++j) {
            int nowx = (i - 1) * 4 + 1, nowy = (j - 1) * 4 + 1;
            cout << ans[nowx][nowy];
        }
        cout << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
