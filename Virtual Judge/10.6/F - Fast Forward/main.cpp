#include <array>
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
    int n, c;
    cin >> n >> c;
    vector<int> pre(2 * n + 1), d(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    for (int i = 1; i <= 2 * n; ++i) {
        pre[i] = pre[i - 1] + d[i];
    }
    vector<array<int, 21>> fa(2 * n + 3);
    for (int i = 1; i <= 2 * n + 2; ++i) {
        
        for (int j = 0; j < 21; ++j) {
            fa[i][j] = 2 * n + 2;
        }
    }
    for (int i = 1; i <= 2 * n; ++i) {
        int l = i, r = 2 * n;
        int pos = 2 * n + 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] - pre[i - 1] >= c) {
                pos = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        fa[i][0] = pos + 1; 
    }
    for (int i = 1; i < 21; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        int u = i;
        int Ans = 0;
        for (int j = 20; j >= 0; --j) {
            if (fa[u][j] <= i + n - 1) {
                Ans += (1 << j); 
                u = fa[u][j];
            }
        }
        cout << Ans << ' ';
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
