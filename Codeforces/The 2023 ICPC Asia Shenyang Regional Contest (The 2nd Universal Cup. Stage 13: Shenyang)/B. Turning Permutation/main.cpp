#include <algorithm>
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
    int n = 8;
    vector<int> p(n);
    iota(all(p), 0);
    vector<vector<int>> vec;
    do {
        vector<int> d(n);
        for (int i = 1; i < n; ++i)
            d[i] = p[i] - p[i - 1];
        bool flag = 0;
        for (int i = 2; i < n; ++i) {
            if (d[i] * d[i - 1] > 0) {
                flag = 1;
                break;
            }
        }
        if (flag) continue;
        vector<int> q(n);
        for (int i = 0; i < n; ++i)
            q[p[i]] = i;
        vec.push_back(q);
    } while (next_permutation(all(p)));
    sort(all(vec));
    for (auto i : vec) {
        for (int j = 0; j < n; ++j) {
            cout << i[j] << " \n"[j == n - 1];
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
