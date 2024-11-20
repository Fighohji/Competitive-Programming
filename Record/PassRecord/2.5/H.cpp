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
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};


//普通线段树
struct Info {
    ll sum, pre, suf, Max;
    ll revpre, revsuf;
    Info() { revpre = -LINF, revsuf = -LINF, sum = 0, pre = -LINF, suf = -LINF, Max = -LINF; }
    Info(ll _pre, ll _suf, ll _revpre, ll _revsuf, ll _sum, ll _Max) {
        pre = _pre;
        suf = _suf;
        revpre = _revpre;
        revsuf = _revsuf;
        sum = _sum;
        Max = _Max;
    }
    /*
        以正数开头的前缀pre
        以正数结尾的后缀suf
        以负数开头的前缀revpre
        以负数结尾的后缀revsuf
    */
    Info operator+(const Info &t) const {
        Info i;
        i.sum = sum + t.sum;
        i.pre = max({pre, sum + t.pre});
        i.suf = max({t.suf, t.sum + suf});
        i.revpre = max({revpre, -sum + t.revpre});
        i.revsuf = max({t.revsuf, t.sum + revsuf});
        i.Max = max({Max, t.Max, suf + t.pre, revsuf + t.revpre, suf + t.revpre});
        return i;
    }
};

struct Tag {
    Tag() {}
};

void apply(Info &p, Tag &tag, const Tag &val) {
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
    void upd(int p, int l, int r, int pos, const Info &val) {
        if (l == r) {
            node[p] = val;
            return ;
        }
        int mid = l + r >> 1;
        push(p);
        if (pos <= mid) upd(p << 1, l, mid, pos, val);
        else upd(p << 1 | 1, mid + 1, r, pos, val);
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
    Info qry(int p, int l, int r, int pos) {
        if (l == r) return node[p];
        push(p);
        int mid = l + r >> 1;
        Info res = Info();
        if (pos <= mid) return qry(p << 1, l, mid, pos);
        return qry(p << 1 | 1, mid + 1, r, pos);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<Info> init(n);
    for (int i = 0; i < n; ++i) {
        init[i] = Info(-a[i], a[i], -a[i], a[i], a[i], -LINF);
    }
    SegTree seg = SegTree(init);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y; cin >> x >> y;
            seg.upd(1, 1, n, x, Info(-y, y, -y, y, y, -LINF));
        } else {
            int l, r; cin >> l >> r;
            cout << seg.qry(1, 1, n, l, r).Max << '\n';
        }
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
