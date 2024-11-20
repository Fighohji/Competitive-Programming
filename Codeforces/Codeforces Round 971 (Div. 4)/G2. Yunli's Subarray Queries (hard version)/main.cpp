#include <climits>
#include <iostream>
#include <random>
#include <set>
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
    int l, r, sum;
    Info() { sum = 0; }
    Info(int _m) : sum(_m) {}
    Info operator+(const Info &t) const {
        Info res = Info(sum + t.sum);
        res.l = l, res.r = t.r;
        return res;
    }
};

struct Tag {
    int w;
    Tag() { w = -1; }
    Tag(int _w) : w(_w) {}
};

void apply(Info &p, Tag &tag, const Tag &val) {
    if (val.w != -1) {
        p.sum = val.w * (p.r - p.l + 1);
        tag.w = val.w;
    }
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
                node[p].l = node[p].r = l;
                return;
            }
            int mid = (l + r) >> 1;
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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i;
        a[i] += n;
    }
    vector<int> rval(n + 1), cnt(2 * n + 1);
    set<pii> st;
    for (int i = n; i > n - k; --i) {
        cnt[a[i]]++;
    }
    for (int i = 0; i <= 2 * n; ++i) {
        st.insert({cnt[i], i});
    }
    for (int l = n - k + 1, r = n; l >= 1; l--, r--) {
        rval[r] = k - st.rbegin()->first;
        if (st.count({cnt[a[l - 1]], a[l - 1]})) st.erase({cnt[a[l - 1]], a[l - 1]});
        cnt[a[l - 1]]++;
        st.insert({cnt[a[l - 1]], a[l - 1]});
        if (st.count({cnt[a[r]], a[r]})) st.erase({cnt[a[r]], a[r]});
        cnt[a[r]]--;
        st.insert({cnt[a[r]], a[r]});
    }

    vector qry(n + 1, vector<pii>());
    for (int i = 1; i <= q; ++i) {
        int l, r;
        cin >> l >> r;
        qry[l].push_back({r, i});
    }

    vector<Info> init(n, Info());
    SegTree seg(init);

    vector<pii> stk{{-1, n + 1}};
    vector<int> Ans(q + 1);

    for (int i = n - k + 1; i >= 1; --i) {
        while (stk.back().first >= rval[i + k - 1]) stk.pop_back();
        seg.upd(1, 1, n, i + k - 1, stk.back().second - 1, Tag(rval[i + k - 1]));
        stk.push_back({rval[i + k - 1], i + k - 1});
        for (const auto &[r, id] : qry[i]) {
            Ans[id] = seg.qry(1, 1, n, i + k - 1, r).sum;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << Ans[i] << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
