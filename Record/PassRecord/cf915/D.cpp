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

constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

void brute_force(vector<int> &a) {
    vector<int> b = a;
    for (auto i : a) b.pb(i);
    int Max = 0;
    for (int i = 0; i < SZ(a); ++i) {
        cout << "permutation is : ";
        for (int j = i; j < i + SZ(a); ++j) {
            cout << b[j] << ' ';
        }
        cout << '\n';
        int sum = 0;
        cout << "Mex is : ";
        for (int j = i; j < i + SZ(a); ++j) {
            vector<int> Mex(100);
            for (int k = i; k <= j; ++k) {
                Mex[b[k]] = 1;
            }
            int m = 0;
            while (Mex[m]) m++;
            cout << m << ' ';
            sum += m;
        }
        cout << '\n';
        cout << "sum is : " << sum << '\n';
        Max = max(Max, sum);
    }
    cout << "Max is " << Max << "\n\n";
}

int n, m;
int a[maxn], Mex[maxn];
ll sum[maxn << 2], lazy[maxn << 2];
void push_up(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
void push_down(int p, int l, int r) {
    if (lazy[p] != -1) {
        int mid = l + r >> 1;
        sum[p << 1] = lazy[p] * (mid - l + 1);
        sum[p << 1 | 1] = lazy[p] * (r - mid);
        lazy[p << 1] = lazy[p];
        lazy[p << 1 | 1] = lazy[p];
        lazy[p] = -1;
    }
}
void build(int p, int l, int r) {
    sum[p] = 0; //注意清空！！！
    lazy[p] = -1;
    if (l == r) {
        sum[p] = Mex[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}
void update(int p, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        sum[p] = val * (r - l + 1);
        lazy[p] = val;
        return ;
    }
    push_down(p, l, r);
    int mid = l + r >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
    push_up(p);
}
ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[p];
    push_down(p, l, r);
    int mid = l + r >> 1;
    ll ans = 0;
    if (ql <= mid) ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr) ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

int st_min[22][maxn];

int lg[maxn];

void build_st() {

    for (int i = 1; i <= 2 * n; ++i)
        st_min[0][i] = a[i];
    for (int j = 1; j <= 21; ++j)
        for (int i = 1; i + (1 << j) - 1 <= 2 * n; ++i)
            st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]);
}

int query_min(int l, int r) {
    int k = lg[r - l + 1];
    return min(st_min[k][l], st_min[k][r - (1 << k) + 1]);
}



void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i < 2 * n; ++i) {
        a[i] = a[i - n];
    }
    build_st();
    ll Max = 0;
    int now = 0;
    vector<bool> vis(n + 1);
    for (int i = 0; i < n; ++i) {
        vis[a[i]] = 1;
        while (vis[now]) now++;
        Mex[i] = now;
    }
    build(1, 0, 2 * n - 1);
    Max += query(1, 0, 2 * n - 1, 0, n - 1);
    for (int i = n; i < 2 * n; ++i) {
        int l = i - n + 1, r = i;
        int pos = i;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query_min(mid, i) < a[i]) {
                pos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        if (a[i] == 0) pos = i - n + 1;
        if (pos != i) {
            update(1, 0, 2 * n - 1, pos, i - 1, a[i]);
        }
        Max = max(Max, query(1, 0, 2 * n - 1, i - n + 1, i - 1) + n);
    }
    cout << Max << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 2; i <= 2000000; ++i)
        lg[i] = lg[i >> 1] + 1;
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
