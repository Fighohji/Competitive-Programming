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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool BEGIN;

vector<int> e[maxn];
int n;
int deg[maxn];
bool vis[maxn];
int ans[maxn];
void solve(int cas) {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1)
            q.push(i);
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        if (vis[p]) continue;
        int k = -1;
        for (auto v : e[p]) {
            if (vis[v]) continue;
            k = v;
            break;
        }
        for (auto v : e[k]) {
            if (vis[v]) continue;
            vis[v] = 1;
            ans[k]++;
            deg[v]--;
            deg[k]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        if (ans[i])
            tmp.pb(ans[i]);
    }
    sort(all(tmp));
    for (auto i : tmp) cout << i << ' ';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
