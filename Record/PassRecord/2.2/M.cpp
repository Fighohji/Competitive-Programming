#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define db           double
#define fir          first
#define sec          second
#define eps          (1e-8)
#define pb           push_back
#define ll           long long
#define mkp          make_pair
#define eb           emplace_back
#define pii          pair<int, int>
#define lowbit(a)    (a & (-a))
#define SZ(a)        ((int)a.size())
#define ull          unsigned long long
#define all(a)       a.begin(), a.end()
#define split        cout << "=========\n";
#define pll          pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1,  0, 1,  1,  1,
                           1,  0, 1,  -1, 0, -1, -1, -1};

void solve() {
    int n;
    cin >> n;
    int Ans = n / 6;
    if (n % 6) Ans += n / 6;
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
