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

constexpr int N = 5e7 + 50;
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

int num[100000001];
 
bool vis[N];
int prime[N];
int cnt;
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        for (int j = i; j <= cnt; ++j) {
            if (1ll * prime[i] * prime[j] > 100000000) break;
            num[prime[i] * prime[j]] = 1;
        }
    }
    for (int i = 1; i <= 100000000; ++i)
        num[i] += num[i - 1];
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << num[r] - num[l - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    isprime(50000000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
