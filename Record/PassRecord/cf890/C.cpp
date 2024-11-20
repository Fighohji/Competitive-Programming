#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
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
#define int long long
int a[maxn], n, k, b[maxn];

bool check(int x) {
  for (int i = 1; i <= n; i++) {
    int res = k;
    for (int j = 1; j <= n; j++)
      b[j] = a[j];
    int flag = 0;
    for (int j = i; j <= n; j++) {
      int w = x - (j - i);
      if (b[j] >= w) {
        flag = 1;
        break;
      } else {
        res -= w - b[j];
      }
    }
    if (res >= 0 && flag) return 1;
  }
  return 0;
}
void solve(int cas) {
  cin >> n >> k;
  int l = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    l = max(l, a[i]);
  }
  int r = l + k;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l << '\n';
}

bool END;
signed main() {
  // cout << fixed << setprecision(10);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    solve(1);
  // cout << ((&END - & BEGIN) >> 21) << '\n';
  return 0;
}
