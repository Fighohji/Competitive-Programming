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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
struct SegTree {
    int sum[maxn << 2];
    void push_up(int p) {
        sum[p] = max(sum[p << 1], sum[p << 1 | 1]);
    }
    void update(int p, int l, int r, int pos, int val) {
        if (l == r) {
            sum[p] = val;
            return ;
        }
        int mid = l + r >> 1;
        if (pos <= mid) update(p << 1, l, mid, pos, val);
        else update(p << 1 | 1, mid + 1, r, pos, val);
        push_up(p);
    }
    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[p];
        int mid = l + r >> 1;
        int ans = -INF;
        if (ql <= mid) ans = max(ans, query(p << 1, l, mid, ql, qr));
        if (mid < qr) ans = max(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
} X, Y;

int t;
map<pii, int> mp;
map<pii, int> mx[maxn], my[maxn];
void solve(int cas) {
    cin >> t;
    memset(X.sum, -0x3f, sizeof X.sum);
    memset(Y.sum, -0x3f, sizeof Y.sum);
    while (t--) {
        int op, x, y; cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (y >= x) {
                mp[mkp(x, y)]++;
            } else {
                mx[x - y][mkp(x, y)]++;
                my[x - y][mkp(y, x)]++;
                auto it = mx[x - y].end();
                --it;
                X.update(1, 0, 1000000, x - y, (*it).fir.fir);
                it = my[x - y].end();
                --it;
                Y.update(1, 0, 1000000, x - y, (*it).fir.fir);
            }
        } else if (op == 2) {
            cin >> x >> y;
            if (y >= x) {
                mp[mkp(x, y)]--;
                if (!mp[mkp(x, y)]) {
                    mp.erase(mkp(x, y));
                }
            } else {
                mx[x - y][mkp(x, y)]--;
                my[x - y][mkp(y, x)]--;
                if (!mx[x - y][mkp(x, y)]) {
                    mx[x - y].erase(mkp(x, y));
                }
                if (!my[x - y][mkp(y, x)]) {
                    my[x - y].erase(mkp(y, x));
                }
                if (!mx[x - y].empty()) {
                    auto it = mx[x - y].end();
                    --it;
                    X.update(1, 0, 1000000, x - y, (*it).fir.fir);
                } else {
                    X.update(1, 0, 1000000, x - y, -INF);
                }
                if (!my[x - y].empty()) {
                    auto it = my[x - y].end();
                    --it;
                    Y.update(1, 0, 1000000, x - y, (*it).fir.fir);
                } else {
                    Y.update(1, 0, 1000000, x - y, -INF);
                }
            }
        } else {
            int k; cin >> k;
            int ans = 0;
            if (!mp.empty()) {
                auto it = mp.end();
                --it;
                ans = max(ans, (*it).fir.fir);
            }
            ans = max(ans, Y.query(1, 0, 1000000, k, 1000000) + k);
            ans = max(ans, X.query(1, 0, 1000000, 0, k));
            cout << ans << '\n';
        }
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
