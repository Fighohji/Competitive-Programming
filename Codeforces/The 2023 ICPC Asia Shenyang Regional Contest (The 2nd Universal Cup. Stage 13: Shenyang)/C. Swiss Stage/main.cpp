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

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
        cout << 4 << '\n';
    } else if (x == 1 && y == 0) {
        cout << 3 << '\n';
    } else if (x == 0 && y == 1) {
        cout << 4 << '\n';
    } else if (x == 1 && y == 1) {
        cout << 3 << '\n';
    } else if (x == 1 && y == 2) {
        cout << 4 << '\n';
    } else if (x == 2 && y == 1) {
        cout << 2 << '\n';
    } else if (x == 2 && y == 0) {
        cout << 2 << '\n';
    } else if (x == 0 && y == 2) {
        cout << 6 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
