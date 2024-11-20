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
struct Info {
    ll sum;
    int l, r;
    Info() { sum = 0, l = INF, r = -INF; }
    Info(int _l, int _r, ll _sum) : l(_l), r(_r), sum(_sum) {}
    Info operator+(const Info &t) const {
        Info i = *this;
        i = Info(min(l, t.l), max(r, t.r), sum + t.sum);
        return i;
    }
};

struct Tag {
    ll a, d;
    Tag() { a = d = 0; }
    Tag(ll _a, ll _d) { a = _a, d = _d; }
};

void apply(Info &p, Tag &tag, const Tag &val) {
    ll a1 = val.a + p.l * val.d;
    ll an = val.a + p.r * val.d;
    p.sum += (a1 + an) * (p.r - p.l + 1) / 2;
    tag.a += val.a;
    tag.d += val.d;
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
                node[p] = vec[l - 1];
                return ;
            }
            int mid = l + r >> 1;
            self(self, p << 1, l, mid);
            self(self, p << 1 | 1, mid + 1, r);
            node[p] = node[p << 1] + node[p << 1 | 1];
        };
        build(build, 1, 1, n);
    }
    void push(int p) {
        apply(node[p << 1], tag[p << 1], tag[p]);
        apply(node[p << 1 | 1], tag[p << 1 | 1], tag[p]);
        tag[p] = Tag();
    }
    void upd(int p, int l, int r, int ql, int qr, const Tag &val) {
        if (ql <= l && r <= qr) {
            apply(node[p], tag[p], val);
            return ;
        }
        push(p);
        int mid = l + r >> 1;
        if (ql <= mid) upd(p << 1, l, mid, ql, qr, val);
        if (mid < qr) upd(p << 1 | 1, mid + 1, r, ql, qr, val);
        node[p] = node[p << 1] + node[p << 1 | 1];
    }
    Info qry(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return node[p];
        push(p);
        int mid = l + r >> 1;
        Info res = Info();
        if (ql <= mid) res = res + qry(p << 1, l, mid, ql, qr);
        if (mid < qr) res = res + qry(p << 1 | 1, mid + 1, r, ql, qr);
        return res;
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> X(m), V(m);
    for (int i = 0; i < m; ++i) {
        cin >> X[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> V[i];
    }

    set<pll> S;
    S.insert({X[0], V[0]});
    S.insert({X[m - 1], V[m - 1]});
    for (int i = 1; i < m - 1; ++i) {
        S.insert({X[i], V[i]});
    }
    vector<Info> vec(n);
    for (int i = 1; i <= n; ++i) {
        auto it = S.lower_bound({i, 0});
        vec[i - 1] = Info(i, i, 0);
        if (it->fir != i) {
            vec[i - 1].sum = prev(it)->sec * (it->fir - i);
        }
    }
    SegTree seg = SegTree(vec);
    while (q--) {
        ll t, x, v, l, r;
        cin >> t;
        if (t == 1) {
            cin >> x >> v;
            auto it = S.upper_bound({x, 0});
            auto [xl, vl] = *prev(it);
            auto [xr, vr] = *(it);
            // left part
            seg.upd(1, 1, n, xl + 1, x, Tag(vl * (x - xr), 0));
            // right part
            ll a1 = -vl * (xr - x - 1) - (x + 1) * vl;
            ll d = vl;
            a1 += v * (xr - x - 1) + (x + 1) * v;
            d += -v;
            seg.upd(1, 1, n, x + 1, xr, Tag(a1, d));

            S.insert({x, v});
        } else {
            cin >> l >> r;
            cout << seg.qry(1, 1, n, l, r).sum << '\n';
        }
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
