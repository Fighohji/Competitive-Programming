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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int a[maxn];
int sum[maxn << 2];
void push_up(int p) {
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}
void build(int p, int l, int r) {
    //lazy[p] = sum[p] = 0 注意清空！！！
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}
void update(int p, int l, int r, int pos, ll val) {
    if (l == r) {
        sum[p] = val;
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(p << 1, l, mid, pos, val);
    if (mid < pos) update(p << 1 | 1, mid + 1, r, pos, val);
    push_up(p);
}
int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[p];
    int mid = l + r >> 1;
    ll ans = 0;
    if (ql <= mid) ans += query(p << 1, l, mid, ql, qr);
    if (mid < qr) ans += query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

int n, m, q;
string s;
void solve(int cas) {
    cin >> n >> m >> q;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i + 1] = s[i] - '0';
    }
    build(1, 1, n);
    
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
