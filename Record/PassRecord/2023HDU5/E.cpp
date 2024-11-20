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

#define N 10000010
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
constexpr int maxn = 1e7 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
bool BEGIN;
// ll p[N],pp[N];
// ll ksm(ll x, ll y)
// {
//     ll ans=1;
//     while(y)
//     {
//         if(y&1) ans=ans*x%mod;
//         x=x*x%mod;
//         y>>=1;
//     }
//     return ans;
// }
// ll inv(ll x)
// {
//     return ksm(x,mod-2);
// }

// void init(ll n)
// {
//     p[0]=1;
//     for(ll i=1;i<=n;++i) p[i]=p[i-1]*i%mod;
//     pp[n]=inv(p[n]);
//     for(ll i=n-1;i>=0;--i) pp[i]=pp[i+1]*(i+1)%mod;
// }
// ll C(ll n,ll m)
// {
//     if(n<m) return 0;
//     return p[n]*pp[m]%mod*pp[n-m]%mod;
// }
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



mint fac[maxn];
mint inv[maxn];

void init(int n) {
    fac[1] = inv[1] = inv[0] = fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = i * fac[i - 1];
    inv[n] = fac[n].inv();
    for (int i = n - 1; i >= 1; --i) inv[i] = (i + 1) * inv[i + 1];
}

mint C(int n, int m) {
    return fac[n] * inv[m] * inv[n - m];
}

ll n,m,a,b;
void solve(int cas) {
    cin>>n>>m>>a>>b;
    // mint det=a*b.inv();
    mint fm=(qpow((mint)b,n)).inv();
    mint ans=0;
    mint pre=0;
    mint pa=1,pb=qpow((mint)(b-a),n);
    mint invb=((mint)(b-a)).inv();
    for(int i=1;i<=n;++i)
    {
        pa=pa*a;pb=pb*invb;
        mint p=C(n,i)*pa*pb*fm;
        pre=(pre+qpow((mint)i,m));

        ans=(ans+pre*p);
    }
    cout<<ans<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init(10000000);

    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
