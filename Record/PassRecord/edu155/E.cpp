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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

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



void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    vector G(n + 1, vector<pii>());
    bool flag = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        if (p[i] != 1) flag = 1;
        G[p[i]].pb({i, i - 1});
    }
    if (!flag) {
        cout << 1 << endl;
        for (int i = 1; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << endl;
        int tmp; cin >> tmp;
        cout << 1 << endl;
        cin >> flag;
        return ;
    }
    vector<int> ans(n + 1, -1);
    bool f = 1;
    for (int i = 2; i <= n && f; ++i) {
        if (p[i] != 1 && SZ(G[p[i]]) == 1) {
            if (ans[i - 1] == 0) {
                f = 0;
                break;
            }
            ans[i - 1] = 1;
            int now = 1;
            int x = i;
            while (p[x] != 1) {
                now ^= 1;
                if (ans[p[x] - 1] == -1) {
                    ans[p[x] - 1] = now;
                } else {
                    if (ans[p[x] - 1] == now) break;
                    f = 0;
                    break;
                }
                x = p[x];
            }
        }
    }
    auto dfs = [&](auto &&dfs, int u, int p, int col = -1) -> void {
        for (auto [v, id] : G[u]) {
            if (ans[id] == -1) {
                if (col == -1) {
                    col = 0;
                }
                ans[id] = col;
            } else col = ans[id];
            dfs(dfs, v, u, col ^ 1);
        }
    };
    if (f) {
        dfs(dfs, 1, 0);
        cout << 2 << endl;
        for (int i = 1; i < n; ++i) {
            cout << ans[i] + 1 << ' ';
        }
        cout << endl;
        int op; cin >> op;
        while (1) {
            vector<int> cnt(2 + 1);
            for (int i = 1; i <= 2; ++i) {
                cin >> cnt[i];
            }
            if (cnt[1] == 0) {
                cout << 2 << endl;
            } else if (cnt[2] == 0) {
                cout << 1 << endl;
            } else {
                if (cnt[1] == cnt[2]) {
                    cout << 1 << endl;
                } else {
                    cout << (cnt[1] < cnt[2] ? 1 : 2) << endl;
                }
            }
            cin >> op;
            if (op != 0) break;
        }
        return ;
    }

    auto DFS = [&](auto &&DFS, int u, int p, int col = 0) -> void {
        for (auto [v, id] : G[u]) {
            ans[id] = col;
            DFS(DFS, v, u, (col + 1) % 3);
        }
    };
    DFS(DFS, 1, 0);
    cout << 3 << endl;
    for (int i = 1; i < n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
    int op; cin >> op;
    while (1) {
        vector<int> c;
        vector<int> cnt(3 + 1);
        for (int i = 1; i <= 3; ++i) {
            cin >> cnt[i];
        }
        for (int i = 1; i <= 3; ++i) {
            if (cnt[i]) c.pb(i);
        }
        if (SZ(c) == 1) {
            cout << c[0] << endl;
        } else {
            if (c[0] > c[1]) swap(c[0], c[1]);
            if (c[0] == 1 && c[1] == 3) {
                cout << 3 << endl;
            } else {
                cout << c[0] << endl;
            }
        }
        cin >> op;
        if (op != 0) break;
    }
    // assert(op == 1);
}

signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
