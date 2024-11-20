#include <cstdint>
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int n;
struct node {
    ll a, b;
    bool operator<(const node &t) const {
        return b < t.b;
    }
} d[maxn];

int root[maxn], ls[maxn << 5], rs[maxn << 5], idx;
ll cnt[maxn << 5], sum[maxn << 5];
#define mid (l + r >> 1)
void ins(int p, int &np, int l, int r, int pos) {
    np = ++idx;
    cnt[np] = cnt[p], sum[np] = sum[p], ls[np] = ls[p], rs[np] = rs[p];
    cnt[np]++; sum[np] += pos;
    if (l == r) return ;
    if (pos <= mid) ins(ls[p], ls[np], l, mid, pos);
    else ins(rs[p], rs[np], mid + 1, r, pos);
}
ll query(int p, int l, int r, int kth) {
    if (cnt[p] == kth) return sum[p];
    if (l == r) return l * kth;
    if (cnt[ls[p]] < kth) return sum[ls[p]] + query(rs[p], mid + 1, r, kth - cnt[ls[p]]);
    else return query(ls[p], l, mid, kth);
}

ll Ans[maxn];

void Solve(int l, int r, int ql, int qr) {
    int pos = qr;
    if (l > r) return ;
    for (int i = ql; i <= qr; ++i) {
        if (i < mid) continue;
        ll res = d[i].b + d[i].a + query(root[i - 1], 1, 1000000000, mid - 1);
        if (res < Ans[mid]) {
            pos = i;
            Ans[mid] = res;
        }
    }
    if (l == r) return ;
    Solve(l, mid - 1, ql, pos); Solve(mid + 1, r, pos, qr);
}
#undef mid

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> d[i].a >> d[i].b;
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; ++i)
        ins(root[i - 1], root[i], 1, 1000000000, d[i].a);
    for (int i = 1; i <= n; ++i)
        Ans[i] = LINF;
    Solve(1, n, 1, n);
    for (int i = 1; i <= n; ++i)
        cout << Ans[i] << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
