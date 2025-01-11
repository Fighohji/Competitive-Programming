#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

int norm(int x) {
    if (x < 0) { x += mod; }
    if (x >= mod) { x -= mod; }
    return x;
}
template <class T>
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
    mint inv() const { return qpow(*this, mod - 2); }
    mint &operator*=(const mint &rhs) {
        x = (ll)x * rhs.x % mod;
        return *this;
    }
    mint &operator+=(const mint &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    mint &operator-=(const mint &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    mint &operator/=(const mint &rhs) { return *this *= rhs.inv(); }
    friend mint operator*(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res *= rhs;
        return res;
    }
    friend mint operator+(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res += rhs;
        return res;
    }
    friend mint operator-(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res -= rhs;
        return res;
    }
    friend mint operator/(const mint &lhs, const mint &rhs) {
        mint res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, mint &a) {
        ll v;
        is >> v;
        a = mint(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        return os << a.val();
    }
};

vector<mint> fac;
vector<mint> inv;
vector<int> f[N];

void init(int n) {
    fac.resize(n + 1);
    inv.resize(n + 1);
    fac[1] = inv[1] = inv[0] = fac[0] = 1;
    for (int i = 1; i <= n; ++i)
        fac[i] = i * fac[i - 1];
    inv[n] = fac[n].inv();
    for (int i = n - 1; i >= 1; --i)
        inv[i] = (i + 1) * inv[i + 1];

    for (int i = 1; i <= n; ++i) {
        for (int j = i * 2; j <= n; j += i) {
            f[j].push_back(i);
        }
    }
}

mint C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * inv[m] * inv[n - m];
}

mint h[21][100001];
void solve() {
    int m, n;
    cin >> m >> n;
    init(m);
    for (int i = 1; i <= m; ++i)
        h[1][i] = mint(1);
    for (int j = 2; j <= 20; ++j) {
        for (int i = 1; i <= m; ++i) {
            for (auto p : f[i]) {
                h[j][i] += h[j - 1][p];
            }
        }
    }

    mint Ans = C(m, n) * n;
    for (int i = 1; i <= m; ++i) {
        for (int y = 1; y <= i && y <= 20; ++y) {
            Ans -= h[y][i] * C(m / i - 1, n - y);
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
