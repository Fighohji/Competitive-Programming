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

unordered_map<string, vector<string>> G;
unordered_map<string, int> deg, dep;
unordered_map<string, array<string, 10>> fa;
set<string> peo;



void dfs(string u, string p) {
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for (auto v : G[u]) {
        dfs(v, u);
    }
}

void init_lca() {
    for (int j = 1; j < 10; ++j)
        for (auto i : peo)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
string get_lca(string u, string v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 9; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i))
            v = fa[v][i];
    if (u == v) return u;
    for (int i = 9; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        string p; cin >> p;
        peo.insert(p);
        int k; cin >> k;
        for (int j = 1; j <= k; ++j) {
            string s; cin >> s;
            G[p].pb(s);
            deg[s]++;
            peo.insert(s);
        }
    }
    string root;
    for (auto i : peo)
        if (!deg[i])
            root = i;

    dfs(root, "");
    init_lca();
    while (m--) {
        string u, v; cin >> u >> v;
        string lca = get_lca(u, v);
        if (lca == u || lca == v) {
            if (dep[u] < dep[v]) swap(u, v);
            int dif = dep[u] - dep[v];
            if (dif == 1) {
                cout << u << " is the child of " << v << '\n';
            } else {
                cout << u << " is the ";
                for (int i = 2; i < dif; ++i) {
                    cout << "great ";
                }
                cout << "grandchild of " << v << '\n';
            }
        } else {
            int D = dep[u] - dep[lca];
            int E = dep[v] - dep[lca];
            if (D == E) {
                if (D == 1) {
                    cout << u << " and " << v << " are siblings\n";
                } else if (D % 10 == 2 && (D - 1) / 10 != 1){
                    cout << u << " and " << v << " are ";
                    if ((D - 1) / 10 != 0) cout << (D - 1) / 10;
                    cout << "1st cousins\n";
                } else if (D % 10 == 3 && (D - 1) / 10 != 1) {
                    cout << u << " and " << v << " are ";
                    if ((D - 1) / 10 != 0) cout << (D - 1) / 10;
                    cout << "2nd cousins\n";
                } else if (D % 10 == 4 && (D - 1) / 10 != 1) {
                    cout << u << " and " << v << " are ";
                    if ((D - 1) / 10 != 0) cout << (D - 1) / 10;
                    cout << "3rd cousins\n";
                } else {
                    cout << u << " and " << v << " are ";
                    cout << D - 1 << "th";
                    cout << " cousins\n";
                }
            } else {
                int Min = min(D, E);
                int dif = abs(D - E);
                if (Min == 2 && (Min - 1) / 10 != 1){
                    cout << u << " and " << v << " are ";
                    if ((Min - 1) / 10 != 0) cout << (Min - 1) / 10;
                    cout << "1st cousins, ";
                } else if (Min == 3 && (Min - 1) / 10 != 1) {
                    cout << u << " and " << v << " are ";
                    if ((Min - 1) / 10 != 0) cout << (Min - 1) / 10;
                    cout << "2nd cousins, ";
                } else if (Min == 4 && (Min - 1) / 10 != 1) {
                    cout << u << " and " << v << " are ";
                    if ((Min - 1) / 10 != 0) cout << (Min - 1) / 10;
                    cout << "3rd cousins, ";
                } else {
                    cout << u << " and " << v << " are ";
                    cout << Min - 1 << "th";
                    cout << " cousins, ";
                }
                if (dif == 1) {
                    cout << "1 time removed\n";
                } else {
                    cout << dif << ' ' << "times removed\n";
                }
            }
        }
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
