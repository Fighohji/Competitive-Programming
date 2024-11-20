#include <algorithm>
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
// z[i] = lcp(s, s[i...n - 1])
vector<int> z_function(const string &s) {
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max(0, r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

struct Fenwick {
    int MX;
    vector<mint> sum;
    Fenwick() {}
    Fenwick(int _MX) : MX(_MX) { sum = vector<mint>(_MX + 1); }
    void upd(int x, mint val) {
        x++;
        while (x <= MX) {
            sum[x] += val;
            x += lowbit(x);
        }
    }
    mint qry(int x) {
        x++;
        mint res = 0;
        while (x) {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    reverse(all(s));
    auto z = z_function(s);
    Fenwick f = Fenwick(n);
    vector<mint> power(2 * n + 1, mint(1));
    vector<mint> inv(2 * n + 1, mint(1));
    mint inv_114514 = qpow(mint(114514), mod - 2);
    inv[0] = 1;
    for (int i = 1; i <= 2 * n; ++i)
        inv[i] = inv[i - 1] * inv_114514;
    for (int i = 1; i <= 2 * n; ++i)
        power[i] = power[i - 1] * mint(114514);

    vector<int> w(n), id(n);
    for (int i = 0; i < n; ++i) {
        w[i] = i - z[i];
        id[i] = i;
    }
    sort(all(id), [&](int x, int y) {
        return w[x] < w[y];
    });
    mint Ans = 0;
    for (int i = 2, j = 0; i < n; ++i) {
        while (j < n && w[id[j]] <= i) {
            f.upd(id[j], inv[2 * id[j]]);
            j++;
        }
        Ans += (f.qry(min(n - 1, i + min(i - 1, z[i]))) - f.qry(i)) * power[n + i];
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
