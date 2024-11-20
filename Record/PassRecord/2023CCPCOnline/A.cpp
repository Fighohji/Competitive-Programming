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
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T qpow(T base, ll power) {
    T res = 1;
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const { assert(x != 0); return qpow(*this, mod - 2); }
    mint &operator*=(const mint &rhs) { x = (ll)x * rhs.x % mod; return *this; }
    mint &operator+=(const mint &rhs) { x = norm(x + rhs.x); return *this; }
    mint &operator-=(const mint &rhs) { x = norm(x - rhs.x); return *this; }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) { mint res = lhs; res *= rhs; return res; }
    friend mint operator+(const mint &lhs, const mint &rhs) { mint res = lhs; res += rhs; return res; }
    friend mint operator-(const mint &lhs, const mint &rhs) { mint res = lhs; res -= rhs; return res; }
    friend mint operator/(const mint &lhs, const mint &rhs) { mint res = lhs; res /= rhs; return res; }
    friend std::istream &operator>>(std::istream &is, mint &a) { ll v; is >> v; a = mint(v); return is; }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) { return os << a.val(); }
};



int lg[maxn];
int sa[maxn], rk[maxn << 1], Lcp[maxn];
struct Tmp {
    int id, x, y;
} tmpa[maxn], tmpb[maxn];
int cnt[maxn];
int st[maxn][22];
void init_Sa(string &S) {
    int n = S.length();
    for (int i = 1; i <= n; i++) cnt[S[i - 1]] = 1;
    for (int i = 1; i <= 256; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; i++) rk[i] = cnt[S[i - 1]];
    for (int L = 1; L < n; L *= 2) {
          for (int i = 1; i <= n; i++) tmpa[i].id = i, tmpa[i].x = rk[i], tmpa[i].y = rk[i + L];
          for (int i = 1; i <= n; i++) cnt[i] = 0;
          for (int i = 1; i <= n; i++) cnt[tmpa[i].y]++;
          for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
          for (int i = n; i >= 1; i--) tmpb[cnt[tmpa[i].y]--] = tmpa[i];
          for (int i = 1; i <= n; i++) cnt[i] = 0;
          for (int i = 1; i <= n; i++) cnt[tmpa[i].x]++;
          for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
          for (int i = n; i >= 1; i--) tmpa[cnt[tmpb[i].x]--] = tmpb[i];
          for (int i = 1; i <= n; i++)
                if(tmpa[i].x == tmpa[i - 1].x && tmpa[i].y == tmpa[i - 1].y)
                    rk[tmpa[i].id] = rk[tmpa[i - 1].id];
                else rk[tmpa[i].id] = rk[tmpa[i - 1].id] + 1;
    }
    for (int i = 1; i <= n; i++) sa[rk[i]] = i; int k = 0;
    for (int i = 1; i <= n; i++) {
          if(k) k--;
          int j = sa[rk[i] - 1];
          while (i + k <= n && j + k <= n && S[i + k - 1] == S[j + k - 1]) k++;
          Lcp[rk[i]] = k;
    }
}
void build_st(int n) {
      lg[0] = -1; for (int i = 1; i <= n; i++) lg[i] = lg[i / 2] + 1; lg[0] = 0;
      for(int i = 1; i <= n; i++) st[i][0] = Lcp[i];
      for(int j = 1; (1 << j) <= n; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int query(int l, int r) {
      l = rk[l], r = rk[r];
      if(l > r) swap(l, r); l++;
      int k = lg[r - l + 1];
      return min(st[l][k], st[r - (1 << k) + 1][k]);
}

mint dp[maxn], g[maxn], f[maxn];
int nxt[maxn];
void solve() {
    string s, t; cin >> s >> t;
    string comb = s + "#" + t;
    int lens = s.length(), lent = t.length();
    init_Sa(comb);
    // build_lcp(comb);
    build_st(lens + lent + 1);

    for (int i = 1; i <= lens; ++i) {
        int lcp = query(i, lens + 2);
        int exlcp = 0;
        if (i + lcp + 1 <= lens && lens + 2 + lcp + 1 <= lens + lent + 1)
            exlcp = query(i + lcp + 1, lens + 2 + lcp + 1);
        int far = min(lens, i + min(lcp + 1 + exlcp, lent) - 1);
        nxt[i] = far;
    }
    g[lens + 1] = 1;
    for (int i = lens; i >= 1; --i) {
        int l = i + 1, r = nxt[i] + 1;
        g[i] = g[l] - g[r + 1];
        f[i] = f[l] - f[r + 1] + g[l] - g[r + 1];
        dp[i] = dp[l] - dp[r + 1] + mint(2) * (f[l] - f[r + 1]) + g[l] - g[r + 1];
        g[i] += g[i + 1];
        f[i] += f[i + 1];
        dp[i] += dp[i + 1];
    }
    cout << dp[1] - dp[2] << '\n';
}
/*
ababaab
aba
*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
