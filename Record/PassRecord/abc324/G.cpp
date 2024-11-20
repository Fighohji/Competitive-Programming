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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-10)
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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

int a[maxn], n;

int cnt[maxn << 5], ls[maxn << 5], rs[maxn << 5], root[maxn], idx;

#define mid (l + r >> 1)

void ins(int p, int &np, int l, int r, int pos) {
    np = ++idx;
    ls[np] = ls[p], rs[np] = rs[p], cnt[np] = cnt[p];
    cnt[np]++;
    if (l == r) return ;
    if (pos <= mid) ins(ls[p], ls[np], l, mid, pos);
    else ins(rs[p], rs[np], mid + 1, r, pos);
}
int rangeQuery(int p, int np, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return cnt[np] - cnt[p];
    int res = 0;
    if (ql <= mid) res += rangeQuery(ls[p], ls[np], l, mid, ql, qr);
    if (mid < qr) res += rangeQuery(rs[p], rs[np], mid + 1, r, ql, qr);
    return res;
}
int query(int l, int r, int mn, int mx) {
    if (l > r || mn > mx) return 0;
    // cout << l << ' ' << r << ' ' << mn << ' ' << mx << '\n';
    return rangeQuery(root[l - 1], root[r], 1, n, mn, mx);
}
int posQuery(int p, int np, int l, int r, int val) {
    if (l == r) return l;
    if (cnt[ls[np]] - cnt[ls[p]] < val) return posQuery(rs[p], rs[np], mid + 1, r, val - (cnt[ls[np]] - cnt[ls[p]]));
    return posQuery(ls[p], ls[np], l, mid, val);
}
#undef mid
int limL[maxn], limR[maxn], limMax[maxn], limMin[maxn];
void clear(int u) {
    limR[u] = 0, limL[u] = 1;
    limMax[u] = 0, limMin[u] = 1;
}
void copy(int u, int v) {
    limR[u] = limR[v], limL[u] = limL[v];
    limMin[u] = limMin[v], limMax[u] = limMax[v];
}
int p[maxn];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        ins(root[i - 1], root[i], 1, n, p[i]);
    limL[0] = 1, limR[0] = n;
    limMin[0] = 1, limMax[0] = n;
    int q; cin >> q;
    for (int i = 1; i <= q; ++i) {
        int op, s, x; cin >> op >> s >> x;
        x++;
        if (op == 1) {
            if (!limR[s]) {
                clear(i);
            } else if (x > 1) {
                int tot = query(limMin[s], limMax[s], limL[s], limR[s]);
                // cout << "tot is " << tot << '\n';
                if (tot < x) {
                    clear(i);
                } else {
                    int cnt = query(limMin[s], limMax[s], 1, limL[s] - 1);
                    // cout << x + cnt << ' ';
                    int pos = posQuery(root[limMin[s] - 1], root[limMax[s]], 1, n, x + cnt);
                    // cout << "pos is " << pos << '\n';
                    copy(i, s);
                    limR[s] = pos - 1;
                    limL[i] = pos;
                }
            } else {
                copy(i, s);
                clear(s);
            }
        } else {
            if (x > limMax[s]) {
                clear(i);
            } else if (x <= limMin[s]) {
                copy(i, s);
                clear(s);
            } else {
                copy(i, s);
                limMax[s] = x - 1;

                limMin[i] = x;
            }
        }
        cout << query(limMin[i], limMax[i], limL[i], limR[i]) << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    cerr << "abc";
    solve();
    return 0;
}
