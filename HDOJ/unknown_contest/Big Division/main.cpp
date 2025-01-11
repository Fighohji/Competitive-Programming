#include <cassert>
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

bool vis[N];
int prime[N];
int cnt;
vector<pii> fac[N];
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 2; i <= n; ++i) {
        int x = i;
        for (int j = 1; prime[j] * prime[j] <= n && j <= cnt; ++j) {
            if (x % prime[j] == 0) {
                int cnt = 0;
                while (x % prime[j] == 0) {
                    x /= prime[j];
                    cnt++;
                }
                fac[i].push_back({prime[j], cnt});
            }
        }
        if (x > 1) fac[i].push_back({x, 1});
    }
}
ll qpow(ll base, ll power) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base;
        base = base * base;
        power >>= 1;
    }
    return res;
}
int CAS;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    vector<int> X(1000001), Y(1000001);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (const auto &[x, y] : fac[a[i]]) {
            X[x] += y;
        }
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        for (const auto &[x, y] : fac[b[i]]) {
            Y[x] += y;
        }
    }
    ll AnsX = 1, AnsY = 1;
    for (int j = 1; j <= cnt; ++j) {
        int i = prime[j];
        if (X[i] > Y[i]) {
            X[i] -= Y[i];
            AnsX *= qpow(i, X[i]);
        } else {
            Y[i] -= X[i];
            AnsY *= qpow(i, Y[i]);
        }
    }
    assert(AnsX <= 2147483647 && AnsY <= 2147483647);
    cout << AnsX << " / " << AnsY << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vis[1] = 1;
    isprime(1000000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
