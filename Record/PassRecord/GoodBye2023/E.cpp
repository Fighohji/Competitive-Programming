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

constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int in[maxn], out[maxn], idx;
vector<int> G[maxn];
void dfs2(int u) {
    in[u] = ++idx;
    for (auto v : G[u]) {
        dfs2(v);
    }
    out[u] = idx;
}

struct SegTree {
    int Max[maxn << 2], lazy[maxn << 2];
    void push(int p) {
        if (lazy[p]) {
            Max[p << 1] += lazy[p];
            Max[p << 1 | 1] += lazy[p];
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            lazy[p] = 0;
        }
    }
    void pull(int p) {
        Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
    }
    void build(int n) {
        for (int i = 1; i <= 4 * n; ++i) {
            Max[i] = lazy[i] = 0;
        }
    }
    void upd(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            Max[p] += val;
            lazy[p] += val;
            return ;
        }
        push(p);
        int mid = l + r >> 1;
        if (ql <= mid) upd(p << 1, l, mid, ql, qr, val);
        if (mid < qr) upd(p << 1 | 1, mid + 1, r, ql, qr, val);
        pull(p);
    }
    ll qry(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return Max[p];
        } 
        push(p);
        int mid = l + r >> 1;
        ll res = 0;
        if (ql <= mid) res = max(res, qry(p << 1, l, mid, ql, qr));
        if (mid < qr) res = max(res, qry(p << 1 | 1, mid + 1, r, ql, qr));
        return res;
    }
} T;
int a[maxn];
ll Ans;
vector<int> S[maxn];
void dfs(int u) {
    for (auto v : G[u])
        dfs(v);
    while (!S[a[u]].empty() && in[S[a[u]].back()] >= in[u]) {
        int p = S[a[u]].back();
        T.upd(1, 1, idx, in[p], out[p], -1);
        S[a[u]].pop_back();
    }
    S[a[u]].push_back(u);
    T.upd(1, 1, idx, in[u], out[u], 1);
    ll pre = 1;
    for (auto v : G[u]) {
        ll now = T.qry(1, 1, idx, in[v], out[v]);
        Ans = max(Ans, pre * now);
        pre = max(pre, now);
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        S[i].clear();
        G[i].clear();
        idx = in[i] = out[i] = 0;
    }
    T.build(n);
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].pb(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dfs2(1);
    Ans = 1;
    dfs(1);
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // brute_force();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
