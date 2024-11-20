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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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
constexpr int maxn = 1e4 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, q;
int a[maxn];
struct node {
    int x, id;
    bool operator<(const node &t) const {
        if (t.x % 2 != x % 2) return x % 2 > t.x % 2;
        if (x != t.x) return x < t.x;
        return id > t.id;
    }
};

int idx;
int root[maxn << 5], ls[maxn << 9], rs[maxn << 9], cnt[maxn << 9], mx[maxn << 9];

void build(int &rt, int l, int r) {
    rt = ++idx;
    if (l == r) {
        mx[rt] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(ls[rt], l, mid);
    build(rs[rt], mid + 1, r);
    mx[rt] = max(mx[ls[rt]], mx[rs[rt]]);
}

void update(int rtu, int &rtv, int l, int r, int pos, int val) {
    rtv = ++idx;
    ls[rtv] = ls[rtu], rs[rtv] = rs[rtu];
    cnt[rtv] = cnt[rtu]; mx[rtv] = mx[rtu];
    if (l == r) {
        mx[rtv] = (a[l] >>= 1);
        cnt[rtv] += 1;
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(ls[rtu], ls[rtv], l, mid, pos, val);
    else update(rs[rtu], rs[rtv], mid + 1, r, pos, val);
    cnt[rtv] = cnt[ls[rtv]] + cnt[rs[rtv]];
    mx[rtv] = max(mx[ls[rtv]], mx[rs[rtv]]);
}
int query( int rt, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return cnt[rt];
    int mid = l + r >> 1, res = 0;
    if (ql <= mid) res += query(ls[rt], l, mid, ql, qr);
    if (mid < qr) res += query(rs[rt], mid + 1, r, ql, qr);
    return res;
}
int query_mx(int rt, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return mx[rt];
    int mid = l + r >> 1, res = 0;
    if (ql <= mid) res = max(query_mx(ls[rt], l, mid, ql, qr), res);
    if (mid < qr) res = max(query_mx(rs[rt], mid + 1, r, ql, qr), res);
    return res;
}
priority_queue<node> Q;
void solve(int cas) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) Q.push((node){a[i], i});
    }
    build(root[0], 1, n);
    int cnt = 0;
    while (!Q.empty()) {
        node p = Q.top(); Q.pop();
        auto [x, id] = p;
        update(root[cnt], root[cnt + 1], 1, n, id, 1);
        cnt++;
        if (x / 2 > 0) Q.push({x >>= 1, id});
    }
    for (int i = 1; i <= q; ++i) {
        int l, r, k; cin >> l >> r >> k;
        if (k == 0) {
            cout << mx[root[0]] << '\n';
        } else {
            int L = 1, R = cnt, t = 0;
            while (L <= R) {
                int mid = L + R >> 1;
                if (query(root[mid], 1, n, l, r) <= k) {
                    t = mid;
                    L = mid + 1;
                } else R = mid - 1;
            }
            cout << query_mx(root[t], 1, n, l, r) << '\n';
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
