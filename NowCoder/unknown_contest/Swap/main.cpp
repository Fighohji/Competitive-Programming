#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

struct SegTree {
    int rt[N], ls[N * 80], rs[N * 80], val[N * 80];
    int idx = 0;
    void build(int &p, int l, int r) {
        p = ++idx;
        if (l == r) {
            val[p] = l;
            return;
        } 
        int mid = (l + r) >> 1;
        build(ls[p], l, mid);
        build(rs[p], mid + 1, r);
    }
    void ins(int op, int &p, int l, int r, int pos, int w) {
        p = ++idx;
        ls[p] = ls[op], rs[p] = rs[op];
        if (l == r) {
            val[p] = w;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) ins(ls[op], ls[p], l, mid, pos, w);
        if (mid < pos) ins(rs[op], rs[p], mid + 1, r, pos, w);
    }
    int qry(int p, int l, int r, int pos) {
        if (l == r) return val[p];
        int mid = (l + r) >> 1;
        if (pos <= mid) return qry(ls[p], l, mid, pos);
        return qry(rs[p], mid + 1, r, pos);
    }
} T;


int a[N], p[N], Ans[N];
void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> x(m + 1), y(m + 1);
    for (int i = 1; i <= n; ++i) {
        a[i] = p[i] = i;
    }
    T.build(T.rt[0], 1, n);
    for (int i = 1; i <= m; ++i) {
        cin >> x[i] >> y[i];
        swap(a[x[i]], a[y[i]]); 
        swap(p[a[x[i]]], p[a[y[i]]]); 
        T.ins(T.rt[i - 1], T.rt[i], 1, n, a[x[i]], p[a[x[i]]]);
        T.ins(T.rt[i], T.rt[i], 1, n, a[y[i]], p[a[y[i]]]);
    }
    vector qry(m + 1, vector<tuple<int, int, int>>());
    for (int i = 1; i <= q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        qry[r].push_back({l, k, i});
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        swap(a[x[i]], a[y[i]]); 
        for (const auto &[l, k, id] : qry[i]) {
            int nx = a[k];
            int ny = T.qry(T.rt[l - 1], 1, n, nx);
            Ans[id] = ny;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << Ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
