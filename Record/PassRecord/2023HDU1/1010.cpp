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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};



// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;



ll a[maxn]; int n;

ll cnt[maxn << 2], sum1[maxn << 2], lazy[maxn << 2], mn[maxn << 2], lazya[maxn << 2], lazys[maxn << 2], sum2[maxn << 2];
void push_up(int p) {
    cnt[p] = cnt[p << 1] + cnt[p << 1 | 1];
    sum1[p] = sum1[p << 1] + sum1[p << 1 | 1];
    mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
    sum2[p] = sum2[p << 1] + sum2[p << 1 | 1];
}

void push_down(int p, int l, int r) {
    int mid = l + r >> 1;
    if (lazy[p]) {
        sum1[p << 1] += lazy[p] * cnt[p << 1];
        sum1[p << 1 | 1] += lazy[p] * cnt[p << 1 | 1];
        mn[p << 1] += lazy[p];
        mn[p << 1 | 1] += lazy[p];
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    } 
    //sum2[p] = sum2[p] * -1 + val;
    lazys[p << 1] = lazys[p] + lazys[p << 1] * lazya[p];
    lazys[p << 1 | 1] = lazys[p] + lazys[p << 1 | 1] * lazya[p];
    lazya[p << 1] *= lazya[p];
    lazya[p << 1 | 1] *= lazya[p];
    sum2[p << 1] = lazya[p] * sum2[p << 1] + lazys[p] * (mid - l + 1 - cnt[p << 1]);
    sum2[p << 1 | 1] = lazya[p] * sum2[p << 1 | 1] + lazys[p] * (r - mid - cnt[p << 1 | 1]);
    lazys[p] = 0;
    lazya[p] = 1;
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    lazya[p] = 1;
    lazys[p] = 0;
    if (l == r) {
        cnt[p] = 1;
        sum1[p] = a[l];
        mn[p] = a[l];
        sum2[p] = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        // cout << "!!!\n";
        if (cnt[p]) {
            if (l == r) {
                if (sum1[p] < val) {
                    mn[p] = LINF;
                    cnt[p] = 0;
                    sum2[p] = val - sum1[p];
                    sum1[p] = 0;
                    // cout << l << ' ' << sum2[p] << ' ' << p << '\n'; 
                } else {
                    sum1[p] -= val;
                    mn[p] -= val;
                }
            } else {
                if (mn[p] < val) {
                    push_down(p, l, r);
                    int mid = l + r >> 1;
                    update(p << 1, l, mid, ql, qr, val);
                    update(p << 1 | 1, mid + 1, r, ql, qr, val);
                    push_up(p);
                    // cout << sum2[p] << '\n';
                } else {
                    sum1[p] -= cnt[p] * val;
                    lazy[p] -= val;
                    mn[p] -= val;
                    lazys[p] = val - lazys[p];
                    lazya[p] *= -1;
                    sum2[p] = (r - l + 1 - cnt[p]) * val - sum2[p];
                }
            }
        } else {
                lazys[p] = val - lazys[p];
                lazya[p] *= -1;
                sum2[p] = (r - l + 1 - cnt[p]) * val - sum2[p];
        }
        return ;
    }
    int mid = l + r >> 1;
    push_down(p, l, r);
    if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        // cout << sum1[p] << ' ' << sum2[p] << ' ' << cnt[p] << " " << l << ' ' << r << '\n';
        return sum1[p] + sum2[p]; 
    }
    push_down(p, l, r);
    ll res = 0;
    int mid = l + r >> 1;
    if (ql <= mid) res += query(p << 1, l, mid, ql, qr);
    if (mid < qr) res += query(p << 1 | 1, mid + 1, r, ql, qr);
    return res;
}


void solve(int cas) {
    int m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
            // split
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("1010.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
