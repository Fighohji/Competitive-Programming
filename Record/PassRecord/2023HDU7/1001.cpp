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
constexpr int maxn = 1.0e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, m;
int col[maxn << 8];
vector<pii> e[maxn];
struct Edge {
    int u, v, tim;
} edge[maxn];
struct Query {
    int op, x, l, r, v;
} q[maxn << 3];
int blockid[maxn << 8], totblk;
vector<int> block[maxn];
void init(int u, int p, int id) {
    blockid[u] = id;
    for (auto [v, tim] : e[u]) {
        if (v == p) continue;
        if (tim != m + 1) init(v, u, v);
        else init(v, u, id);
    }
}
int fa[maxn << 8];
int Sz[maxn << 8];
int cutId[maxn << 3];
vector<int> opVec[maxn << 3];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int root[maxn << 8], ls[maxn << 8], rs[maxn << 8], cnt[maxn << 8], idx;
int head[maxn << 8];
void ins(int &rt, int l, int r, int pos, int val) {
    if (!rt) rt = ++idx;
    cnt[rt] += Sz[val];
    if (l == r) {
        if (!head[rt]) {
            head[rt] = ++totblk;
            col[head[rt]] = pos;
            fa[head[rt]] = head[rt];
        }
        fa[val] = head[rt]; Sz[head[rt]] += Sz[val];
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) ins(ls[rt], l, mid, pos, val);
    else ins(rs[rt], mid + 1, r, pos, val);
}
int query(int rt, int l, int r, int ql, int qr) {
    if (!cnt[rt]) return 0;
    if (ql <= l && r <= qr) return cnt[rt];
    int mid = l + r >> 1, res = 0;
    if (ql <= mid) res += query(ls[rt], l, mid, ql, qr);
    if (mid < qr) res += query(rs[rt], mid + 1, r, ql, qr);
    return res;
}
void del(int rt, int l, int r, int pos) {
    if (!cnt[rt]) return ;
    if (l == r) {
        cnt[rt] = Sz[head[rt]];
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) del(ls[rt], l, mid, pos);
    else del(rs[rt], mid + 1, r, pos);
    cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}
vector<int> tmp;
void Split(int rt, int l, int r, int ql, int qr) {
    if (!cnt[rt]) return ;
    if (l == r) {
        tmp.pb(head[rt]);
        cnt[rt] = 0;
        head[rt] = 0;
        return ;
    }
    int mid = l + r >> 1;
    if (ql <= mid) Split(ls[rt], l, mid, ql, qr);
    if (mid < qr) Split(rs[rt], mid + 1, r, ql, qr);
    cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}
void solve(int cas) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }
    for (int i = 1; i < n; ++i) {
        cin >> edge[i].u >> edge[i].v;
        edge[i].tim = m + 1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].op;
        if (q[i].op == 1) {
            cin >> q[i].x;
            edge[q[i].x].tim = i;
        } else if (q[i].op == 2) {
            cin >> q[i].x >> q[i].l >> q[i].r >> q[i].v;
        } else {
            cin >> q[i].x >> q[i].l >> q[i].r;
        }
    }
    for (int i = 1; i < n; ++i) {
        auto [u, v, tim] = edge[i];
        e[u].eb(v, tim);
        e[v].eb(u, tim);
    }
    init(1, 0, 1); totblk = n;
    for (int i = 1; i <= n; ++i) {
        block[blockid[i]].pb(i);
        fa[i] = i;
        Sz[i] = 1;
    }
    int Nid = 1;
    for (int i = m; i >= 1; --i) {
        if (q[i].op == 1) {
            int x = blockid[edge[q[i].x].u];
            int y = blockid[edge[q[i].x].v];
            if (SZ(block[x]) > SZ(block[y])) swap(x, y);
            Nid = y;
            cutId[i] = x;
            for (auto j : block[x]) {
                block[y].eb(j), opVec[i].eb(j), blockid[j] = y;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        blockid[i] = Nid;
        ins(root[Nid], 1, n, col[i], i);
    }
    for (int i = 1; i <= m; ++i) {
        auto [op, x, l, r, v] = q[i];
        if (op == 1) {
            for (auto j : opVec[i]) {
                Sz[find(j)]--;
                col[j] = col[find(j)];// push_down lazy
                del(root[blockid[j]], 1, n, col[j]);
                blockid[j] = cutId[i];
                ins(root[blockid[j]], 1, n, col[j], j);
            }
        } else if (op == 2) {
            tmp.clear(); Split(root[blockid[x]], 1, n, l, r);
            ++totblk; fa[totblk] = totblk; //new root
            for (auto j : tmp) {
                fa[j] = totblk;
                Sz[totblk] += Sz[j];
            }
            ins(root[blockid[x]], 1, n, v, totblk);
        } else {
            cout << query(root[blockid[x]], 1, n, l, r) << '\n';
        }
    }
}

bool END;
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve(1);
    return 0;
}

