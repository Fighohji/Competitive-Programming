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
    vector<int> p(k), c(k);
    vector<int> Ans(m + 1), in(m + 1, -1), out(m + 1, -1);
    for (int i = 0; i < k; ++i) {
        cin >> p[i] >> c[i];
        if (in[c[i]] == -1) {
            in[c[i]] = p[i];
        } else {
            out[c[i]] = p[i];
            Ans[c[i]] += (in[c[i]] == out[c[i]] ? 100 : abs(in[c[i]] - out[c[i]]));
            in[c[i]] = out[c[i]] = -1;
        }
    }
    for (int i = 1; i <= m; ++i) {
        if (in[i] != -1 && out[i] == -1) {
            Ans[i] += 100;
        }
    }
    for (int i = 1; i <= m; ++i) {
        cout << Ans[i] << ' ';
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
