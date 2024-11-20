#include <bitset>
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

int n;
vector<int> buc[N];

vector<int> seg[N];

void update(int p, int l, int r, int ql, int qr, int w) {
    if (ql <= l && r <= qr) {
        seg[p].push_back(w);
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, w);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, w);
}

bitset<500001> bs;
vector<bitset<500001>> lbs;
int stk[N], top;
int Ans[N];

void qry(int p, int l, int r) {
    int las = top;
    lbs.push_back(bs);
    for (auto x : seg[p]) {
        stk[++top] = x;
        bs |= bs << x;
    }
    if (l == r) {
        Ans[l] = bs.count() - 1;
        top = las;
        bs = lbs.back();
        lbs.pop_back();
        return;
    }
    int mid = (l + r) >> 1;
    qry(p << 1, l, mid);
    qry(p << 1 | 1, mid + 1, r);
    top = las;
    bs = lbs.back();
    lbs.pop_back();
}

void solve() {
    bs.set(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            buc[x].push_back(i);
        } else {
            update(1, 1, n, buc[x].back(), i - 1, x);
            buc[x].pop_back();
        }
    }
    for (int i = 1; i <= 500000; ++i) {
        for (auto j : buc[i])
            update(1, 1, n, j, n, i);
    }
    qry(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << '\n';
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

