#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
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

#define int long long
constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1,  0, 1,  1,  1,
                           1,  0, 1,  -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

bool BEGIN;
bool vis[maxn];
int prime[maxn];
int cnt;
void isprime(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!vis[i])
      prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
      vis[i * prime[j]] = 1;
      if (i % prime[j] == 0)
        break;
    }
  }
}

struct Hash {
  ull seed = 114514, p;
  ull hash[maxn], power[maxn], pre[maxn];
  void init(string &s, ull P = UINT64_MAX) {
    p = P;
    power[0] = 1;
    for (int i = 1; i <= s.length(); ++i) {
      hash[i] = (hash[i - 1] * seed % p + s[i] - '0') % p;
      power[i] = power[i - 1] * seed % p;
      pre[i] = (pre[i - 1] + power[i]) % p;
    }
  }
  ull get_hash(int l, int r) {
    if (l > r)
      return 0ull;
    ull a = hash[r];
    ull b = hash[l - 1] * power[r - l + 1] % p;
    return ((a - b) % p + p) % p;
  }
};

Hash hs1, hs2;
void solve(int cas) {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  vector<bool> vis(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int res = 0;
  int l = 1, r = 0;
  bool flag1 = 0;
  bool flag2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      if (flag1) {
        if (!flag2) {
          flag1 = flag2 = 0;
          for (int j = l; j <= r; j++)
            vis[j] = 0;
        } else {
          vis[i] = 1;
          vis[l - 1] = 1;
          res++;
        }
      }
      flag1 = flag2 = 0;
    } else {
      if (a[i] == 2)
        flag2 = 1;
      if (!flag1)
        l = i;
      flag1 = 1;
      r = i;
      vis[i] = 1;
    }
  }
  if (flag1) {
    if (!flag2) {
      for (int i = l; i <= r; i++)
        vis[i] = 0;
    } else {
      vis[l - 1] = 1;
      res++;
    }
    flag1 = 0;
  }
  l = 1, r = 0;
  bool flag = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      if (!flag1)
        l = i;
      r = i;
      flag1 = 1;
      if (vis[i] == 1)
        flag = 1;
      vis[i] = 1;
    } else {
      if (!flag1)
        continue;
      else {
        if (l - 1 > 0 && vis[l - 1] == 0) {
          vis[l - 1] = 1;
        } else {
          vis[i] = 1;
        }
        flag1 = 0;
        if (!flag)
          res++;
        flag = 0;
      }
    }
  }
  if (flag1) {
    vis[l - 1] = 1;
    flag1 = 0;
    if (!flag)
      res++;
    flag = 0;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0)
      res++;
  }
  cout << res << '\n';
}

bool END;
signed main() {
  srand(time(nullptr));
  // cout << fixed << setprecision(10);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  isprime(5e3);
  // cerr << cnt << '\n';
  int T;
  // cin >> T;
  // while (T--) {
    solve(1);
  // }
  // cout << ((&END - & BEGIN) >> 21) << '\n';
  return 0;
}
