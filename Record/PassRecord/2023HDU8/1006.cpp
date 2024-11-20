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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e7 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
void z_function(string &s, int *z) {
  int n = (int)s.length();
  for (int i = 0; i <= n; ++i) z[i] = 0;
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
}
int z[2][maxn];

int nxt[maxn];
int f[maxn];
int ocr[maxn];
il void getNxt(string s) {
    s = "~" + s;
    int n = SZ(s) - 1;
    for (int i = 1; i <= n; ++i) nxt[i] = 0;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}
il void getF(string s, string t, int *ocr) {
    s = "~" + s, t = "~" + t;
    int n = SZ(s) - 1, m = SZ(t) - 1;
    for (int i = 1, j = 0; i <= m; ++i) {
        ocr[i] = ocr[i - 1];
        while (j && (j == n || t[i] != s[j + 1])) j = nxt[j];
        if (t[i] == s[j + 1]) j++;
        f[i] = j;
        if (f[i] == n) {
            ocr[i]++;
        }
    }
}


string t1, revt1, t2, s, Z, revZ, revs;
void solve(int cas) {
    cin >> t1 >> t2 >> s;
    revs = s; reverse(all(revs));
    Z = t1 + "@" + s;
    revt1 = t1; reverse(all(revt1));
    revZ = revt1 + "@" + revs;
    getNxt(t2);
    getF(t2, s, ocr);
    z_function(Z, z[0]);
    z_function(revZ, z[1]);
    int m1 = t1.length(), m2 = t2.length(), n = s.length();
    ll ans = 0;
    for (int l = 0, r = m1 + m2 - 1; r < n; l++, r++) {
        int prelcp = z[0][m1 + 1 + l];
        int suflcp = z[1][m1 + n - r];
        if (prelcp + suflcp < m1) continue;
        ans += ocr[min(l + prelcp + m2 - 1, r) + 1] - ocr[max(l, r - suflcp - m2 + 1) - 1 + m2];
    }
    cout << ans << '\n';
}

/*
3
abab ab
abababab
ab a
aaabbaabaa
aba ab
ababaabbabaab
*/

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
