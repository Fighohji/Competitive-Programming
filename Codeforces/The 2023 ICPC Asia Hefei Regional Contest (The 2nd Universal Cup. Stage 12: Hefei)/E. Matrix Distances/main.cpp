#include <algorithm>
#include <cassert>
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

int a[1001][1001];

ll row[1000001][3], col[1000001][3];
ll cnt[1000001];
bool vis[1000001];
void solve() {
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    vector<int> tmp(n * m);
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            tmp[idx++] = a[i][j];
        }
    }

    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] = lower_bound(all(tmp), a[i][j]) - tmp.begin() + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt[a[i][j]]++;
        }
        for (int j = 1; j <= m; ++j) {
            int x = a[i][j];
            int y = cnt[x];
            if (vis[x]) continue;
            vis[x] = 1;
            if (row[x][1]) {
                ll _pre = row[x][0];
                ll _c = row[x][1];
                ll _dis = row[x][2];
                ll dis = i - _dis;
                ans += _pre * y + dis * _c * y;
                ll pre = _pre + dis * _c;
                ll c = _c + y;
                row[x][0] = pre;
                row[x][1] = c;
                row[x][2] = i;
            } else {
                row[x][0] = 0, row[x][1] = y, row[x][2] = i;
            }
        }
        for (int j = 1; j <= m; ++j) {
            cnt[a[i][j]]--;
            vis[a[i][j]] = 0;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            cnt[a[i][j]]++;
        }
        for (int i = 1; i <= n; ++i) {
            int x = a[i][j];
            int y = cnt[x];
            if (vis[x]) continue;
            vis[x] = 1;
            if (col[x][1]) {
                ll _pre = col[x][0];
                ll _c = col[x][1];
                ll _dis = col[x][2];
                ll dis = j - _dis;
                ans += _pre * y + dis * _c * y;
                ll pre = _pre + dis * _c;
                ll c = _c + y;
                col[x][0] = pre;
                col[x][1] = c;
                col[x][2] = j;
            } else {
                col[x][0] = 0, col[x][1] = y, col[x][2] = j;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cnt[a[i][j]]--;
            vis[a[i][j]] = 0;
        }
    }
    cout << ans * 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
