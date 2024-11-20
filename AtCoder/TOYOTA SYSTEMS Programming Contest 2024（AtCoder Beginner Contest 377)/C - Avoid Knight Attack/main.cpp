#include <climits>
#include <iostream>
#include <random>
#include <set>
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
    { 1,  2},
    {-1,  2},
    { 2,  1},
    {-2,  1},
    {-2, -1},
    {-1, -2},
    { 1, -2},
    { 2, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int Ans = n * n;
    set<pii> s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        s.insert({a, b});
        for (int j = 0; j < 8; ++j) {
            int nx = a + dir[j][0];
            int ny = b + dir[j][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n)
                s.insert({nx, ny});
        }
    }
    cout << Ans - s.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
