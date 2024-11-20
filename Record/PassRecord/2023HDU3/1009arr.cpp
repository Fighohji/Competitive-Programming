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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

// #define int long long

bool BEGIN;
constexpr int K = 3;
int n;
struct Quota {
    int l, r;
    int id[maxn], quota[maxn];
    void init() { l = 1, r = 2 * n; }
    int getNxt(int u, int checkVal) {
        if (l > r) return 0;
        if (quota[id[l]] < quota[u] - checkVal) {
            return id[l++];
        }
        if (quota[id[r]] > quota[u] + checkVal) {
            return id[r--];
        }
        return 0;
    }
}quotas[K];

bool vis[maxn];
int stk[maxn], sccnum[maxn], top;
void dfs(int u, int checkVal) {
    cerr << u << "\n";
    if (vis[u]) return ;
    vis[u] = 1;
    for (int i = 0; i < K; ++i) {
        while (1) {
            int nxt = quotas[i].getNxt(u, checkVal);
            if (!nxt) break;
            if (nxt < 1 || nxt > 2 * n) {
                cerr << "dfs!@#@!#\n";
            }
            int y = nxt <= n ? nxt + n : nxt - n;
            // assert(y < 2 * n);
            if (y < 1 || y > 2 * n) {
                cerr << "dfsy!@#@!#\n";
            }
            if (!vis[y])
                dfs(y, checkVal);
        }
    }
    stk[++top] = u;
}
int cnt;
void DFS(int u, int checkVal) {
    if (!vis[u]) return ;
    vis[u] = 0;
    sccnum[u] = cnt;
    for (int i = 0; i < K; ++i) {
        while (1) {
            int y = u <= n ? u + n : u - n;
            if (y < 1 || y > 2 * n) {
                cerr << "y!@#@!#\n";
            }
            int nxt = quotas[i].getNxt(y, checkVal);
            if (!nxt) break;
            if (nxt < 1 || nxt > 2 * n) {
                cerr << "!@#@!#\n";
            }
            if (vis[nxt])
                DFS(nxt, checkVal);
        }
    }
}
bool check(int checkVal) {
    top = cnt = 0;
    for (int i = 0; i < K; ++i) quotas[i].init();
    for (int i = 1; i <= 2 * n; ++i) vis[i] = 0;
    for (int i = 1; i <= 2 * n; ++i) if (!vis[i]) dfs(i, checkVal);
    for (int i = 0; i < K; ++i) quotas[i].init();
    for (int i = top; i >= 1; --i) {
        if (!vis[stk[i]]) continue;
        cnt++;
        DFS(stk[i], checkVal);
    }
    for (int i = 1; i <= n; ++i) {
        if (sccnum[i] == sccnum[i + n]) return 0;
    }
    return 1;
}
void solve(int cas) {
    cin >> n;
    for (int i = 0; i < K; ++i) {
        for (int j = 1; j <= 2 * n; ++j) {
            quotas[i].id[j] = j;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> quotas[j].quota[i];
        }
        for (int j = 0; j < K; ++j) {
            cin >> quotas[j].quota[i + n];
        }
    }
    for (int i = 0; i < K; ++i) {
        sort(quotas[i].id + 1, quotas[i].id + 1 + 2 * n, [&](int x, int y) {
            return quotas[i].quota[x] < quotas[i].quota[y];
        });
    }
    int l = 0, r = 0;
    int mx = -INF, mn = INF;
    for (int i = 0; i < K; ++i) {
        mx = max(mx, quotas[i].quota[2 * n]);
        mn = min(mn, quotas[i].quota[1]);
    }
    r = mx - mn;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1 << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    freopen("1009.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    freopen("wrong.out", "w", stderr);
    int T; cin >> T; while (T--)
    solve(1);
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

