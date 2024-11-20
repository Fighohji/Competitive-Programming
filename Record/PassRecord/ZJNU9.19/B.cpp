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

const int st = 4;
const int d1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int d2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool judge(int x) {
    if (x % 400 == 0 || x % 4 == 0 && x % 100 != 0) return 1;
    return 0;
}

void solve() {
    int y; cin >> y;
    int day = 3;
    int ans = 0;
    for (int i = 1970; i <= y; ++i) {
        ans = 0;
        bool f = judge(i);
        if (f) {
            for (int j = 1; j <= 12; ++j) {
                int now = 0;
                bool flag = 0;
                for (int k = 1; k <= d2[j]; ++k) {
                    day++;
                    if (!flag) now++;
                    if (day == 8 && flag) {
                        now++;
                    }
                    if (day == 8) day = 1;
                    flag = 1;
                }
                ans += now;
            }
        } else {
            for (int j = 1; j <= 12; ++j) {
                int now = 0;
                bool flag = 0;
                for (int k = 1; k <= d1[j]; ++k) {
                    day++;
                    if (!flag) now++;
                    if (day == 8 && flag) {
                        now++;
                    }
                    if (day == 8) day = 1;
                    flag = 1;
                }
                ans += now;
            }
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
