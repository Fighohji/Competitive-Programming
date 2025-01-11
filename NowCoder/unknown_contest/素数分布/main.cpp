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

int vis[N];
int prime[N];
int cnt;
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        int flag = 1;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        vis[i] = vis[i - 1] + flag;
    }
}
void solve() {
    int x;
    cin >> x;
    cout << vis[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    isprime(100000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
