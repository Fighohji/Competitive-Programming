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

#define int long long


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> f{1};
    int now = 1;
    while ((__int128)now * k + 1 <= n) {
        f.push_back(now * k + 1);
        now = now * k + 1;
    }
    int Ans = 0;
    if (f.size() >= k + 1) {
        Ans += n - f[k]; 
        n = f[k];
    }  
    for (int i = (int)f.size() - 1; i >= 1; --i) {
        if (n >= f[i]) {
            Ans += f[i - 1] * (n / f[i]);
            n %= f[i];
        } 
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
