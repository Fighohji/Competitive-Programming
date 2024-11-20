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

int idx, ls[N << 5], rs[N << 5], cnt[N << 5], sum[N << 5];

void ins(int &p, int l, int r, int pos, int w) {
    if (!p) p = ++idx;
    cnt[p] += w;
    sum[p] += w * pos;
    if (l == r) { return; }
    int mid = (l + r) >> 1;
    if (pos <= mid) ins(ls[p], l, mid, pos, w);
    if (mid < pos) ins(rs[p], mid + 1, r, pos, w);
}

int qry(int p, int l, int r, int pre = 0) {
    if (l == r) {
        if (l == 0) return cnt[l];
        // cerr << l << '\n';
        return min(cnt[p], (0 - pre) / l);
    }
    int mid = (l + r) >> 1;
    if (pre + sum[ls[p]] > 0) return qry(ls[p], l, mid, pre);
    return cnt[ls[p]] + qry(rs[p], mid + 1, r, pre + sum[ls[p]]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    int M = 1000000000;
    vector<int> a(n + 1);
    int rt = 0;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ins(rt, -M, M, a[i], 1);
        if (a[i] > 0) c++;
    }
    while (q--) {
        int x, v;
        cin >> x >> v;
        if (a[x] > 0) c--;
        ins(rt, -M, M, a[x], -1);
        a[x] = v;
        if (a[x] > 0) c++;
        ins(rt, -M, M, a[x], 1);
        cout << c - (n - qry(rt, -M, M)) + 1 << '\n';
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
