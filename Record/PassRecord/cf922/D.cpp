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

#define int long long

struct Info {
    int val;
    Info() { val = LINF; }
    Info(int _v) : val(_v) {}
    Info operator+(const Info &t) const {
        Info i = *this;
        i.val = min(i.val, t.val);
        return i;
    }
};

struct Tag {
    Tag() {}
};

void apply(Info &p, Tag &tag, const Tag &val) {
    return ;
}

struct SegTree {
    vector<Info> node;
    vector<Tag> tag;
    SegTree(const vector<Info> &vec) {
        int n = vec.size() - 1;
        node.assign((n << 2) + 4, Info());
        tag.assign((n << 2) + 4, Tag());
        auto build = [&](auto self, int p, int l, int r) -> void {
            if (l == r) {
                node[p] = vec[l];
                return ;
            }
            int mid = l + r >> 1;
            self(self, p << 1, l, mid);
            self(self, p << 1 | 1, mid + 1, r);
            node[p] = node[p << 1] + node[p << 1 | 1];
        };
        build(build, 1, 0, n);
    }
    void push(int p) {
        return ;
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


/*
dp[i]

*/

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<ll> pre(n + 1);
    int l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    auto check = [&](int val) -> bool {
        vector<Info> f(n + 1, Info(LINF));
        vector<Info> g(n + 1, Info(LINF));
        f[0] = 0;
        g[0] = 0;
        array<SegTree, 2> seg = {SegTree(f), SegTree(g)};
        for (int i = 1; i <= n; ++i) {
            int L = 1, R = i;
            int pos = i;
            while (L <= R) {
                int mid = L + R >> 1;
                if (pre[i] - pre[mid - 1] <= val) {
                    pos = mid;
                    R = mid - 1;
                } else L = mid + 1;
            }
            f[i] = seg[1].qry(1, 0, n, pos - 1, i - 1);
            g[i] = Info(min(f[i - 1].val + a[i], g[i - 1].val + a[i]));
            seg[1].upd(1, 0, n, i, g[i]);
        }
        // cout << g[n].val << ' ' << f[n].val << '\n';
        return min(g[n].val, f[n].val) <= val;
    };
    int Ans = r;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid - 1;
            Ans = mid;
        } else l = mid + 1;
    }
    cout << Ans << '\n';
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
