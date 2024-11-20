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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
bool BEGIN;
#define int long long
int a[maxn], n;
int root[maxn << 5], ls[maxn << 5], rs[maxn << 5], cnt[maxn << 5], idx;
void ins(int rtu, int &rtv, int l, int r, int val) {
    rtv = ++idx;
    ls[rtv] = ls[rtu], rs[rtv] = rs[rtu], cnt[rtv] = cnt[rtu];
    cnt[rtv]++;
    if (l == r) return ;
    int mid = l + r >> 1;
    if (val <= mid) ins(ls[rtu], ls[rtv], l, mid, val);
    else ins(rs[rtu], rs[rtv], mid + 1, r, val);
}

int query(int rtu, int rtv, int l, int r, int ql, int qr) {
    if (qr < ql) return 0;
    if (ql <= l && r <= qr) return cnt[rtv] - cnt[rtu];
    int mid = l + r >> 1, res = 0;
    if (ql <= mid) res += query(ls[rtu], ls[rtv], l, mid, ql, qr);
    if (mid < qr) res += query(rs[rtu], rs[rtv], mid + 1, r, ql, qr);
    return res;
}

set<tuple<int, int, int>> seg;
multiset<int> Ans;
void Clear(int n) {
    seg.clear();
    Ans.clear();
    for (int i = 1; i <= n; ++i) root[i] = 0;
    for (int i = 1; i <= idx; ++i) {
        ls[i] = rs[i] = cnt[i] = 0;
    }
    idx = 0;
}
void solve() {
    cin >> n;
    Clear(n);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ins(root[i - 1], root[i], 1, n, a[i]);
        tot += query(root[0], root[i], 1, n, a[i] + 1, n);
    }
    seg.insert({1, n, tot});
    Ans.insert(tot);
    for (int i = 1; i <= n; ++i) {
        int now = *Ans.rbegin();
        cout << now << ' ';
        int x; cin >> x;
        int mid = x ^ now;
        if (i == n) break;
        auto it = seg.upper_bound({mid, n + 1, 0});
        --it;
        auto [l, r, sum] = *it;
        seg.erase(it);
        Ans.extract(sum);
        if (l == r) continue;
        if (mid - l < r - mid) {
            int lsum = 0, rsum = sum;
            for (int i = l + 1; i < mid; ++i) {
                lsum += query(root[l - 1], root[i], 1, n, a[i] + 1, n);
            }
            rsum -= lsum + query(root[l - 1], root[mid], 1, n, a[mid] + 1, n);
            for (int i = l; i <= mid; ++i) {
                rsum -= query(root[mid], root[r], 1, n, 1, a[i] - 1);
            }
            if (mid - 1 >= l) seg.insert({l, mid - 1, lsum}), Ans.insert(lsum);
            if (mid + 1 <= r) seg.insert({mid + 1, r, rsum}), Ans.insert(rsum);
        } else {
            int lsum = sum, rsum = 0;
            for (int i = mid + 2; i <= r; ++i) {
                rsum += query(root[mid], root[i], 1, n, a[i] + 1, n);
            }
            lsum -= rsum + query(root[mid], root[r], 1, n, 1, a[mid] - 1);
            for (int i = mid; i <= r; ++i) {
                lsum -= query(root[l - 1], root[mid - 1], 1, n, a[i] + 1, n);
            }
            if (mid - 1 >= l) seg.insert({l, mid - 1, lsum}), Ans.insert(lsum);
            if (mid + 1 <= r) seg.insert({mid + 1, r, rsum}), Ans.insert(rsum);
        }
    }
    cout << '\n';
}

/*
3
5
4 3 1 1 1
5 4 5 3 1
10
9 7 1 4 7 8 5 7 4 8
21 8 15 5 9 2 4 5 10 6
15
4 8 8 1 12 1 10 14 7 14 2 9 13 10 3
37 19 23 15 7 2 10 15 2 13 4 5 8 7 10

*/

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
