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

int idx, root[maxn], ls[maxn << 5], rs[maxn << 5], sum[maxn << 5];
void ins(int &p, int l, int r, int pos) {
    if (!p) p = ++idx;
    sum[p]++;
    if (l == r) return;
    int mid = l + r >> 1;
    if (pos <= mid) ins(ls[p], l, mid, pos);
    else ins(rs[p], mid + 1, r, pos);
}
void merge(int &p, int np) {
    if (!p || !np) {
        p = np | p;
        return ;
    }
    sum[p] += sum[np];
    merge(ls[p], ls[np]);
    merge(rs[p], rs[np]);
}

int qry(int p, int l, int r, int ql, int qr) {
    if (!p) return 0;
    if (ql <= l && r <= qr) return sum[p];
    int mid = l + r >> 1, res = 0;
    if (ql <= mid) res += qry(ls[p], l, mid, ql, qr);
    if (mid < qr) res += qry(rs[p], mid + 1, r, ql, qr);
    return res;
}
struct Query {
    int l, r, id;
};
vector<Query> qr[maxn];
vector<int> G[maxn];

int n, q;
int Ans[maxn], a[maxn];
void dfs(int u, int p) {
    ins(root[u], 1, n, a[u]);
    for (auto v : G[u]) {
        if (v == p) continue;
        dfs(v, u);
        merge(root[u], root[v]);
    }
    for (auto [l, r, id] : qr[u]) {
        Ans[id] = qry(root[u], 1, n, l, r);
    }
}
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) root[i] = 0, G[i].clear(), qr[i].clear();
    for (int i = 1; i <= idx; ++i) ls[i] = rs[i] = sum[i] = 0;
    idx = 0;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
    }
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        a[p[i]] = i;
    }
    for (int i = 1; i <= q; ++i) {
        int l, r, x; cin >> l >> r >> x;
        qr[x].pb({l, r, i});
    }
    dfs(1, 0);
    for (int i = 1; i <= q; ++i) {
        cout << (Ans[i] ? "Yes\n" : "No\n");
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
