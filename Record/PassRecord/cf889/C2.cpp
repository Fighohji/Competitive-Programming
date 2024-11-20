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
#include <utility>
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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


void solve(int cas) {
  int n;
  cin >> n;
  vector<pll> vec;
  vector<int> a(n + 2);
  bool f = 0;
  int MAX = 1;
  int MIN = 1;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0)
      cnt1++;
    if (a[i] > 0)
      cnt2++;
    if (a[i] > a[MAX])
      MAX = i;
    if (a[i] < a[MIN])
      MIN = i;
  }
  if (a[MAX] <= 0) {
    for (int i = n; i > 1; i--) {
      vec.push_back(mkp(i - 1, i));
    }
  } else if (a[MIN] >= 0) {
    for (int i = 2; i <= n; i++) {
      vec.push_back(mkp(i, i - 1));
    }
  } else {
    if (cnt1 <= 12 && cnt2 <= 12) {
      int a1 = a[MAX];
      int a2 = a[MIN];
      if (a1 >= -a2) {
        for (int i = 1; i <= n; i++) {
          if (a[i] < 0) {
            a[i] += a[MAX];
            vec.push_back(mkp(i, MAX));
          }
        }
        for (int i = 2; i <= n; i++) {
          vec.push_back(mkp(i, i - 1));
        }
      } else {
        for (int i = 1; i <= n; i++) {
          if (a[i] > 0) {
            a[i] += a[MIN];
            vec.push_back(mkp(i, MIN));
          }
        }
        for (int i = n; i > 1; i--) {
          vec.push_back(mkp(i - 1, i));
        }
      }
    } else {
      if (cnt1 <= 12) {
        while (a[MAX] < 20) {
          vec.push_back(mkp(MAX, MAX));
          a[MAX] *= 2;
        }
        for (int i = 1; i <= n; i++) {
          if (a[i] < 0) {
            a[i] += a[MAX];
            vec.push_back(mkp(i, MAX));
          }
        }
        for (int i = 2; i <= n; i++) {
          vec.push_back(mkp(i, i - 1));
        }
      } else {
        while (a[MIN] > -20) {
          vec.push_back(mkp(MIN, MIN));
          a[MIN] *= 2;
        }
        for (int i = 1; i <= n; i++) {
          if (a[i] > 0) {
            a[i] += a[MIN];
            vec.push_back(mkp(i, MIN));
          }
        }
        for (int i = n; i > 1; i--) {
          vec.push_back(mkp(i - 1, i));
        }
      }
    }
  }
  cout << vec.size() << '\n';
  for (auto i : vec) {
    cout << i.first << ' ' << i.second << '\n';
  }
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
