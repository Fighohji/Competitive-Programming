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

// 2 3 1 
// 3 1 2
// 2 3 1
//
// 1 3 2
// 1 2 3
//
// 3 1 2
//
// 3 2 1
// 1 2 3
//
// 2 1 3
// 1 2 3
//
// 2 3 4 1
// 3 4 1 2
// 1 2 3 4
//
// 3 2 4 1
// 4 2 1 3
// 3 2 4 1
//
// 4 3 1 2
// 2 1 4 3
// 1 2 3 4

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> tmp = p;
        for (int j = 1; j <= n; ++j) {
            tmp[j] = p[p[j]];
        }
        p = tmp;
        for (int j = 1; j <= n; ++j) {
            cerr << p[j] << " \n"[j == n];
        }
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
