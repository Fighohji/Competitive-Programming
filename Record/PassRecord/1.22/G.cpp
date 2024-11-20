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

struct Scanline {
    int l, r, val;
};
vector<Scanline> S[maxn];
struct SegTree {
    struct Info {
        int lazy, val;
        Info() : lazy(0), val(0) {}
        Info operator+(const Info &r) const {
            Info res = Info();
            res.val = max(val, r.val);
            return res;
        }
    } node[maxn << 2];
    void push(int p) {
        if (node[p].lazy) {
            node[p << 1].lazy += node[p].lazy;
            node[p << 1 | 1].lazy += node[p].lazy;
            node[p << 1].val += node[p].lazy;
            node[p << 1 | 1].val += node[p].lazy;
            node[p].lazy = 0;
        }
    }
    void upd(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            node[p].val += val;
            node[p].lazy += val;
            return ;
        }
        push(p);
        int mid = l + r >> 1;
        if (ql <= mid) upd(p << 1, l, mid, ql, qr, val);
        if (mid < qr) upd(p << 1 | 1, mid + 1, r, ql, qr, val);
        node[p] = node[p << 1] + node[p << 1 | 1];
    }
    int srh(int p, int l, int r, int val) {
        if (l == r) return l;
        push(p);
        int mid = l + r >> 1;
        if (node[p << 1].val == val) return srh(p << 1, l, mid, val);
        return srh(p << 1 | 1, mid + 1, r, val);
    }
} T;
struct node {
    int v, l, r;
};
void solve() {
    int Max = 0;
    int n; cin >> n;
    vector<node> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].l >> p[i].v >> p[i].r;
        Max = max({p[i].r, Max});
        S[p[i].v].eb(p[i].l, p[i].v, 1);
        S[p[i].r + 1].eb(p[i].l, p[i].v, -1);
    }
    Max++;
    int Ans = 0, cl, cr;
    for (int i = 1; i <= Max; ++i) {
        for (auto &[l, r, val] : S[i]) {
            T.upd(1, 1, Max, l, r, val);
        }
        if (Ans < T.node[1].val) {
            Ans = T.node[1].val;
            cl = T.srh(1, 1, Max, T.node[1].val);
            cr = i;
        }
    }
    // cout << cl << ' ' << cr << '\n';
    cout << Ans << '\n';
    for (int i = 1; i <= n; ++i) {
        if (p[i].v >= cl && p[i].v <= cr && p[i].l <= cl && p[i].r >= cr) {
            cout << i << ' ';
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
