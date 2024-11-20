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

int fa[maxn];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) fa[i] = i;
    vector<pii> edge(m + 1);
    int las = -1;
    int head;
    for (int i = 1; i <= m; ++i) {
        cin >> edge[i].fir >> edge[i].sec;
        if (las != -1) continue;
        if (find(edge[i].fir) != find(edge[i].sec)) {
            fa[find(edge[i].fir)] = edge[i].sec;
        } else {
            head = find(edge[i].fir);
            las = i;
        }
    }
    vector G(n + 1, vector<int>());
    for (int i = 1; i <= las; ++i) {
        G[edge[i].fir].pb(edge[i].sec);
        G[edge[i].sec].pb(edge[i].fir);
    }
    // cout << las << '\n';
    if (las == -1) {
        cout << "-1\n";
        return;
    }
    vector<int> Ans;
    vector<bool> vis(n + 1);
    int st;
    vector<int> stk;
    auto dfs = [&](auto &&dfs, int u, int p) -> bool {
        if (vis[u]) {
            st = u;
            return 1;
        }
        vis[u] = 1;
        stk.pb(u);
        for (auto v : G[u]) {
            if (v == p) continue;
            if (dfs(dfs, v, u)) return 1;
        }
        vis[u] = 0;
        stk.pop_back();
        return 0;
    };
    dfs(dfs, head, 0);
    vector<bool> onCir(n + 1);
    bool flag = 0;
    for (int i = 0; i < stk.size(); ++i) {
        if (stk[i] == st) flag = 1;
        if (flag) onCir[stk[i]] = 1;
    }
    // for (int i = 1; i <= n; ++i) {
    //     if (onCir[i] == 1) {
    //         cout << i << ' ';
    //     }
    // }
    // cout << '\n';
    for (int i = 1; i <= las; ++i) {
        if (onCir[edge[i].fir] && onCir[edge[i].sec]) {
            Ans.pb(i);
        }
    }
    for (int i = 0; i < Ans.size(); ++i)
        cout << Ans[i] << " \n"[i == Ans.size() - 1];
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
