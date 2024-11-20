#include <algorithm>
#include <climits>
#include <functional>
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

#define int long long
struct SegTree {
    int sum[N << 2], Max[N << 2], tag[N << 2];
    void push(int p, int l, int r) {
        int mid = (l + r) >> 1;
        if (tag[p] != -1) {
            sum[p << 1] = tag[p] * (mid - l + 1);
            Max[p << 1] = tag[p];
            sum[p << 1 | 1] = tag[p] * (r - mid);
            Max[p << 1 | 1] = tag[p];
            tag[p << 1] = tag[p];
            tag[p << 1 | 1] = tag[p];
            tag[p] = -1;
        }
    }
    void pull(int p) {
        Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void upd(int p, int l, int r, int ql, int qr, int w) {
        if (ql > qr) return;
        int mid = (l + r) >> 1;
        if (ql <= l && r <= qr) {
            sum[p] = w * (r - l + 1);
            tag[p] = w;
            Max[p] = w;
            return;
        }
        push(p, l, r);
        if (ql <= mid) upd(p << 1, l, mid, ql, qr, w);
        if (mid < qr) upd(p << 1 | 1, mid + 1, r, ql, qr, w);
        pull(p);
    }
    pii qry(int p, int l, int r, int ql, int qr) {
        if (ql > qr) return {0, 0};
        if (ql <= l && r <= qr) return {Max[p], sum[p]};
        int mid = (l + r) >> 1;
        push(p, l, r);
        pii res = {0, 0};
        if (ql <= mid) {
            auto [mx, s] = qry(p << 1, l, mid, ql, qr);
            res.first = max(res.first, mx);
            res.second += s;
        }
        if (mid < qr) {
            auto [mx, s] = qry(p << 1 | 1, mid + 1, r, ql, qr);
            res.first = max(res.first, mx);
            res.second += s;
        }
        return res;
    }
    int find(int p, int l, int r, int w) {
        if (l == r) return r;
        push(p, l, r);
        int mid = (l + r) >> 1;
        if (Max[p << 1] >= w) return find(p << 1, l, mid, w);
        return find(p << 1 | 1, mid + 1, r, w);
    }
} seg;

vector<int> Y[N];
void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        tmp.push_back(x);
        Y[x].push_back(y);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    int tot = 0;
    int Ans = (1ll + p) * p / 2 * (q + 1) + (1ll + q) * q / 2 * (p + 1);
    int las = 0, res = 0;
    for (int k = 0; k < tmp.size(); ++k) {
        int i = tmp[k];
        if (i >= p) break;
        Y[i].push_back(1000001);
        sort(all(Y[i]), greater());
        for (int j = 1; j < (int)Y[i].size(); ++j) {
            int Max = seg.qry(1, 0, 1000000, 0, Y[i][j]).first + 1;
            int pos = seg.find(1, 0, 1000000, Max);
            seg.upd(1, 0, 1000000, Y[i][j] + 1, pos, Max);
        }
        tot += (i - las) * res;
        res = seg.qry(1, 0, 1000000, 0, q).second;
        las = i;
    }
    tot += (p - las) * res;
    seg.upd(1, 0, 1000000, 0, 1000000, 0);
    for (auto i : tmp) {
        Y[i].clear();
    }
    cout << Ans - tot << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 4000000; ++i)
        seg.tag[i] = -1;
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
