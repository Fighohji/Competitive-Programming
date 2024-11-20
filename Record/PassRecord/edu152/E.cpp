// Author: wsyear
// Problem: E. Max to the Right of Min
// Contest: Codeforces - Educational Codeforces Round 152 (Rated for Div. 2)
// Memory Limit: 256 MB
// Time Limit: 3000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#ifdef dbg
#define D(...) fprintf(stderr, __VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ " = "), debug_helper::debug(__VA_ARGS__), D("\n")
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define gc getchar
#define pc putchar
using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;

template <class T = int> T read() {
  T x = 0; bool f = 0; char ch = gc();
  while (!isdigit(ch)) f = ch == '-', ch = gc();
  while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
  return f ? -x: x;
}
template <class T> void write(T x) {
  if (x >= 0) { if (x > 9) write(x / 10); pc(x % 10 + 48); }
  else { pc('-'); if (x < -9) write(-x / 10); pc(48 - x % 10); }
}

const int N = 1000010;

int n, a[N], mn[N << 2], mx[N << 2], pos[N];
ll ans;

#define mid ((l + r) >> 1)

void build(int c, int l, int r) {
  if (l == r) return mn[c] = mx[c] = a[l], void();
  build(c << 1, l, mid), build(c << 1 | 1, mid + 1, r);
  mn[c] = min(mn[c << 1], mn[c << 1 | 1]);
  mx[c] = max(mx[c << 1], mx[c << 1 | 1]);
}

int qry(int c, int l, int r, int x, int y) {
  if (l == x && r == y) return mn[c];
  if (y <= mid) return qry(c << 1, l, mid, x, y);
  else if (x > mid) return qry(c << 1 | 1, mid + 1, r, x, y);
  else return min(qry(c << 1, l, mid, x, mid), qry(c << 1 | 1, mid + 1, r, mid + 1, y));
}

int find1(int c, int l, int r, int x, int v) {
  // min pos that pos >= x && a[pos] > v
  if (r < x || mx[c] <= v) return n + 1;
  if (l == r) return l;
  int res = find1(c << 1, l, mid, x, v);
  if (res != n + 1) return res;
  return find1(c << 1 | 1, mid + 1, r, x, v);
}

int find2(int c, int l, int r, int x, int v) {
  // max pos that pos <= x && a[pos] > v
  if (l > x || mx[c] <= v) return 0;
  if (l == r) return l;
  int res = find2(c << 1 | 1, mid + 1, r, x, v);
  if (res != 0) return res;
  return find2(c << 1, l, mid, x, v);
}

#undef mid

void solve(int l, int r) {
  if (l == r) return;
  int mid = pos[qry(1, 1, n, l, r)];
  if (mid - l <= r - mid) {
    int mx = 0;
    per (i, mid, l) {
      mx = max(mx, a[i]);
      int pos = find1(1, 1, n, mid, mx);
      if (pos <= r) ans += r - pos + 1;
    }
  } else {
    int mx = 0;
    rep (i, mid, r) {
      mx = max(mx, a[i]);
      if (mx <= a[mid]) continue;
      int pos = find2(1, 1, n, mid, mx);
      pos = max(pos, l - 1);
      ans += mid - pos;
    }
  }
  if (l < mid) solve(l, mid - 1);
  if (r > mid) solve(mid + 1, r);
}

int main() {
  n = read();
  rep (i, 1, n) a[i] = read(), pos[a[i]] = i;
  build(1, 1, n), solve(1, n), write(ans), pc(10);
}
