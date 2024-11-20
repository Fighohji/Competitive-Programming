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

unordered_map<string, bool> hs;
string s[maxn];
void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        // if ((s[i].length() + 1) * s[i].length() / 2 > n) continue;
        // hs[s[i]] = 1;
    }
    sort(s, s + n, [&](string &x, string &y){
        return x.length() < y.length();
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i].length() == 1) {
            hs[s[i]] = 1;
            ans = 1;
            continue;
        }
        if (hs.count(s[i].substr(0, (int)s[i].length() - 1)) &&
            hs.count(s[i].substr(1, (int)s[i].length() - 1))) {
            hs[s[i]] = 1;
            ans = s[i].length();
        }
    }
    cout << ans << '\n';
    // int ans = 0;
    // for (int i = 0; i < n; ++i) {
    //     if ((s[i].length() + 1) * s[i].length() / 2 > n) continue;
    //     bool flag = 1;
    //     for (int j = 0; j < s[i].length(); ++j) {
    //         for (int k = j; k < s[i].length(); ++k) {
    //             if (!hs.count(s[i].substr(j, k - j + 1))) {
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //         if (!flag) break;
    //     }
    //     if (flag) ans = max(ans, (int)s[i].length());
    // }
    // cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
