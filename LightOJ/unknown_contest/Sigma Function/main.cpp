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

constexpr int N = 1e6 + 50;
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

ll num[N << 1], tot;
constexpr ll M = 1000000000000ll;
void init() {
    num[++tot] = 1;
    for (ll i = 2; i <= M; i <<= 1) {
        num[++tot] = i;
    }
    for (int i = 3; i <= 1000000; i += 2) {
        ll x = 1ll * i * i;
        for (ll j = x; j <= M; j *= 2) {
            num[++tot] = j;
        }
    }
    sort(num + 1, num + 1 + tot);
}
int CAS;
void solve() {
    ll n;
    cin >> n;
    cout << n - (upper_bound(num + 1, num + 1 + tot, n) - num - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
