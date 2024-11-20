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

bool BEGIN;
void solve(int cas) {
    const int K = 3;
    struct Quota {
        int l, r;
        vector<int> quota, id;
        Quota(int _size) {
            l = 0, r = _size - 1;
            quota.resize(_size);
            id.resize(_size);
            iota(all(id), 0);
        }
        void init(int _size) { l = 0, r = _size - 1; }
        int getNxt(int u, int checkVal) {
            assert(u >= 0);
            if (l > r) return -1;
            if (quota[id[l]] < quota[u] - checkVal) {
                return id[l++];
            }
            if (quota[id[r]] > quota[u] + checkVal) {
                return id[r--];
            }
            return -1;
        }
        void Sort() {
            sort(all(id), [&](int x, int y) {
                return quota[x] < quota[y];
            });
        }
    };
    int n; cin >> n;
    vector<Quota> quotas(K, Quota(n << 1)); 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < K; ++j) {
            cin >> quotas[j].quota[i];
        }
        for (int j = 0; j < K; ++j) {
            cin >> quotas[j].quota[i + n];
        }
    }
    for (int i = 0; i < K; ++i) quotas[i].Sort();
    int l = 0, r = 0;
    for (int i = 0; i < K; ++i) {
        r = max(r, quotas[i].quota[2 * n - 1] - quotas[i].quota[0]);
    }
    auto check = [&](int checkVal) -> bool {
        vector<bool> vis(n << 1, 0);
        vector<int> stk((n << 1) + 1, 0), sccnum(n << 1, 0);
        int top = 0, cnt = 0;
        auto dfs = [&](auto self, int u) {
            if (vis[u]) return ;
            vis[u] = 1;
            for (int i = 0; i < K; ++i) {
                while (1) {
                    int nxt = quotas[i].getNxt(u, checkVal);
                    if (nxt == -1) break;
                    self(self, nxt < n ? nxt + n : nxt - n);
                }
            }
            stk[top++] = u;
        };
        auto DFS = [&](auto self, int u) {
            if (!vis[u]) return ;  
            vis[u] = 0;
            sccnum[u] = cnt;
            for (int i = 0; i < K; ++i) {
                while (1) {
                    int nxt = quotas[i].getNxt(u < n ? u + n : u - n, checkVal);
                    if (nxt == -1) break;
                    self(self, nxt);
                }
            }
        };
        for (int i = 0; i < K; ++i) quotas[i].init(n << 1);
        for (int i = 0; i < 2 * n; ++i) dfs(dfs, i);
        for (int i = 0; i < K; ++i) quotas[i].init(n << 1);
        for (int i = top - 1; i >= 0; --i) {
            if (!vis[stk[i]]) continue;
            cnt++;
            DFS(DFS, stk[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (sccnum[i] == sccnum[i + n]) return 0;
        }
        return 1;
    };
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
    // freopen("1009.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    int T; cin >> T; while (T--)
    solve(1);
    // fclose(stdin);
    // fclose(stdout);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

