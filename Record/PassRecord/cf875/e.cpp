#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <random>
#include <cctype>
#include <cstdio>
#include <chrono>
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
 
mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 6e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool BEGIN;

int norm(int x)
{
    if (x < 0) {
        x += mod;
    }
    if (x >= mod) {
        x -= mod;
    }
    return x;
}
template<class T>
T qpow(T base, ll power)
{
    T res = 1;
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}

struct mint
{
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



mint fac[maxn];
mint inv[maxn];
mint cat[maxn];

mint C(int n, int m)
{
    return fac[n] * inv[m] * inv[n - m];
}
void init(int n)
{
    fac[1] = inv[1] = inv[0] = fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = i * fac[i - 1];
    inv[n] = fac[n].inv();
    for (int i = n - 1; i >= 1; --i) inv[i] = (i + 1) * inv[i + 1];
    cat[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cat[i] = C(2 * i, i) * ((mint)(i + 1)).inv(); 
    }
}

int get_rand() {
    return (rand() * rand() % INF + INF) % INF;
}

void solve(int cas) {
    int n, k; cin >> n >> k;
    vector<ull> pre(n + 2, 0);
    mint ans = 1;
    for (int i = 1; i <= k; ++i) {
        int l, r; cin >> l >> r;
        auto num = dist(rnd);
        pre[l] ^= num;
        pre[r + 1] ^= num;
        if ((r - l + 1) & 1) ans = 0;
    }
    map<ull, int> buc;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] ^ pre[i];
        buc[pre[i]]++;
    }
    if (ans.val() == 0) cout << ans << '\n';
    else {
        for (auto [x, y] : buc) {
            if (y % 2) ans = 0;
            else ans *= cat[y / 2];
        }
        cout << ans << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    srand(time(0));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init(300000);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

