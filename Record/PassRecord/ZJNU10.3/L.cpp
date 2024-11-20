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
constexpr int mod = 1e9 + 7; //998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)



ll qpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inv2 = qpow(2, mod - 2);
ll q2[maxn], fac[maxn], ifac[maxn];
void init(int n)
{
    q2[0] = 1;
    fac[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        q2[i] = q2[i - 1] * (mod - inv2) % mod;
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[n] = qpow(fac[n], mod - 2);
    for(int i = n; i; --i) ifac[i - 1] = ifac[i] * i % mod;
}
ll C(int n, int m)
{
    if(m < 0 || n < m) return 0;
    return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
void solve() {
    int n; ll m;
    cin >> n >> m;
    if(n < m)
    {
        cout << 0 << '\n';
        return ;
    }
    if(n == m)
    {
        cout << 1ll * fac[n - 1] * inv2 % mod << '\n';
        return ;

    }
    ll k = n - m;
    ll res = 0;
    for(int i = 0; i <= k; ++i)
    {
        res = (res + C(k, i) * q2[i] % mod * C(n - i - 1, k - 1) % mod) % mod;
    }
    res = res * fac[n] % mod * ifac[k] % mod;
    cout << res << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init(100000);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
