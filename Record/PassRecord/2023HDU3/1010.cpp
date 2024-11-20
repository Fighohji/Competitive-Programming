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

ll a[maxn], b[maxn];
vector<pll> range[maxn];

vector<pll> operator + (const vector<pll> &a, const vector<pll> &b) {
    set<pll> s;
    for (auto &i : a) {
        for (auto &j : b) {
            s.emplace(i.fir + j.fir, i.sec + j.sec);
        }
    }
    ll prel = -1, prer = -1;
    vector<pll> Ans;
    for (auto i : s) {
        auto [x, y] = i;
        if (prel == -1) prel = x, prer = y;
        else {
            if (x <= prer + 1) {
                prer = max(prer, y);
            } else {
                Ans.eb(prel, prer);
                prel = x, prer = y;
            }
        }
    }
    Ans.eb(prel, prer);
    return Ans;
}

void build(int p, int l, int r) {
    range[p].clear();
    if (l == r) {
        range[p].eb(0, 0);
        range[p].eb(a[l], b[l]);
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    range[p] = range[p << 1] + range[p << 1 | 1];
    // if (l == 1 && r == 2) {
    //     for (auto i : range[p]) {
    //         cout << i.fir << ' ' << i.sec << '\n';
    //     }
    // }
}


void update(int p, int l, int r, int pos, pll nrange) {
    if (l == r) {
        range[p].clear();
        range[p].eb(0, 0);
        range[p].pb(nrange);
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(p << 1, l, mid, pos, nrange);
    else update(p << 1 | 1, mid + 1, r, pos, nrange);
    range[p] = range[p << 1] + range[p << 1 | 1];
}

vector<pll> query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return range[p];
    int mid = l + r >> 1;
    vector<pll> ans;
    ans.eb(0, 0);
    if (ql <= mid) ans = ans + query(p << 1, l, mid, ql, qr);
    if (mid < qr) ans = ans + query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

void solve(int cas) {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    build(1, 1, n);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int k, a, b; cin >> k >> a >> b;
            update(1, 1, n, k, {a, b});
        } else {
            int l, r; cin >> l >> r;
            vector<pll> ans = query(1, 1, n, l, r);
            ll Ans = 0;
            for (auto i : ans) {
                auto [x, y] = i;
                // cout << x <<  ' ' << y << '\n';
                Ans += y - x + 1;
            }
            cout << Ans << '\n';
        }
    }    
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

