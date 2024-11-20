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


// #define int long long

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n), c, d;
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    int Max = 0, Min = 0;
    int suf = n - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (suf < 0) break;
        int l = 0, r = suf;
        int pos = -1;
        while (l <= r) {
            // cout << l << ' ' << r << '\n';
            int mid = l + r >> 1;
            // cout << "mid " << mid << '\n';
            if (a[i] > b[mid]) {
                l = mid + 1;
                pos = mid;
            } else r = mid - 1;
        }
        if (pos >= 0) {
            suf = pos - 1;
            Max++;
        }
        if (suf < 0) break;
    }
    int pre = 0;
    for (int i = 0; i < n; ++i) {
        if (pre >= n) break;
        int p = upper_bound(b.begin() + pre, b.end(), a[i]) - b.begin();
        if (p == n) break;
        pre = p + 1;
        Min++;
    }
    Min = n - Min;
    // cout << Min << ' ' << Max << '\n';
    cout << Max - Min + 1 << '\n';
    for (int i = Min; i <= Max; ++i)
        cout << i << ' ';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
