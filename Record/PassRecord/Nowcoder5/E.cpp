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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct node {
    int l, r;
    bool f;
    bool operator<(const node &t) const {
        if (l == t.l) return r > t.r;
        return l < t.l;
    }
};
void solve(int cas) {
    int n, m; cin >> n >> m;
    vector<node> a(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> a[i].l >> a[i].r >> a[i].f;
        if (a[i].f && a[i].l == a[i].r) {
            cout << "-1\n";
            return ;
        }
    }
    vector<vector<int>> e(n + 1);
    vector<int> fa(n + 1);
    a[0] = {1, n, 0};
    sort(all(a));
    // for (int i = 0; i <= m; ++i) {
    //     cout << a[i].l << ' ' << a[i].r << '\n';
    // }
    for (int i = 1; i <= m; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (a[j].l <= a[i].l && a[j].r >= a[i].r) {
                e[j].pb(i);
                fa[i] = j;
            }
        }
    }
    vector<int> p(n + 1);
    iota(all(p), 0);
    vector<bool> vis(m + 1, 0);
    auto dfs = [&](auto self, int u) -> void{
        // if (vis[u] == a[u].f) return ;
        cout << u << '\n';
        for (auto v : e[u]) {
            self(self, v);
        }
        if (vis[u] ^ a[u].f) {
            if (SZ(e[u]) == 1) {
                int v = e[u][0];
                if (a[v].l == a[u].l && a[v].r == a[u].r) {
                    cout << u << ' ' << "-1\n";
                    exit(0);
                }
                if (a[v].l > a[u].l) {
                    swap(p[a[v].l], p[a[u].l]);
                    vis[u] = vis[u] ^ 1;
                    vis[fa[u]] = vis[fa[u]] ^ 1;
                } else {
                    swap(p[a[v].r], p[a[u].r]);
                    vis[u] = vis[u] ^ 1;
                    vis[fa[u]] = vis[fa[u]] ^ 1;
                }
            } else {
                swap(p[a[e[u][0]].l], p[a[e[u][1]].l]);
                vis[u] = vis[u] ^ 1;
                vis[fa[u]] = vis[fa[u]] ^ 1;
            }
        }
    };
    dfs(dfs, 0);
    for (int i = 1; i <= n; ++i) {
        cout << p[i] << ' ';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

