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
#define il inline
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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct node {
    int l, r, a, b;
    bool operator<(const node &t) const {
        if (l != t.l) return l < t.l;
        return r < t.r;
    }
};
struct Query {
    int x, id;
    bool operator<(const Query &t) const {
        return x < t.x;
    }
};

namespace DSU
{
    int fa[maxn * 6];
    void init(int n) { for (int i = 1; i <= n; ++i) fa[i] = i; }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y)
    {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        fa[yy] = xx;
    }
}
using namespace DSU;

void solve() {
    vector<int> tmp;
    int n; cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].a >> a[i].b;
        tmp.pb(a[i].l); tmp.pb(a[i].r);
        tmp.pb(a[i].a); tmp.pb(a[i].b);
    }
    int q; cin >> q;
    vector<Query> qr(q + 1);
    for (int i = 1; i <= q; ++i) {
        cin >> qr[i].x;
        tmp.pb(qr[i].x);
        qr[i].id = i;
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    sort(qr.begin() + 1, qr.end());
    for (int i = 1; i <= q; ++i)
        qr[i].x = lower_bound(all(tmp), qr[i].x) - tmp.begin() + 1;
    vector<vector<pii>> L(SZ(tmp) + 2), R(SZ(tmp) + 2);
    for (int i = 1; i <= n; ++i) {
        a[i].l = lower_bound(all(tmp), a[i].l) - tmp.begin() + 1;
        a[i].r = lower_bound(all(tmp), a[i].r) - tmp.begin() + 1;
        a[i].a = lower_bound(all(tmp), a[i].a) - tmp.begin() + 1;
        a[i].b = lower_bound(all(tmp), a[i].b) - tmp.begin() + 1;
        L[a[i].l].pb({a[i].b, a[i].a});
        R[a[i].r + 1].pb({a[i].b, a[i].a});
    }
    vector<bool> p(SZ(tmp) + 1, 0);
    for (int i = 1; i <= q; ++i) p[qr[i].x] = 1;
    init(SZ(tmp) + 1);
    vector<int> Ans(q + 1);
    set<pii> seg;
    for (int i = 1; i <= SZ(tmp); ++i) {
        for (auto j : R[i]) seg.erase(j);
        for (auto j : L[i]) seg.insert(j);
        if (!p[i]) continue;
        if (seg.empty()) continue;
        auto it = --seg.end();
        if ((*it).fir > i) {
            p[(*it).fir] = 1;
            merge((*it).fir, i);
        }
    }
    for (int i = 1; i <= q; ++i) {
        Ans[qr[i].id] = tmp[find(qr[i].x) - 1];
    }
    for (int i = 1; i <= q; ++i) {
        cout << Ans[i] << ' ';
    }
    cout << '\n';
}

/*
1
3
6 17 7 14
1 12 3 8
16 24 20 22
6
10 2 23 15 28 18
*/
bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
