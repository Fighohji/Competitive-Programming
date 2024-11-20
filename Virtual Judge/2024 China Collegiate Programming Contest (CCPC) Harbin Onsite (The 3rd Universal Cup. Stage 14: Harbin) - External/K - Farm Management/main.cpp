#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a(n + 1, array<int, 3>{});
    vector<int> suf(n + 2), cnt(n + 2), lpre(n + 1), lcnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
        }
    }
    sort(all(a));
    for (int i = n; i >= 1; --i) {
        suf[i] = a[i][2] - a[i][1];
        cnt[i] = cnt[i + 1] + suf[i];
        suf[i] = suf[i + 1] + suf[i] * a[i][0];
    }
    for (int i = 1; i <= n; ++i) {
        lcnt[i] = lcnt[i - 1] + a[i][1];
        lpre[i] = lpre[i - 1] + a[i][1] * a[i][0];
    }
    int Ans = lpre[n];
    int c = m - lcnt[n];
    for (int i = n; i >= 1 && c; --i) {
        Ans += min(c, a[i][2] - a[i][1]) * a[i][0];
        c -= min(c, a[i][2] - a[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        int l = i + 1, r = n;
        int pos = n + 1;
        int res = m - lcnt[n] + a[i][1];
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (cnt[mid] <= res) {
                pos = mid; 
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int oth = res - cnt[pos];
        int tmp = suf[pos] + lpre[n] - a[i][0] * a[i][1] + (res - cnt[pos]) * a[pos - 1][0];
        Ans = max(Ans, tmp);
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
