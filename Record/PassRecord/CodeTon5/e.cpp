#include <map>
#include <numeric>
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};




bool BEGIN;

int sum[maxn << 2], lazy[maxn << 2];

void push_down(int p) {
    if (lazy[p]) {
        sum[p << 1] += lazy[p];
        sum[p << 1 | 1] += lazy[p];
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    }
}

void update(int p, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        sum[p] += val;
        lazy[p] += val;
        return ;
    }
    push_down(p);
    int mid = l + r >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
    sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
}

void update(int p, int l, int r, int pos, int val) {
    if (l == r) {
        sum[p] = min(sum[p], val);
        return ;
    }
    push_down(p);
    int mid = l + r >> 1;
    if (pos <= mid) update(p << 1, l, mid, pos, val);
    else update(p << 1 | 1, mid + 1, r, pos, val);
    sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
}

int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[p];
    int ans = 2 * (INF - 100);
    int mid = l + r >> 1;
    push_down(p);
    if (ql <= mid) ans = min(ans, query(p << 1, l, mid, ql, qr));
    if (mid < qr) ans = min(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
    return ans;
}

void solve(int cas) {
    int n, k, A; cin >> n >> k >> A;
    vector<vector<pii>> a(k + 1);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x, y, c; cin >> x >> y >> c;
        a[y].eb(x, c);
        ans += c;
    }
    for (int i = 1; i <= 4 * (k + 1); ++i) sum[i] = 2 * (INF - 100);
    vector<int> dp(k + 1, 0);
    for (int i = k; i >= 0; --i) {
        int r = k - i;
        for (auto [x, c] : a[i]) {
            update(1, 0, k, x, r, c);
        }
        dp[i] = r * A;
        dp[i] = min(dp[i], A * r + query(1, 0, k, 0, r));
        update(1, 0, k, r, dp[i] - A * (r + 1));
    }
    cout << dp[0] << '\n';
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

