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

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), w(n + 1);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
        tot += w[i];
    }
    vector<int> p(n + 1), Max(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (w[i] > Max[a[i]]) {
            Max[a[i]] = w[i];
            p[a[i]] = i;
        }
    }
    int Ans = 0;
    vector<int> vis(n + 1);
    vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
        // cerr << p[i] << " \n"[i == n];
        vis[p[i]] = i;
        Ans += Max[i];
        if (p[i]) used[i] = 1;
        // cerr << vis[i] << ' ';
    }
    cout << tot - Ans << '\n';
    for (int i = 1, j = 1; i <= n; ++i) {
        if (vis[i]) continue;
        while (used[j])
            j++;
        vis[i] = j;
        used[j] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << vis[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
