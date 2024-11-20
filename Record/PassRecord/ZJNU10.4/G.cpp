#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
#define db long double
#define il inline
#define fir first
#define sec second
#define eps (1e-12)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

void solve() {
    int n, k; cin >> n >> k;
    vector <ll> ansx(n, LINF), ansy(n, LINF);
    vector a(n, vector<int>(n));
    vector buc(k + 1, vector<tuple<int, int, int>>());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            buc[a[i][j]].pb({i, j, 0});
        }
    for (auto [x, y, id] : buc[1]) {
        ansx[x] = 0, ansy[y] = 0;
    }
    for (int i = 2; i <= k; ++i) {
        vector<ll> Ansx(n, LINF), Ansy(n, LINF);
        for (auto [x, y, id] : buc[i]) {
            ll tmp = LINF;
            for (int j = 0; j < n; ++j) {
                tmp = min(tmp, ansx[j] + (j - x) * (j - x));
                tmp = min(tmp, ansy[j] + (j - y) * (j - y));
            }
            Ansx[x] = min(Ansx[x], tmp);
            Ansy[y] = min(Ansy[y], tmp);
        }
        ansx = Ansx, ansy = Ansy;
    }
    ll ans = min(*min_element(all(ansx)), *min_element(all(ansy)));
    if (ans == LINF) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
