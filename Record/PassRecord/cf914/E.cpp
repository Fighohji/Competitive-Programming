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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct SegTree {
#define mid (l + r >> 1)
#define ls (p << 1)
#define rs (p << 1 | 1)
    int Max[maxn << 2], lazy[maxn << 2];
    void pull(int p) {
        Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
    }
    void push(int p) {
        if (lazy[p]) {
            Max[ls] += lazy[p];
            Max[rs] += lazy[p];
            lazy[ls] += lazy[p];
            lazy[rs] += lazy[p];
            lazy[p] = 0;
        }
    }
    void build(int p, int l, int r, vector<int> &a) {
        if (l == r) {
            Max[p] = a[l];
            return ;
        }
        build(ls, l, mid, a);
        build(rs, mid + 1, r, a); 
        pull(p);
    }
    void updMax(int p, int l, int r, int ql, int qr, int w) {
        if (ql > qr) return;
        if (ql <= l && r <= qr) {
            Max[p] += w;
            lazy[p] += w;
            return ;
        }
        push(p);
        if (ql <= mid) updMax(ls, l, mid, ql, qr, w);
        if (mid < qr) updMax(rs, mid + 1, r, ql, qr, w);
        pull(p);
    }
    int qryMax(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return 0;
        if (ql <= l && r <= qr) {
            return Max[p];
        }
        push(p);
        int Ans = 0;
        if (ql <= mid) Ans = max(Ans, qryMax(ls, l, mid, ql, qr));
        if (mid < qr) Ans = max(Ans, qryMax(rs, mid + 1, r, ql, qr));
        return Ans;
    }
#undef mid
#undef ls
#undef rs
} T;

void solve() {
    int n, q; cin >> n >> q;
    vector G(n + 1, vector<int>());
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    int idx = 0;
    vector<int> in(n + 1), out(n + 1), dep(n + 1);
    dep[0] = -1;
    auto init = [&](auto &&init, int u, int p) -> void {
        in[u] = ++idx;
        dep[u] = dep[p] + 1;
        for (auto v : G[u]) {
            if (v == p)
                continue;
            init(init, v, u);
        }
        out[u] = idx;
    };
    init(init, 1, 0);
    vector<int> val(n + 1);
    for (int i = 1; i <= n; ++i) {
        val[in[i]] = dep[i];
    }
    vector<vector<pair<int, vector<int>>>> Q(n + 1);
    for (int i = 1; i <= q; ++i) {
        int x, k; cin >> x >> k;
        vector<int> node;
        for (int j = 1; j <= k; ++j) {
            int p; cin >> p;
            node.pb(p);
        }
        Q[x].pb({i, node});
    }
    T.build(1, 1, n, val);
    vector<int> Ans(q + 1), nxt(n + 1);
    auto dfs = [&](auto && dfs, int u, int p) -> void {
        for (auto &[x, vec] : Q[u]) {
            vector<pii> seg;
            bool flag = 0;
            for (auto j : vec) {
                if (j == u) {
                    flag = 1;
                    break;
                }
                if (in[u] >= in[j] && in[u] <= out[j]) {
                    seg.pb({1, in[nxt[j]] - 1});
                    seg.pb({out[nxt[j]] + 1, n}); 
                } else {
                    seg.pb({in[j], out[j]});
                }
            }
            if (!flag) {
                sort(all(seg));
                int pre = 0;
                for (auto [l, r] : seg) {
                    if (l - 1 > pre) {
                        Ans[x] = max(Ans[x], T.qryMax(1, 1, n, pre + 1, l - 1));
                    }
                    pre = max(pre, r);
                }
                if (n > pre) Ans[x] = max(Ans[x], T.qryMax(1, 1, n, pre + 1, n));
            }
        }
        T.updMax(1, 1, n, 1, n, 1);
        for (auto v : G[u]) {
            if (v == p) 
                continue;
            T.updMax(1, 1, n, in[v], out[v], -2);
            nxt[u] = v;
            dfs(dfs, v, u);
            T.updMax(1, 1, n, in[v], out[v], 2);
        }
        T.updMax(1, 1, n, 1, n, -1);
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= q; ++i) {
        cout << Ans[i] << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}

