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


int sum, cnt, dep[maxn];
int Val[maxn];
int in[maxn], id[maxn], out[maxn], idx, son[maxn], sz[maxn], fa[maxn], top[maxn];
struct Seg {
#define mid ((l + r) >> 1)
#define ls (p << 1)
#define rs (ls + 1)
    int val[maxn << 2], lazy[maxn << 2];
    void push(int p, int l, int r) {
        if (lazy[p]) {
            val[ls] += (mid - l + 1) * lazy[p];
            val[rs] += (r - mid) * lazy[p];
            lazy[ls] += lazy[p];
            lazy[rs] += lazy[p];
            lazy[p] = 0;
        }
    }
    void update(int p, int l, int r, int ql, int qr, int w) {
        if (ql <= l && r <= qr) {
            val[p] += w * (r - l + 1);
            lazy[p] += w;
            return ;
        }
        push(p, l, r);
        if (ql <= mid) update(ls, l, mid, ql, qr, w);
        if (mid < qr) update(rs, mid + 1, r, ql, qr, w);
        val[p] = val[ls] + val[rs];
    }
    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return val[p];
        push(p, l, r);
        int res = 0;
        if (ql <= mid) res += query(ls, l, mid, ql, qr);
        if (mid < qr) res += query(rs, mid + 1, r, ql, qr);
        return res;
    }

#undef mid
#undef ls
#undef rs
} seg;


void upd(int u, int w) {
    while (top[u]) {
        seg.update(1, 1, idx, in[top[u]], in[u], w);
        u = fa[top[u]];
    }
}
int qry(int u) {
    int res = 0;
    while (top[u]) {
        res += seg.query(1, 1, idx, in[top[u]], in[u]);
        u = fa[top[u]];
    }
    return res;
}
vector<int> G[maxn];
void Clear(int n) {
    for (int i = 1; i <= 4 * n; ++i) {
        G[i].clear();
        dep[i] = 0;
        seg.val[i] = 0;
        seg.lazy[i] = 0;
        in[i] = out[i] = id[i] = 0;
        son[i] = sz[i] = 0;
        Val[i] = 0;
    }
    idx = sum = cnt = 0;
}
void dfs(int u, int p) {
    fa[u] = p;
    sz[u] = 1;
    dep[u] = dep[p] + 1;
    for (auto v : G[u])
        if (v != p) {
            dfs(v, u);
            sz[u] += sz[v];
            if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
        }
}
void DFS(int u, int p) {
        in[u] = ++idx;
        top[u] = p;
        if (son[u]) DFS(son[u], p);
        for (auto v : G[u]) {
            if (v == son[u] || v == fa[u]) continue;
            DFS(v, v);
        }
}
void solve() {
    int n, m; cin >> n >> m;
    Clear(n);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }


    dfs(1, 0); DFS(1, 1);
    while (m--) {
        int op, x, w;
        cin >> op;
        if (op == 1) {
            cin >> x >> w;
            cnt++;
            sum += dep[x] - w;
            upd(x, 2);
        } else if (op == 2) {
            cin >> x;
            int res = (Val[x] - cnt * dep[x] - sum + qry(x));
            Val[x] = res >= 0 ? cnt * dep[x] + sum - qry(x) : Val[x];
        } else {
            cin >> x;
            cout << (Val[x] - cnt * dep[x] - sum + qry(x)) << '\n';
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
