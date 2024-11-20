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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
struct Hash
{
    ll seed = 131, p;
    ll hash[maxn], power[maxn];
    void init(string &s, ll P = UINT64_MAX)
    {
        p = P;
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ll get_hash(int l, int r)
    {
        l++, r++;
        ll a = hash[r];
        ll b = hash[l - 1] * power[r - l + 1] % p;
        return (a - b + p) % p;
    }
} hs1, hs2;
struct SegTree {
    ull sum[maxn << 2], lazy[maxn << 2];
    void push_up(int p) {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void push_down(int p, int l, int r) {
        if (lazy[p]) {
            int mid = l + r >> 1;
            sum[p << 1] += lazy[p] * (mid - l + 1);
            sum[p << 1 | 1] += lazy[p] * (r - mid);
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            lazy[p] = 0;
        }
    }
    void build(int p, int l, int r, int *a) {
        //lazy[p] = sum[p] = 0 注意清空！！！
        if (l == r) {
            sum[p] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid, a);
        build(p << 1 | 1, mid + 1, r, a);
        push_up(p);
    }
    void update(int p, int l, int r, int ql, int qr, ll val) {
        if (ql <= l && r <= qr) {
            sum[p] += val * (r - l + 1);
            lazy[p] += val;
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
}



void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    hs1.init(s, 1e9 + 9); hs2.init(s, 998244853);

}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
