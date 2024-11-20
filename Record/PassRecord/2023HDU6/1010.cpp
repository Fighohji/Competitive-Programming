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



void solve(int cas) {
    int n, q; cin >> n >> q;
    vector<int> k(n + 1), b(n + 1), p(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
        deg[p[i]]++;
    }
    queue<int> Q;
    for (int i = 0; i < n; ++i) {
        if (!deg[i]) Q.push(i);
    }
    while (!Q.empty()) {

    }
    vector<vector<int>> cir;
    int cnt = 0;
    vector<pii> id(n + 1);
    vector<bool> vis(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        int now = i;
        int c = 0;
        vector<int> tmp;
        while (!vis[now]) {
            vis[now] = 1;
            id[now] = {cnt, c++};
            tmp.eb(now);
            now = p[now];
        }
        cir.pb(tmp);
        cnt++;
    }

    vector<vector<pair<mint, mint>>> pre(cnt);
    for (int i = 0; i < cnt; ++i) {
        int len = 2 * SZ(cir[i]);
        int sz = len / 2;
        pre[i].resize(len);
        for (int j = 0; j < len; ++j) {
            mint K(k[cir[i][j % sz]]), B(b[cir[i][j % sz]]);
            // cout << K << ' ' << B << '\n';
            if (j == 0) pre[i][j] = mkp(K, B);
            else {
                pre[i][j] = mkp(pre[i][j - 1].fir * K, K * pre[i][j - 1].sec + B);
            }
            // cout << "pre is " << pre[i][j].fir << ' ' << pre[i][j].sec << '\n';
        }
    }
    while (q--) {
        int x, l, y; cin >> x >> l >> y;
        x--;
        x = p[x];
        int siz = SZ(cir[id[x].fir]);
        ll power = l / siz;
        ll mo = l % siz;
        // cout << power << ' ' << mo << " p and m\n";
        mint ans = 0;
        int head = id[x].sec, tail = id[x].sec + siz - 1;
        int Id = id[x].fir;
        pair<mint, mint> base = pre[Id][tail];
        // cout << base.fir << ' ' << base.sec << '\n';
        // cout << head << ' ' << tail << '\n';
        if (head > 0) {
            mint invk = qpow(pre[Id][head - 1].fir, mod - 2);
            base = (pair<mint, mint>){invk, -pre[Id][head - 1].sec * invk} * base;
        }
        base = qpow(base, power);
        // cout << base.fir << ' ' << base.sec << '\n';
        if (mo) {
            head = id[x].sec, tail = id[x].sec + mo - 1;
            Id = id[x].fir;
            pair<mint, mint> BASE = pre[Id][tail];
            // cout << BASE.fir << ' ' << BASE.sec << "BASE\n";
            if (head > 0) {
                mint invk = qpow(pre[Id][head - 1].fir, mod - 2);
                BASE = (pair<mint, mint>){invk, -pre[Id][head - 1].sec * invk} * BASE;
                // cout << BASE.fir << ' ' << BASE.sec << "BASE\n";
            }
            base = base * BASE;
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
