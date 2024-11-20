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
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


vector<int> G[maxn];
int in[maxn], out[maxn], dep[maxn], id[maxn], idx;
int n, m;
void dfs(int u, int p) {
    dep[u] = dep[p] + 1;
    in[u] = ++idx;
    id[idx] = u;
    for (auto v : G[u])
        dfs(v, u);
    out[u] = idx;
}

struct Info {
    int d, flag;
    int lazysum, lazycnt;
};

struct SegTree {
#define ls (p << 1)
#define rs (ls + 1)
#define mid (l + r >> 1)
    Info node[maxn << 2];
    void build(int p, int l, int r) {
        if (l == r) {
            node[p].d = dep[id[l]];
            node[p].flag = dep[id[l]] % 2 ? 1 : -1;
            return ;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
    }
    void push(int p) {
        if (node[p].lazysum) {
            node[ls].lazysum = ((node[ls].lazysum + node[p].lazysum) % mod + mod) % mod;
            node[rs].lazysum = ((node[rs].lazysum + node[p].lazysum) % mod + mod) % mod;
            node[p].lazysum = 0;
        }
        if (node[p].lazycnt) {
            node[ls].lazycnt = ((node[ls].lazycnt + node[p].lazycnt) % mod + mod) % mod;
            node[rs].lazycnt = ((node[rs].lazycnt + node[p].lazycnt) % mod + mod) % mod;
            node[p].lazycnt = 0;
        }
    }
    void update_sum(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            node[p].lazysum += val;
            node[p].lazysum %= mod;
            node[p].lazysum += mod;
            node[p].lazysum %= mod;
            return ;
        }
        push(p);
        if (ql <= mid) update_sum(ls, l, mid, ql, qr, val);
        if (mid < qr) update_sum(rs, mid + 1, r, ql, qr, val);
    }
    void update_cnt(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            node[p].lazycnt += val;
            node[p].lazycnt %= mod;
            node[p].lazycnt += mod;
            node[p].lazycnt %= mod;
            return ;
        }
        push(p);
        if (ql <= mid) update_cnt(ls, l, mid, ql, qr, val);
        if (mid < qr) update_cnt(rs, mid + 1, r, ql, qr, val);
    }

    int query(int p, int l, int r, int pos) {
        if (l == r) {
            return ((node[p].lazysum + (ll)node[p].lazycnt * node[p].d % mod) % mod * node[p].flag % mod + mod) % mod;
        }
        push(p);
        if (pos <= mid) return query(ls, l, mid, pos);
        else return query(rs, mid + 1, r, pos);
    }
#undef mid
#undef ls
#undef rs
} seg;

struct UPD {
    int l, r, x, y, z;
    bool operator<(const UPD &t) const {
        return l < t.l;
    }
    bool operator==(const UPD &t) const {
        return l == t.l;
    }
};
multiset<UPD> clr;

void solve() {
    cin >> n >> m;
    for (int i = 2; i <= n; ++i) {
        int fa; cin >> fa;
        G[fa].pb(i);
    }
    dfs(1, 0);
    seg.build(1, 1, n);
    while (m--) {
        int op; cin >> op;
        int v, x, k;
        if (op == 1) {
            cin >> v >> x >> k;
            int X = dep[v] % 2 ? x : -x;
            int Y = dep[v] % 2 ? k : -k;
            int Z = dep[v] % 2 ? (-dep[v] * k % mod + mod) % mod : k * dep[v] % mod;
            seg.update_sum(1, 1, n, in[v], out[v], X);
            seg.update_cnt(1, 1, n, in[v], out[v], Y);
            seg.update_sum(1, 1, n, in[v], out[v], Z);
            clr.insert((UPD){in[v], out[v], X, Y, Z});
            // cerr << v << " insert\n";
        } else if (op == 2) {
            cin >> v;
            cout << seg.query(1, 1, n, in[v]) << '\n';
        } else {
            cin >> v;
            // for (auto [l, r, x, y, z] : clr) {
            //     cout << id[l] << " ";
            // }
            // cerr << "clr\n";
            while (!clr.empty()) {
                auto it = (clr.lower_bound({in[v], 0, 0, 0, 0}));
                if (it == clr.end() || (it->l) > out[v]) break;
                seg.update_sum(1, 1, n, it->l, it->r, ((-(it->x)) % mod + mod) % mod);
                seg.update_sum(1, 1, n, it->l, it->r, ((-(it->z)) % mod + mod) % mod);
                seg.update_cnt(1, 1, n, it->l, it->r, ((-(it->y)) % mod + mod) % mod);
                clr.erase(it);
            }
        }
    }
}
/*
5 11
1
1
3
3
1 1 0 2
2 1
2 2
3 3
2 4
3 1
1 3 1 3
2 3
2 4
3 1
2 1
*/

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
