#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <climits>
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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, k, q;

int a[maxn];

int idx, root, cnt[maxn << 5], ls[maxn << 5], rs[maxn << 5];
ll sum[maxn << 5];

void update(int &p, int l, int r, int pos, ll val) {
    if (!p) p = ++idx;
    if (l == r) {
        cnt[p] += val;
        sum[p] += val * pos;
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(ls[p], l, mid, pos, val);
    else update(rs[p], mid + 1, r, pos, val);
    sum[p] = sum[ls[p]] + sum[rs[p]];
    cnt[p] = cnt[ls[p]] + cnt[rs[p]];
}

ll query(int p, int l, int r, int kth) {
    // cout << l << ' ' << r << '\n';
    if (r < l || !p) return 0;
    int mid = l + r >> 1;
    if (l == r) {
        return kth * (ll)l;
    }
    if (cnt[rs[p]] >= kth) {
        return query(rs[p], mid + 1, r, kth);
    } else {
        ll res = sum[rs[p]];
        kth -= cnt[rs[p]];
        return res + query(ls[p], l, mid, kth);
    }
}

void solve(int cas) {
    cin >> n >> k >> q;
    update(root, 0, 1000000000, 0, n);
    while (q--) {
        int x, y; cin >> x >> y;
        update(root, 0, 1000000000, a[x], -1);
        update(root, 0, 1000000000, y, 1);
        a[x] = y;
        cout << query(root, 0, 1000000000, k) << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
