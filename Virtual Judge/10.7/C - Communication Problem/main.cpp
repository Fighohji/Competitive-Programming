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

void work(int n)
{
    vector<int> a(n);
    for(int i = 0; i < n; ++i) a[i] = i + 1;
    vector<double> dp(n + 1);
    for(int i = 1; i < (1 << n); ++i)
    {
        double fc = 1, fr = 0;
        int cnt = 0;
        for(int j = 0; j < n; ++j)
        {
            if(!(i >> j & 1)) 
            {
                for(int k = 0; k < n; ++k)
                {
                    if(!(i >> k & 1)) continue;
                    if(a[k] % a[j] == 0) fr += 1;
                }
            }
            else 
            {
                cnt++;
                fc *= a[j];
            }
        }
        dp[cnt] = max(dp[cnt], 1.0 * fr / fc);
    }
    for(int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i == n];
}
void solve() {
    // for(int i =  1; i <= 10; ++i) work(i);
    // double fc = 1;
    // for(int i = 2; i <= 10; ++i)
    // {
    //     fc *= i;
    //     cout << (i - 1) / fc << '\n';
    // }
    int n; cin >> n;
    mint f = mint(1);
    for(int i = 2; i <= n; ++i)
    {
        f *= mint(i);
        cout << mint(i - 1) / f << ' '; 
    }
    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
