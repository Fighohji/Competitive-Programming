#include <ios>
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

//普通线段树
struct Info {
    int val;
    Info() { val = 0; }
    Info(int _) { val = _; }
    Info operator+(const Info &t) const {
        Info i;
        i.val = max(val, t.val);
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
            node[p].val = max(node[p].val, val.val);
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
    int n, d; cin >> n >> d;
    vector<int> a(n + 1);
    int Max = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        Max = max(Max, a[i]);
    }
    vector<int> dp(n + 1, 0);
    SegTree seg = SegTree(vector<Info>(Max));
    int Ans = 0;
    for (int i = 1; i <= n; ++i) {
        int L = max(1, a[i] - d), R = min(Max, a[i] + d);
        dp[i] = max(dp[i], seg.qry(1, 1, Max, L, R).val + 1);
        seg.upd(1, 1, Max, a[i], dp[i]);
        Ans = max(Ans, dp[i]);
    }
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
