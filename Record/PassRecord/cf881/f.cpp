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

struct node {
    int sum, lmx, rmx, mx, mn, lmn, rmn;
    node () { sum = lmx = rmx = mx = mn = lmn = rmn = 0; }
} seg[maxn << 2];

struct Query {
    int u, v, k;
} qr[maxn];

vector<int> e[maxn];
int idx;
int a[maxn];
int tot, top[maxn], dfn[maxn], id[maxn], sz[maxn], dep[maxn], fa[maxn], son[maxn];

void dfs1(int u, int p) {
    dep[u] = dep[p] + 1;
    fa[u] = p; sz[u] = 1;
    for (auto v : e[u]) {
        if (v != p) {
            dfs1(v, u);
            sz[u] += sz[v];
            if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
        }
    }
}

void dfs2(int u, int p) {
    dfn[u] = ++tot;
    id[tot] = u;
    top[u] = p;
    if (!son[u]) return ;
    dfs2(son[u], p);
    for (auto v : e[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

node push_up(node x, node y) {
    node ans;
    ans.sum = x.sum + y.sum;
    ans.lmx = max(x.lmx, x.sum + y.lmx);
    ans.rmx = max(y.rmx, y.sum + x.rmx);
    ans.mx = max(max(x.mx, y.mx), x.rmx + y.lmx);
    ans.lmn = min(x.lmn, x.sum + y.lmn);
    ans.rmn = min(y.rmn, y.sum + x.rmn);
    ans.mn = min(min(x.mn, y.mn), x.rmn + y.lmn);
    return ans;
}

void build(int p, int l, int r) {
    if (l == r) {
        seg[p].sum = a[id[l]];
        seg[p].lmn = seg[p].rmn = seg[p].mn = seg[p].sum;
        seg[p].lmx = seg[p].rmx = seg[p].mx = seg[p].sum;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    seg[p] = push_up(seg[p << 1], seg[p << 1 | 1]);
}

node query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[p];
    int mid = l + r >> 1;
    node L, R;
    if (ql <= mid) L = query(p << 1, l, mid, ql, qr);
    if (mid < qr) R = query(p << 1 | 1, mid + 1, r, ql, qr);
    return push_up(L, R);
}

node chainquery(int u, int v) {
    node L, R;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            R = push_up(query(1, 1, tot, dfn[top[v]], dfn[v]), R);
            v = fa[top[v]];
        } else {
            L = push_up(query(1, 1, tot, dfn[top[u]], dfn[u]), L);
            u = fa[top[u]];
        }
    }
    if (dep[u] > dep[v]) {
        L = push_up(query(1, 1, tot, dfn[v], dfn[u]), L);
    } else {
        R = push_up(query(1, 1, tot, dfn[u], dfn[v]), R);
    }
    swap(L.lmx, L.rmx);
    swap(L.lmn, L.rmn);
    return push_up(L, R);
}

void solve(int cas) {
    int n; cin >> n;
    idx = 1, tot = 0;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        sz[i] = son[i] = 0;
        a[i] = 0;
    }
    a[1] = 1;
    int cnt_q = 0;
    for (int i = 0; i < n; ++i) {
        string op; cin >> op;
        if (op == "+") {
            int x, val; cin >> x >> val;
            e[x].eb(++idx);
            a[idx] = val;
        } else {
            cin >> qr[++cnt_q].u >> qr[cnt_q].v >> qr[cnt_q].k;
        }
    }
    dfs1(1, 0); dfs2(1, 1);
    build(1, 1, tot);
    for (int i = 1; i <= cnt_q; ++i) {
        auto [u, v, k] = qr[i];
        if (k == 0) cout << "Yes\n";
        else {
            node ans = chainquery(u, v);
            if (k > 0 && ans.mx >= k || k < 0 && ans.mn <= k) {
                cout << "Yes\n";
            } else cout << "No\n";
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

