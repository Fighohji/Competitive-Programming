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

void solve() {
    int n;
    cin >> n;
    cout << "? ";
    cout << n << ' ';
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    int k;
    cin >> k;
    vector<int> v1(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> v1[i];
    }
    cout << "? ";
    cout << n / 2 * 2 << ' ';
    for (int i = 1, j = 1; i <= n / 2; i++, j++) {
        cout << j << ' ' << j << ' ';
    }
    cout << endl;
    int k1;
    cin >> k1;
    vector<int> v2(k1 + 1);
    for (int i = 1; i <= k1; i++) {
        cin >> v2[i];
    }
    cout << "? ";
    cout << n / 2 * 2 << ' ';
    for (int i = n / 2, j = n; i >= 1; i--, j--) {
        cout << j << ' ' << j << ' ';
    }
    cout << endl;
    int k2;
    cin >> k2;
    vector<int> v3(k2 + 1);
    for (int i = 1; i <= k2; i++) {
        cin >> v3[i];
    }
    vector<int> ans(n + 1);
    int p = 0, pre = 0;
    for (int i = 1; i <= n / 2; i++) {
        int c1 = 0;
        vector<int> vis(1001);
        while (1) {
            vis[v2[++p]]++;
            if (vis[v2[p]] == 2) {
                c1--;
            } else
                c1++;
            if (c1 == 0) {
                ans[i] = (p - pre) / 2;
                pre = p;
                break;
            }
        }
    }
    p = 0, pre = 0;
    for (int i = 1; i <= n / 2; i++) {
        int c1 = 0;
        vector<int> vis(1001);
        while (1) {
            vis[v3[++p]]++;
            if (vis[v3[p]] == 2) {
                c1--;
            } else
                c1++;
            if (c1 == 0) {
                ans[n - i + 1] = (p - pre) / 2;
                pre = p;
                break;
            }
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
        tot += ans[i];
    if (k != tot) { ans[n / 2 + 1] = k - tot; }
    pre = 1;
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
        for (int j = pre; j <= pre + ans[i] - 1; j++) {
            cout << v1[j] << ' ';
        }
        pre += ans[i];
    }
    cout << endl;
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
