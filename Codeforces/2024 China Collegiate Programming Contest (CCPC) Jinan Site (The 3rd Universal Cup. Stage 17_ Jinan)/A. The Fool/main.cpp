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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    string temp = s[0].substr(0, k);
    int cnt = 0;
    int sx, sy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m * k; j += k) {
            if (s[i].substr(j, k) != temp) {
                cnt++;
                sx = i, sy = j / k;
            }
        }
    }
    if (cnt == 1) {
        cout << sx + 1 << ' ' << sy + 1 << '\n';
    } else {
        cout << 1 << ' ' << 1 << '\n';
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
