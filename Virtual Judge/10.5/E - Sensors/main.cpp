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

constexpr int N = 5e5 + 50;
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

struct Qry {
    int id, l, r;
};
int sum[N << 2], n, m;
ll Ans;
int cnt[N];
ll tot[N];
vector<Qry> qry[N << 2];
void build(int p, int l, int r) {
    sum[p] = (r - l + 1);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
void add(int p, int l, int r, int ql, int qr, const Qry &w) {
    if (ql <= l && r <= qr) {
        qry[p].emplace_back(w);
        cnt[w.id]++;
        tot[w.id] += p;
        if (w.l == w.r) Ans += 1ll * w.id * w.id;
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) add(p << 1, l, mid, ql, qr, w);
    if (mid < qr) add(p << 1 | 1, mid + 1, r, ql, qr, w);
}

void upd(int p, int l, int r, int pos) {
    sum[p]--;
    if (sum[p] == 0 || sum[p] == 1) {
        for (const auto &[id, l, r] : qry[p]) {
            if (sum[p] == 0) {
                cnt[id]--;
                tot[id] -= p;
            }
            if (cnt[id] > 1) continue;
            if (cnt[id] == 0) {
                Ans -= 1ll * id * id;
            } else if (sum[tot[id]] == 1) {
                Ans += 1ll * id * id;
            }
        }
    }
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) upd(p << 1, l, mid, pos);
    if (mid < pos) upd(p << 1 | 1, mid + 1, r, pos);
}

void solve() {
    cin >> n >> m;
    Ans = 0;
    for (int i = 0; i <= m; ++i)
        cnt[i] = tot[i] = 0;
    build(1, 0, n - 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        add(1, 0, n - 1, l, r, {i + 1, l, r});
    }
    cout << Ans << ' ';
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a = (a + Ans) % n;
        upd(1, 0, n - 1, a);
        cout << Ans << " \n"[i == n - 1];
    }
    for (int i = 0; i <= n * 4; ++i)
        qry[i].clear();
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
