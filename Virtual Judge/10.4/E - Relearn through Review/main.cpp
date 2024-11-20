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
    vector<int> a(n + 1), suf(n + 2), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = gcd(p[i - 1], a[i]);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = gcd(suf[i + 1], a[i]);
    }
    int pre = 0;
    int las = pre;
    int Ans = suf[1];
    for (int i = 1; i <= n; ++i) {
        pre = gcd(pre, a[i]);
        if (pre != las) {
            int g1 = 0, g2 = 0;
            for (int j = i; j <= n; ++j) {
                g2 = gcd(g2, a[j] + k);
                Ans = max(Ans, gcd(las, gcd(g2, suf[j + 1])));
            }
        }
        las = pre;
    }
    pre = 0, las = 0;
    for (int i = n; i >= 1; --i) {
        pre = gcd(pre, a[i]);
        if (pre != las) {
            int g1 = 0, g2 = 0;
            for (int j = i; j >= 1; --j) {
                g2 = gcd(g2, a[j] + k);
                Ans = max(Ans, gcd(las, gcd(g2, p[j - 1])));
            }
        }
        las = pre;
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
