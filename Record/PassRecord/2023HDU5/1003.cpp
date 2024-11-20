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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int cnt; char s[maxn]; int len[maxn];//注意两倍空间
void manaqr() {
    cnt = 1;
    char c = getchar();
    s[0] = '~', s[cnt] = '|';
    while (c < 'a' || c > 'z') c = getchar();
    while (c >= 'a' && c <= 'z') s[++cnt] = c, s[++cnt] = '|', c = getchar();
    s[cnt + 1] = 0;
    for (int i = 1; i <= cnt; ++i) len[i] = 0;
}
void manacher() {
    manaqr();
    for (int t = 1, r = 0, mid = 0; t <= cnt; ++t) {//t是当前指针，r是当前最长回文右边界， mid是当前最长回文重心
        if (t <= r) len[t] = min(len[(mid<<1) - t] ,r - t + 1);
        while (s[t - len[t]] == s[t + len[t]]) ++len[t];
        if (len[t] + t > r) r = len[t] + t - 1, mid = t;
    }
}
int R[maxn];
int sum[maxn << 5], ls[maxn << 5], rs[maxn << 5], root[maxn << 5], idx;
void update(int &rtu, int rtv, int l, int r, int pos) {
    rtu = ++idx;
    ls[rtu] = ls[rtv], rs[rtu] = rs[rtv];
    sum[rtu] = sum[rtv] + 1;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (pos <= mid) update(ls[rtu], ls[rtv], l, mid, pos);
    else update(rs[rtu], rs[rtv], mid + 1, r, pos);
}
int query(int rtu, int rtv, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[rtv] - sum[rtu];
    int res = 0;
    int mid = l + r >> 1;
    if (ql <= mid) res += query(ls[rtu], ls[rtv], l, mid, ql, qr);
    if (mid < qr) res += query(rs[rtu], rs[rtv], mid + 1, r, ql, qr);
    return res;
}
void solve(int cas) {
    manacher();
    for (int i = 1; i <= idx; ++i) {
        sum[i] = ls[i] = rs[i] = root[i] = 0;
    }
    idx = 0;
    for (int i = 1; i <= cnt; ++i) {
        R[i] = i + len[i] - 1;
        update(root[i], root[i - 1], 1, cnt, R[i]);
    }
    ll ans = 0;
    for (int i = 3; i < cnt; i += 2) {
        int L = (i - len[i] + 2 + i) / 2;
        ans += query(root[L - 1], root[i - 1], 1, cnt, i, cnt);
    }
    printf("%d\n", ans);
    
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; scanf("%d", &T); while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}


