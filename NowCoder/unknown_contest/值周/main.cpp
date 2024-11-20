#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <cassert>
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

int tmp[3000100];

void solve() {
    int l, m;
    cin >> l >> m;
    vector<int> x(m), y(m);
    int len = 0;
    tmp[++len] = 0;
    tmp[++len] = l + 1;
    for (int i = 0; i < m; ++i) {
        cin >> x[i] >> y[i];
        tmp[++len] = x[i];
        tmp[++len] = y[i];
        tmp[++len] = y[i] + 1;
    }
    sort(tmp + 1, tmp + 1 + len);
    len = unique(tmp + 1, tmp + 1 + len) - tmp;
    vector<int> pre(len);  
    for (int i = 0; i < m; ++i) {
        x[i] = lower_bound(tmp + 1, tmp + len, x[i]) - tmp;
        y[i] = lower_bound(tmp + 1, tmp + len, y[i]) - tmp;
        pre[x[i]]++, pre[y[i] + 1]--;
    }
    int Ans = 0;
    for (int i = 1; i < len - 1; ++i) {
        pre[i] += pre[i - 1];
        if (!pre[i]) {
            Ans += tmp[i + 1] - tmp[i];
        }
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
