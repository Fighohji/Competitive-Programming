#include <algorithm>
#include <array>
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

constexpr int N = 2e5 + 50;
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

#define int long long

struct Info {
    int d, Max, Min, LMax, RMax;
    Info() { d = Max = LMax = RMax = -LINF, Min = LINF; }
    Info(int _d) { Max = Min = _d, LMax = RMax = -_d, d = 0; }
    Info(int _d, int _Mx, int _Mn, int _LMx, int _RMx)
        : d(_d), Max(_Mx), Min(_Mn), LMax(_LMx), RMax(_RMx) {}
    Info operator+(const Info &t) const {
        Info i(max({d, t.d, Max + t.RMax, LMax + t.Max}), max({Max, t.Max}),
               min({Min, t.Min}), max({LMax, t.LMax, Max - 2 * t.Min}),
               max({RMax, t.RMax, t.Max - 2 * Min}));
        return i;
    }
};

struct Tag {
    int w;
    Tag() { w = 0; }
    Tag(int _w) { w = _w; }
};

void apply(Info &p, Tag &tag, const Tag &val) {
    p.Max += val.w;
    p.Min += val.w;
    p.LMax -= val.w;
    p.RMax -= val.w;
    tag.w += val.w;
}

struct SegTree {
    vector<Info> node;
    vector<Tag> tag;
    SegTree(const vector<Info> &vec) {
        int n = vec.size();
        node.assign((n << 2) + 1, Info());
        tag.assign((n << 2) + 1, Tag());
        auto build = [&](auto self, int p, int l, int r) -> void {
            if (l == r) {
                node[p] = vec[l];
                return;
            }
            int mid = (l + r) >> 1;
            self(self, p << 1, l, mid);
            self(self, p << 1 | 1, mid + 1, r);
            node[p] = node[p << 1] + node[p << 1 | 1];
        };
        build(build, 1, 0, n - 1);
    }
    void push(int p) {
        apply(node[p << 1], tag[p << 1], tag[p]);
        apply(node[p << 1 | 1], tag[p << 1 | 1], tag[p]);
        tag[p] = Tag();
    }
    void upd(int p, int l, int r, int ql, int qr, const Tag &val) {
        if (ql > qr) return;
        if (ql <= l && r <= qr) {
            apply(node[p], tag[p], val);
            return;
        }
        push(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) upd(p << 1, l, mid, ql, qr, val);
        if (mid < qr) upd(p << 1 | 1, mid + 1, r, ql, qr, val);
        node[p] = node[p << 1] + node[p << 1 | 1];
    }
    void upd(int p, int l, int r, int pos, const Info &val) {
        if (l == r) {
            node[p] = val;
            return;
        }
        int mid = (l + r) >> 1;
        push(p);
        if (pos <= mid)
            upd(p << 1, l, mid, pos, val);
        else
            upd(p << 1 | 1, mid + 1, r, pos, val);
        node[p] = node[p << 1] + node[p << 1 | 1];
    }
    Info qry(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return Info();
        if (ql <= l && r <= qr) return node[p];
        push(p);
        int mid = (l + r) >> 1;
        Info res = Info();
        if (ql <= mid) res = res + qry(p << 1, l, mid, ql, qr);
        if (mid < qr) res = res + qry(p << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }
    Info qry(int p, int l, int r, int pos) {
        if (l == r) return node[p];
        push(p);
        int mid = (l + r) >> 1;
        if (pos <= mid) return qry(p << 1, l, mid, pos);
        return qry(p << 1 | 1, mid + 1, r, pos);
    }
};
void solve() {
    int n, q, W;
    cin >> n >> q >> W;
    vector G(n + 1, vector<pii>());
    vector<array<int, 3>> edge(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i - 1] = {u, v, w};
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> in(n << 1), out(n << 1), dep(n << 1), euler;
    int idx = 0;
    auto dfs = [&](auto self, int u, int p, int d) -> void {
        dep[u] = d;
        euler.push_back(u);
        in[u] = idx++;
        for (const auto &[v, w] : G[u]) {
            if (v == p) continue;
            self(self, v, u, d + w);
            idx++;
            euler.push_back(u);
        }
        out[u] = idx - 1;
    };
    dfs(dfs, 1, 0, 0);
    vector<Info> init(idx);
    for (int i = 0; i < idx; ++i) {
        init[i] = Info(dep[euler[i]]);
    }
    SegTree seg(init);
    int las = 0;
    while (q--) {
        int d, e;
        cin >> d >> e;
        d = (d + las) % (n - 1);
        e = (e + las) % W;
        auto [u, v, w] = edge[d];
        if (dep[u] < dep[v]) swap(u, v);
        int det = e - w;
        edge[d] = {u, v, e};
        seg.upd(1, 0, idx - 1, in[u], out[u], Tag(det));
        cout << (las = seg.node[1].d) << '\n';
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
