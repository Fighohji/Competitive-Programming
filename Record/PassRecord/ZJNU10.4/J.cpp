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
    vector<string> S(n);
    for (int i = 0; i < n; ++i)
        cin >> S[i];

    vector G(k << 1, vector<int>());
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k; ++j) {
            if (S[i][j] == 'F') {
                for (int p = 0; p < k; ++p) {
                    if (p == j || S[i][p] == 'X') continue;
                    G[j * 2].pb(S[i][p] == 'T' ? p * 2 : p * 2 + 1);
                }
            } else if (S[i][j] == 'T') {
                for (int p = 0; p < k; ++p) {
                    if (p == j || S[i][p] == 'X') continue;
                    G[j * 2 + 1].pb(S[i][p] == 'T' ? p * 2 : p * 2 + 1);
                }
            }
        }

    vector <bool> vis(k << 1);
    vector<int> stk(k << 1); int top;
    auto dfs = [&](auto &&dfs, int u) -> bool {
        if (vis[u]) return 1;
        if (vis[u ^ 1]) return 0;
        vis[u] = 1;
        stk[top++] = u;
        for (auto v :  G[u]) {
            if (!dfs(dfs, v))
                return 0;
        }
        return 1;
    };
    bool flag = 1;
    for (int i = 0; i < 2 * k; i += 2) {
        if (!vis[i] && !vis[i + 1]) {
            top = 0;
            if (!dfs(dfs, i)) {
                while (top > 0) vis[stk[--top]] = 0;
                if (!dfs(dfs, i + 1)) {
                    flag = 0;
                    break;
                }
            }
        }
    }
    if (!flag) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < 2 * k; i += 2) {
            cout << (vis[i + 1] ? "T" : "F");
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
