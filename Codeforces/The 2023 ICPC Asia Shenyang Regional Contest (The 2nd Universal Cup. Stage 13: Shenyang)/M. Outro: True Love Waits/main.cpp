#include <climits>
#include <iostream>
#include <random>
#include <algorithm>
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
constexpr int mod = 1e9 + 7;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

ll qpow(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % mod;
        base = base * base % mod;
        power >>= 1;
    }
    return res;
}

void solve() {
    string s, t;
    cin >> s >> t;
    reverse(all(s));
    reverse(all(t));
    int n = s.length(), m = t.length();
    int k;
    cin >> k;
    vector<int> bs(max(s.length(), t.length()));
    if (bs.size() % 2) bs.push_back(0);
    auto bt = bs;
    int z = bs.size();
    for (int i = 0; i < n; ++i)
        bs[i] = s[i] - '0';
    for (int i = 0; i < m; ++i)
        bt[i] = t[i] - '0';
    for (int i = 0; i < z; ++i)
        bs[i] ^= bt[i];
    
    vector<ll> power(z + 1);
    power[0] = 1;
    for (int i = 1; i <= z; ++i) {
        power[i] = power[i - 1] * 4 % mod;
    }
    for (int i = 1; i <= z; ++i) {
        power[i] += power[i - 1];
        power[i] %= mod;
    }

    if (s == t) {
        if (k == 1) {
            cout << 0 << '\n';
        } else {
            cout << (qpow(4ll, k - 1) - 1) * 4 % mod * qpow(3, mod - 2) % mod << '\n';
        } 
        return;
    }

    ll Ans = 0;

    for (int i = 0; i < z; i += 2) {
        if (bs[i] == 0 && bs[i + 1] == 0) {
                     
        } else if (bs[i] == 0 && bs[i + 1] == 1) {
            Ans += 3ll * power[i / 2] % mod; 
            Ans %= mod;
        } else if (bs[i] == 1 && bs[i + 1] == 0) {
            Ans += 1ll * power[i / 2] % mod; 
            Ans %= mod;
        } else {
            Ans += 2ll * power[i / 2] % mod; 
            Ans %= mod;
        }
    }

    int zero = 0;
    while (zero < z && bs[zero] == 0) {
        zero++;
    }
    zero /= 2;
    if (k - 1 > zero) {
        cout << -1 << '\n';
    } else {
        Ans += (power[k - 1] - 1 + mod) % mod; 
        Ans %= mod;
        cout << Ans << "\n";
    }
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
