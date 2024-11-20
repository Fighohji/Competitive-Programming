#include <cstdlib>
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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

bool endpos[maxn];
vector<pair<int, char>> e[maxn];
string Ans;
int col[maxn];
int cnt[maxn];

bool vis[maxn][2];

bool dfs(int u, bool flag) {
    int f = 0;
    if (col[u]) f = 1;
    // if (col[u] >= 2) flag = 1;
    if (vis[u][f]) return 0;
    if (f) flag = 1;
    vis[u][f] = 1;
    col[u]++;
    if (flag && endpos[u]) {
        cout << Ans << '\n';
        exit(0);
    }
    for (auto [v, C] : e[u]) {
        Ans += C;
        dfs(v, flag);
        Ans.pop_back();
    }
    col[u]--;
    return 0;
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        int a; cin >> a;
        endpos[a] = 1;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; string s;
        cin >> u >> v >> s;
        e[u].eb(v, s[0]);
    }
    if (dfs(1, 0)) {
        cout << Ans << '\n';
    } else {
        cout << "-1\n";
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
