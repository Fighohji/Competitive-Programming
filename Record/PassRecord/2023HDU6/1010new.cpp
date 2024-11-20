#pragma GCC optimize(2)
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9+7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
int norm(int x) {
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T qpow(T base, ll power) {
    T res = 1;
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}


struct mint {
    int x;
    mint(int x = 0) : x(norm(x)) {}
    mint(ll x) : x(norm(x % mod)) {}
    int val() const { return x; }
    mint operator-() const { return mint(norm(mod - x)); }
    mint inv() const { assert(x != 0); return qpow(*this, mod - 2); }
    mint &operator*=(const mint &rhs) { x = (ll)x * rhs.x % mod; return *this; }
    mint &operator+=(const mint &rhs) { x = norm(x + rhs.x); return *this; }
    mint &operator-=(const mint &rhs) { x = norm(x - rhs.x); return *this; }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) { mint res = lhs; res *= rhs; return res; }
    friend mint operator+(const mint &lhs, const mint &rhs) { mint res = lhs; res += rhs; return res; }
    friend mint operator-(const mint &lhs, const mint &rhs) { mint res = lhs; res -= rhs; return res; }
    friend mint operator/(const mint &lhs, const mint &rhs) { mint res = lhs; res /= rhs; return res; }
    friend std::istream &operator>>(std::istream &is, mint &a) { ll v; is >> v; a = mint(v); return is; }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) { return os << a.val(); }
};
pair<mint, mint> operator * (const pair<mint, mint> a, const pair<mint, mint> b) {
    return {a.fir * b.fir, b.fir * a.sec + b.sec};
}
pair<mint, mint> qpow(pair<mint, mint> base, ll power) {
    pair<mint, mint> res = {1, 0};
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}


#define node pair<mint, mint>
#define K first
#define B second

void solve(int cas) {
    int n, q; cin >> n >> q;
    vector<int> k(n + 1), b(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    vector<vector<int>> fa(31, vector<int>(n + 1, 0));
    vector<vector<node>> mul(31, vector<node>(n + 1, {1, 0}));
    for (int i = 1; i <= n; ++i) {
        fa[0][i] = p[i];
        mul[0][i] = mul[0][i] * (node){k[p[i]], b[p[i]]};
    }
    for (int i = 1; i <= 30; ++i) {
        for (int j = 1; j <= n; ++j) {
            fa[i][j] = fa[i - 1][fa[i - 1][j]];
            mul[i][j] = mul[i - 1][j] * mul[i - 1][fa[i - 1][j]];
            // if (i == 1) cout << mul[i][j].K << ' ' << mul[i][j].B << '\n';
        }
    }
    while (q--) {
        int x, l, y; cin >> x >> l >> y;
        node base = {1, 0};
        while (l) {
            for (int i = 30; i >= 0; --i) {
                if (l >= (1 << i)) {
                    l -= (1 << i);
                    base = base * mul[i][x];
                    x = fa[i][x];
                    break;
                }
            }
        }
        cout << mint(y) * base.fir + base.sec << '\n';
    }
}
/*
1
5 1
2 2 2 2 2
3 0 0 0 0
2 3 4 5 1
1 6 1
*/

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
