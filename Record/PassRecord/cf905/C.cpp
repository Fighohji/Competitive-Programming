#include <locale>
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 1e14;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct SegTree {
#define mid (l + r >> 1)
    ll Min[maxn], Max[maxn], lazy[maxn];
    int ls[maxn], rs[maxn], idx, root;
    void push(int p) {
        if (lazy[p]) {
            Min[ls[p]] += lazy[p];
            Min[rs[p]] += lazy[p];
            Max[ls[p]] += lazy[p];
            Max[rs[p]] += lazy[p];
            lazy[ls[p]] += lazy[p];
            lazy[rs[p]] += lazy[p];
            lazy[p] = 0;
        }
    }
    void clear() {
        for (int i = 1; i <= idx; ++i) {
            Max[i] = Min[i] = lazy[i] = ls[i] = rs[i] = 0;
        }
        idx = root = 0;
        Min[0] = LINF;
        Max[0] = -LINF;
    }
    void build(int &p, int l, int r) {
        p = ++idx;
        if (l == r) return ;
        build(ls[p], l, mid);
        build(rs[p], mid + 1, r);
    }
    void update(int p, int l, int r, int ql, int qr, int val) {
        if (!p) return ;
        if (ql <= l && r <= qr) {
            Min[p] += val;
            Max[p] += val;
            lazy[p] += val;
            return ;
        }
        push(p);
        if (ql <= mid) update(ls[p], l, mid, ql, qr, val);
        if (mid < qr) update(rs[p], mid + 1, r, ql, qr, val);
        Min[p] = min(Min[ls[p]], Min[rs[p]]);
        Max[p] = max(Max[ls[p]], Max[rs[p]]);
    }
    ll query() {
        return Min[root];
    }
    void del(int &p, ll val) {
        if (!p) return ;
        if (Max[p] <= val) return ;
        if (Min[p] > val) {
            p = 0;
            return ;
        }
        push(p);
        if (Max[ls[p]] > val) del(ls[p], val);
        if (Max[rs[p]] > val) del(rs[p], val);
        Min[p] = min(Min[ls[p]], Min[rs[p]]);
        Max[p] = max(Max[ls[p]], Max[rs[p]]);
    }
#undef mid
} seg;

struct node {
    int val, id;
};

void solve()  {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int q; cin >> q;
    seg.clear();
    seg.build(seg.root, 0, q);
    vector Q(n + 1, vector<node>());
    for (int i = 1; i <= q; ++i) {
        int l, r, val; cin >> l >> r >> val;
        Q[l].pb({val, i});
        if (r < n) Q[r + 1].pb({-val, i});
    }
    for (int i = 1; i <= n; ++i) {
        for (auto [val, id] : Q[i])
            seg.update(seg.root, 0, q, id, q, val);

       cout << a[i] + seg.query() << " \n"[i == n];
       seg.del(seg.root, seg.query());
    }
}
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
