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
int n;
int ans;
int vis1[maxn], vis2[maxn];
bool vis[maxn];

void solve(int cas) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; ++i)
        e[i].clear(), vis1[i] = 0, vis2[i] = 0;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].eb(v, i);
        e[v].eb(u, i);
    }
    queue<pii> q1, q2;
    q1.emplace(1, 0);
    vis2[1] = 1;
    vis1[1] = 1;
    while (1) {
        bool f = 0;
        while (!q1.empty()) {
            auto [u, id] = q1.front(); q1.pop();
            // cout << u << ' ' << id << '\n';
            for (auto [v, nid] : e[u]) {
                if (vis1[v]) continue;
                if (nid > id) {
                    q1.emplace(v, nid);
                    vis1[v] = 1;
                    f = 1;
                }
                if (!vis2[v] && nid > id) {
                    q2.emplace(v, 0);
                    vis2[v] = 1;
                }
            }
        }
        // split
        if (q2.empty()) break;
        if (f) ans++;
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    cout << ans << '\n';
    // split
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _; cin >> _; while (_--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
