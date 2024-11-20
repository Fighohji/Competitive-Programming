#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
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
    map<int, vector<int>> X, Y;
    vector<int> x(k + 1), y(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> x[i] >> y[i];
        X[x[i]].push_back(y[i]);
        Y[y[i]].push_back(x[i]);
    }
    int Ans = 0, sx = 0, sy = 0;
    for (auto &[_, vec] : X) {
        sort(all(vec));
        int las = 0;
        vec.push_back(m + 1);
        for (int i = 0; i < vec.size(); ++i) {
            int tot = max(i, (int)vec.size() - 1 - i);
            if (vec[i] - las > 1 && tot > Ans) {
                Ans = tot;
                sx = _, sy = vec[i] - 1;
            }
            las = vec[i];
        }
    }
    for (auto &[_, vec] : Y) {
        sort(all(vec));
        int las = 0;
        vec.push_back(n + 1);
        for (int i = 0; i < vec.size(); ++i) {
            int tot = max(i, (int)vec.size() - 1 - i);
            if (vec[i] - las > 1 && tot > Ans) {
                Ans = tot;
                sx = vec[i] - 1, sy = _;
            }
            las = vec[i];
        }
    }
    cout << Ans << '\n';
    cout << sx << ' ' << sy << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
