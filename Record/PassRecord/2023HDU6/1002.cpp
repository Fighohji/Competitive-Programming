// #pragma GCC optimize(2)
#include <climits>
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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;




struct BIT {
    int MX;
    int tr[maxn];
    void init(int n) {
        MX = n;
        for (int i = 1; i <= n; ++i)
            tr[i] = 0;
    }
    void update(int x, int val) {
        while (x <= MX) {
            tr[x] += val;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int sum = 0;
        while (x) {
            sum += tr[x];
            x -= lowbit(x);
        }
        return sum;
    }
} bit;


struct node {
    int l, r, id;
    bool operator<(const node &t) const {
        return r < t.r;
    }
} qr[maxn];

int p[maxn], id[maxn];
int sqr[maxn], cnt;
int ans[maxn];
vector<int> pa[maxn];
void solve(int cas) {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        id[p[i]] = i;
        pa[i].clear();
    }
    int q; cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr + 1, qr + 1 + q);
    for (int i = 1; i <= cnt; ++i) {
        if (sqr[i] >= 2 * n) break;
        for (int j = max(sqr[i] - n, 1); j <= (sqr[i] - 1) / 2; ++j) {
            int l = id[j], r = id[sqr[i] - j];
            if (l > r) swap(l, r);
            pa[r].eb(l);
        }
    }
    int sz = 0;
    bit.init(n);
    int r = 1;
    for (int i = 1; i <= q; ++i) {
        while (r <= qr[i].r) {
            for (int j : pa[r]) {
                bit.update(j, 1);
                sz++;
            }
            r++;
        }
        ans[qr[i].id] = sz - bit.query(qr[i].l - 1);
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i * i <= 200000; ++i) sqr[++cnt] = i * i;
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
