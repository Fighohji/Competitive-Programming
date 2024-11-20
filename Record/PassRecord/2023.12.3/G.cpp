
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



void FWTor(vector<ll> &a, bool rev) {
    int n = a.size();
    for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
        for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
            if (!rev) a[i + j + m] += a[i + j];
            else a[i + j + m] -= a[i + j];
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<ll> r(1 << n), b(1 << n);
    for(auto &x : r) cin >> x;
    for(auto &x : b) cin >> x;
    FWTor(r, 0);
    FWTor(b, 0);
    vector<ll> dp(1 << n);
    dp[0] = min(b[0], r[0]);
    for(int i = 1; i < (1 << n); ++i)
    {
        dp[i] = b[i];
        for(int j = 0; j < n; ++j)
        {
            if((i >> j) & 1)
            {
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + r[i] - r[i ^ (1 << j)]);
                dp[i] = min(dp[i], dp[i ^ (1 << j)] + b[i] - b[i ^ (1 << j)]);
            }
        }

    }
    // for(int i = 0 ; i < (1 << n); ++i)
    //     cout << i << ' ' << dp[i] << ' ' << r[i] << ' ' << b[i] << '\n';
    cout << dp[(1 << n) - 1];
}
/*
2
-5 9 9 -5
10 -8 -6 3

3
-15 19 19 -5 30 -3 -16 13
29 -6 -14 -7 24 -5 18 11

*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
