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
#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-8)
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


map<int, int> ability;
map<int, int> pointer;
map<int, vector<pii>> require;
vector<pii> award[maxn];
int cnt[maxn];

void solve() {
    int g; cin >> g;
    for (int i = 1; i <= g; ++i) {
        int t, u; cin >> t >> u;
        ability[t] += u;
    }
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        int m; cin >> m;
        cnt[i] = m;
        if (cnt[i] == 0) q.push(i);
        for (int j = 1; j <= m; ++j) {
            int a, b; cin >> a >> b;
            require[a].pb({b, i});
        }
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            int c, d; cin >> c >> d;
            award[i].pb({c, d});
        }
    }
    int ans = 0;
    for (auto &[x, y] : require) {
        sort(all(y));
        pointer[x] = 0;
        for (int j = 0; j < SZ(y); ++j) {
            if (ability[x] >= y[j].fir) {
                cnt[y[j].sec]--;
                if (cnt[y[j].sec] == 0) {
                    q.push(y[j].sec);
                }
                pointer[x]++;
            } else break;
        }
    }
    while (!q.empty()) {
        ans++;
        int p = q.front(); q.pop();
        for (auto [x, y] : award[p]) {
            ability[x] += y;
            for (int i = pointer[x]; i < SZ(require[x]); ++i) {
                if (require[x][i].fir > ability[x]) break;
                cnt[require[x][i].sec]--;
                if (cnt[require[x][i].sec] == 0) {
                    q.push(require[x][i].sec);
                }
                pointer[x]++;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
