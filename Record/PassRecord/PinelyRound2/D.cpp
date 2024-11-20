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


void solve() {
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = "~" + s[i];
    }
    for (int i = 1; i <= n; ++i) {
        int cnt = count(all(s[i]), 'U') + count(all(s[i]), 'D');
        if (cnt % 2 == 1) {
            cout << "-1\n";
            return ;
        }
        bool f = 0;
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 'U' || s[i][j] == 'D') {
                if (s[i][j] == 'U') {
                    s[i + 1][j] = (f ? 'B' : 'W');
                }
                s[i][j] = (f ? 'W' : 'B');
                f ^= 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (s[j][i] == 'L' || s[j][i] == 'R')
                cnt++;
        }
        if (cnt % 2 == 1) {
            cout << "-1\n";
            return ;
        }
        bool f = 0;
        for (int j = 1; j <= n; ++j) {
            if (s[j][i] == 'L' || s[j][i] == 'R') {
                if (s[j][i] == 'L') {
                    s[j][i + 1] = (f ? 'B' : 'W');
                }
                s[j][i] = (f ? 'W' : 'B');
                f ^= 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << s[i].substr(1) << '\n';
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
