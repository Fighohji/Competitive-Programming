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

struct Hash {
    ll seed, p;
    vector<ll> power, hash;
    Hash() {}
    Hash(const string &s, ll sd = 131, ll P = 1e9 + 7) {
        seed = sd, p = P;
        power.resize(s.length() + 1);
        hash.resize(s.length() + 1);
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ll get_hash(int l, int r) {
        l++, r++;
        ll a = hash[r];
        ll b = hash[l - 1] * power[r - l + 1] % p;
        return (a - b + p) % p;
    }
};
void solve() {
    int n, q, m, k;
    cin >> n >> q >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector<Hash> h(n);
    for (int i = 0; i < n; ++i)
        h[i] = Hash(s[i]);
    for (int i = 0; i < q; ++i) {
        string t;
        cin >> t;
        Hash ht(t);
        int Ans = 0;
        for (int y = 0; y < n; ++y) {
            int p = 0, j = 0;
            for (; j <= k && p < m;) {
                int l = p, r = m - 1;
                int pos = p;
                auto check = [&](int x) -> bool {
                    return ht.get_hash(p, x) == h[y].get_hash(p, x);
                };
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (check(mid)) {
                        pos = mid + 1;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                if (pos == m) {
                    p = pos;
                    break;
                }
                if (s[y][pos] != t[pos]) j++;
                p = pos + 1;
            }
            // cerr << i << ' ' << y << ' ' << p << '\n';
            Ans += (p == m && j <= k);
        }
        // cerr << "------\n";
        cout << Ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

