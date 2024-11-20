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
    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1\n";
        return;
    }
    int x = (n + 1) / 2;
    x++;
    cout << x << '\n';
    vector<vector<char>> G(x, vector<char>(x, '.'));
    for (int i = 1; i < x; ++i)
        G[i][0] = 'o', G[x - 1][i - 1] = 'o';
    if (n % 2 == 0) {
        G[x - 2][1] = 'o';
    }
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            cout << G[i][j];
        }
        cout << '\n';
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

