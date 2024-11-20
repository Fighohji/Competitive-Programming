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



void solve() {
    int n, m; cin >> n >> m;
    if (n == m) {
        cout << n + max(n - 2, 0) << '\n';
        for(int i = 1; i <= n; ++i) {
            cout << 1 << ' ' << i << '\n';
        }
        for (int i = 2; i < n; ++i) {
            cout << n << ' ' << i << '\n';
        }
    } else {
        vector<pii> ans;
        if (n > m) {
            int mid = (m + 1) / 2;
            int l = m + 1, r = n - m;
            for (int i = m, p = m - 2; p > 0; i--, p -= 2) {
                l = i;
            }
            for (int i = n - m + 1, p = m - 2; p > 0; i++, p -= 2) {
                r = i;
            }
            if (m % 2) {
                for (int i = l; i <= r; ++i) {
                    ans.eb(i, mid);
                }
            } else {
                for (int i = l; i <= r; i += 2) {
                    ans.eb(i, mid);
                    ans.eb(i, mid + 1);
                }
            }
            for (int i = 1; i <= m; ++i) {
                ans.eb(1, i);
                ans.eb(n, i);
            }
            cout << SZ(ans) << '\n';
            for (auto [x, y] : ans) {
                cout << x << ' ' << y << '\n';
            }
        } else {
            int mid = (n + 1) / 2;
            int l = n + 1, r = m - n;
            for (int i = n, p = n - 2; p > 0; i--, p -= 2) {
                l = i;
            }
            for (int i = m - n + 1, p = n - 2; p > 0; i++, p -= 2) {
                r = i;
            }
            if (n % 2) {
                for (int i = l; i <= r; ++i) {
                    ans.eb(mid, i);
                }
            } else {
                for (int i = l; i <= r; i += 2) {
                    ans.eb(mid, i);
                    ans.eb(mid + 1, i);
                }
            }
            for (int i = 1; i <= n; ++i) {
                ans.eb(i, 1);
                ans.eb(i, m);
            }
            cout << SZ(ans) << '\n';
            for (auto [x, y] : ans) {
                cout << x << ' ' << y << '\n';
            }
        }
    }
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
