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
    int n, m;
    cin >> n >> m;
    vector<int> p(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> p[i];
        if (i > 1) assert(p[i] != p[i - 1]);
    }
    vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1);
    for (int i = 1; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        assert(b[i] < a[i]);
    }
    for (int i = 1; i < m; ++i) {
        int l = p[i], r = p[i + 1];
        if (l > r) swap(l, r);
        d[l]++, d[r]--; 
    }
    int Ans = 0;
    for (int i = 1; i < n; ++i) {
        d[i] += d[i - 1];
        // Ans += min(a[i] * d[i], b[i] * d[i] + c[i]);
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
