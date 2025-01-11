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
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pos(1000001);
    for (int i = 2; i <= 1000000; ++i)
        pos[i].push_back(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; prime[j] * prime[j] <= a[i] && j <= cnt; ++j) {
            if (a[i] % prime[j] == 0) {
                pos[prime[j]].push_back(i);
                while (a[i] % prime[j] == 0)
                    a[i] /= prime[j];
            }
        }
        if (a[i] > 1) pos[a[i]].push_back(i);
    }
    int Ans = 0;
    for (int i = 2; i <= 1000000; ++i) {
        for (int k = 1; k < pos[i].size(); ++k)
            Ans += (n - pos[i][k] + 1) * (pos[i][k] - pos[i][k - 1]);
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    isprime(1000000);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
