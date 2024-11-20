#include <climits>
#include <cstdlib>
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
    auto work = [&](int a, int b, int c, int d) -> void {
        if (a >= c && b >= d) {
            cout << "YES\n";
            exit(0);
        } 
        for (double i = 0; i <= min(a, c); i += 0.0001) {
            double j = sqrt(c * c - i * i); 
            double h = d * (j / c);
            double w = d * (i / c);
            if (h + i <= a && w + j <= b) {
                // cout << i << '\n';
                cout << "YES\n";
                exit(0);
            }
        }
    };
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    work(a, b, c, d);
    work(b, a, c, d);
    work(a, b, d, c);
    work(b, a, d, c);
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
