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
constexpr int mod = 998244353; /* 1e9 + 7 */
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




void solve(int cas) {
    int n; cin >> n;
    vector<int> a(n + 1), s(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    vector<vector<array<mint, 2>>> cnt(31, vector<array<mint, 2>>(n + 1, {0, 0}));
    for (int i = 0; i <= 30; ++i) {
        // cnt[i][0][0] = 1;
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = cnt[i][j - 1];
            cnt[i][j][s[j] >> i & 1] += 1;
        }
    }
    vector<mint> power(65, 0);
    power[0] = 1;
    for (int i = 1; i <= 64; ++i) {
        power[i] = power[i - 1] * 2;
    }
    mint ans = 0;
    vector<vector<array<mint, 2>>> suf(31, vector<array<mint, 2>>(n + 1, {0, 0}));
    for (int i = 0; i <= 30;++i) {
        for (int j = n - 1; j >= 1; --j) {
            if (a[j] >> i & 1) {
                suf[i][j] = suf[i][j + 1];
                swap(suf[i][j][0], suf[i][j][1]);
                suf[i][j][1] += power[i] * ((cnt[i][n][0] - cnt[i][j][0] + 1) * (cnt[i][n][1] - cnt[i][j][1]));
            } else {
                suf[i][j] = suf[i][j + 1];
                suf[i][j][0] += power[i] * ((cnt[i][n][0] - cnt[i][j][0] + 1) * (cnt[i][n][1] - cnt[i][j][1]));
            }
        }
    }
    for (int j = 2; j < n; ++j) { //R
        mint pre = 0, res = 0;
        for (int i = 0; i <= 30; ++i) {
            pre += power[i] * ((cnt[i][j - 1][0] + 1) * cnt[i][j - 1][1]);
            res += power[i] * suf[i][j][a[j] >> i & 1 ^ 1];
        }
        // cout << pre << ' ' << ans << '\n';
        ans += pre * res;
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
