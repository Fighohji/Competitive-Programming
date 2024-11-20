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
#define GG                                                                     \
  {                                                                            \
    cout << "NO\n";                                                            \
    return;                                                                    \
  }
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
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1,  0, 1,  1,  1,
                           1,  0, 1,  -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

bool BEGIN;

void solve() {
  string s; cin >> s;
  int n = SZ(s);
  int cnt0 = count(all(s), '0');
  int cnt1 = n - cnt0;
  int nd = (n * (n - 1) / 2 - cnt0 * (cnt0 - 1) / 2 + cnt1 * (cnt1 - 1) / 2) / 2;
  vector dp(cnt1 + 1, vector<int>(nd + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = cnt1 - 1; j >= 0; --j) {
      for (int k = 0; k + i <= nd; ++k) {
        dp[j + 1][k + i] = min(dp[j + 1][k + i], dp[j][k] + (s[i] == '0'));
      }
    }
  }
  cout << dp[cnt1][nd] << '\n';
}

bool END;
signed main() {
  // cout << fixed << setprecision(10);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  // int T; cin >> T; while (T--)
  solve();
  // cout << ((&END - & BEGIN) >> 21) << '\n';
  return 0;
}
