#include <climits>
#include <cmath>
#include <iomanip>
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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<double> L(n);
    for (int i = 0; i < n; ++i)
        cin >> L[i];
    double l = 0, r = 100000;
    auto check = [&](double x) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += floor(L[i] / x);
        }
        return cnt >= k;
    };
    while (r - l > 0.000001) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
