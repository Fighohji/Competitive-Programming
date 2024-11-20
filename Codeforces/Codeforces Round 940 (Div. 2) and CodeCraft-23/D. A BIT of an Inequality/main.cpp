#include <array>
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
constexpr int dir[8][2] = {
    {-1,  0},
    {-1,  1},
    { 0,  1},
    { 1,  1},
    { 1,  0},
    { 1, -1},
    { 0, -1},
    {-1, -1}
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

// pre[x - 1] ^ pre[z] ^ a[y] > pre[x - 1] ^ pre[z]

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    vector<array<int, 30>> cntl(n + 2), cntr(n + 2);
    for (int i = 1; i <= n; ++i) {
        cntl[i] = cntl[i - 1];
        for (int j = 0; j < 30; ++j) {
            cntl[i][j] += (pre[i] >> j & 1);
        }
    }
    ll Ans = 0;
    for (int i = 1; i <= n; ++i) {
        int hi = 0;
        for (int j = 0; j < 30; ++j)
            if (1 << j & a[i]) {
                hi = j;
            }
        Ans += 1ll * cntl[i - 1][hi] * (cntl[n][hi] - cntl[i - 1][hi]);
        Ans += 1ll * (i - cntl[i - 1][hi]) * (n - i + 1 - cntl[n][hi] + cntl[i - 1][hi]);
    }
    cout << Ans << '\n';
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
