#include <algorithm>
#include <array>
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

struct Fenwick {
    int MX;
    vector<ll> sum;
    Fenwick() {}
    Fenwick(int _MX) : MX(_MX) { sum = vector<ll>(_MX + 1); }
    void upd(int x, int val) {
        while (x <= MX) {
            sum[x] += val;
            x += lowbit(x);
        }
    }
    ll qry(int x) {
        ll res = 0;
        while (x) {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    mint Ans = 1;
    vector<pii> a(n);
    vector<int> tmp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        tmp.push_back(a[i].first);
        tmp.push_back(a[i].second);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 0; i < n; ++i) {
        a[i].first = lower_bound(all(tmp), a[i].first) - tmp.begin() + 1;
        a[i].second = lower_bound(all(tmp), a[i].second) - tmp.begin() + 1;
    }
    vector<int> L(tmp.size() + 1), R(tmp.size() + 1);
    for (int i = 0; i < n; ++i) {
        L[a[i].first]++;
        R[a[i].second]++;
    }
    int num = 0;
    for (int i = 1; i <= tmp.size(); ++i) {
        for (int j = 0; j < L[i]; ++j) {
            Ans *= mint(max(0, k - num));
            num++;
        }
        num -= R[i];
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
