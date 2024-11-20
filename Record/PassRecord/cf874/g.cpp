#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <cstdio>
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
#define GG { cout << "NO\n"; return; }
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

bool BEGIN;

vector<pii> e[maxn];

int sz[maxn];
bool f;
vector<int> ans;
void dfs(int u, int p) {
    if (!f) return ;
    sz[u] = 1;
    vector<pii> tmp;
    int sum = 0;
    for (auto [v, id] : e[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (!f) return ;
        if (sz[v]) {
            if (sz[v] == 3) {
                ans.eb(id);
            } else {
                tmp.eb(sz[v], id);
                // sum += sz[v];
                sz[u] += sz[v];
            }
        }
    }
    if (SZ(tmp) > 2 || sz[u] > 3) {
        f = 0;
        return ;
    }
    
}

void solve(int cas) {
    int n; cin >> n;
    ans.clear();
    f = 1;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        sz[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].eb(v, i);
        e[v].eb(u, i);
    }
    if (n % 3) {
        cout << "-1\n";
        return ;
    }
    dfs(1, 0);
    if (!f) cout << "-1\n";
    else if (SZ(ans)) {
        cout << SZ(ans) << '\n';
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << 0 << '\n';
        cout << "\n";
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

