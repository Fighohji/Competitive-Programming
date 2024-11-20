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

constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
//可持久化线段树
#define int long long
int idx, ls[maxn << 5], rs[maxn << 5], root[maxn];
ll cnt[maxn << 5];
void update(int rtu, int &rtv, int l, int r, int pos, int val) {
    rtv = ++idx;
    ls[rtv] = ls[rtu], rs[rtv] = rs[rtu], cnt[rtv] = cnt[rtu];
    if (l == r) {
        cnt[rtv] += val;
        return ;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(ls[rtu], ls[rtv], l, mid, pos, val);
    else update(rs[rtu], rs[rtv], mid + 1, r, pos, val);
    cnt[rtv] = cnt[ls[rtv]] + cnt[rs[rtv]];
}

ll query(int rtu, int rtv, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return cnt[rtv] - cnt[rtu];
    }
    int mid = (l + r) >> 1;
    ll res = 0;
    if (ql <= mid) res += query(ls[rtu], ls[rtv], l, mid, ql, qr);
    if (mid < qr) res += query(rs[rtu], rs[rtv], mid + 1, r, ql, qr);
    return res;
}
void solve() {
    int n; cin >> n;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fir;
        a[i].sec = i;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; ++i) {
        update(root[i - 1], root[i], 1, n, a[i].sec, a[i].fir);
    }
    int q; cin >> q;
    ll Ans = 0;
    while (q--) {
        ll x, y, z; cin >> x >> y >> z;
        x ^= Ans;
        y ^= Ans;
        z ^= Ans;
        int t = upper_bound(a.begin() + 1, a.end(), mkp(z, LINF)) - a.begin();
        cout << (Ans = query(root[0], root[t - 1], 1, n, x, y)) << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
