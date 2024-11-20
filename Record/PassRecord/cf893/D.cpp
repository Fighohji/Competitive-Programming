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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    #define arr vector<vector<array<int, 2>>> 
    arr pre(n + 2, vector<array<int, 2>> (k + 1)), suf(n + 2, vector<array<int, 2>> (k + 1));
    auto get = [&](arr &dp) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                for (auto op : {0, 1}) {
                    if (s[i - 1] == '0' + op) {
                        dp[i][j][op] = max(dp[i][j][op], dp[i - 1][j][op] + 1);
                    } else {
                        if (j + 1 <= k) dp[i][j + 1][op] = max(dp[i][j + 1][op], dp[i - 1][j][op] + 1);
                    }
                }
            }
        }  
    };
    get(pre);
    reverse(all(s));
    get(suf);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (auto op : {0, 1}) {
                pre[i][j][op] = max(pre[i - 1][j][op], pre[i][j][op]);
                suf[i][j][op] = max(suf[i - 1][j][op], suf[i][j][op]);
            }
        }
    }
    vector<int> f(n + 1, -INF);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // cerr << pre[i][j][1] << ' ' << suf[i][j][1] << '\n';
            f[pre[i][j][0]] = max(f[pre[i][j][0]], suf[n - i][k - j][1]);
            f[suf[i][j][0]] = max(f[suf[i][j][0]], pre[n - i][k - j][1]);
        }
    }
    // cout << f[0] << '\n';
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (f[j] >= 0) ans[i] = max(ans[i], j * i + f[j]);
        }
        cout << ans[i] << " \n"[i == n];
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
