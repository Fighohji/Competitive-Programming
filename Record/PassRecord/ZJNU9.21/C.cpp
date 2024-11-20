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

bool vis[256][10005];

struct Operation {
    int op, v, k;
} inc[10005];
struct node {
    int id, val;
};
void solve() {
    int n; cin >> n;
    for (int i = 0; i < 256; ++i)
        for (int j = 0; j <= n + 1; ++j)
            vis[i][j] = 0;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        int v, k;
        if (s == "add") {
            cin >> v;
            inc[i].op = 1;
            inc[i].v = v;
        } else {
            cin >> v >> k;
            if (s == "beq") {
                inc[i] = {2, v, k};
            } else if (s == "bne") {
                inc[i] = {3, v, k};
            } else if (s == "blt") {
                inc[i] = {4, v, k};
            } else {
                inc[i] = {5, v, k};
            }
        }
    }
    queue<node> q;
    q.push({1, 0});
    while (!q.empty()) {
        auto [id, val] = q.front(); q.pop();
        if (vis[val][id]) continue;
        // cout << id << ' ' << val << '\n';
        vis[val][id] = 1;
        if (id == n + 1) {
            cout << "Yes\n";
            return ;
        }
        if (inc[id].op == 1) {
            q.push({id + 1, (val + inc[id].v) % 256});
        } else if (inc[id].op == 2) {
            if (val == inc[id].v)
                q.push({inc[id].k, val});
            else
                q.push({id + 1, val});
        } else if (inc[id].op == 3) {
            if (val != inc[id].v)
                q.push({inc[id].k, val});
            else
                q.push({id + 1, val});
        } else if (inc[id].op == 4) {
            if (val < inc[id].v)
                q.push({inc[id].k, val});
            else
                q.push({id + 1, val});
        } else {
            if (val > inc[id].v)
                q.push({inc[id].k, val});
            else
                q.push({id + 1, val});
        }
    }
    cout << "No\n";
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
