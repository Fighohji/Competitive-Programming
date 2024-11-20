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


void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> stk(n + 2);
    map<int, int> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            int col; cin >> col;
            s[col]++;
            stk[i].pb(col);
        }
    }
    int need = 0;
    for (auto i : s) {
        need += (i.sec + k - 1) / k;
    }
    if (need > n + 2) {
        cout << "NIE\n";
        return ;
    }
    cout << "TAK\n";
    vector<bool> vis(n + 2, 0);
    for (auto I : s) {
        auto [col, cnt] = I;
        for (int i = 1; i <= n; ++i) {
            while (!stk[i].empty()) {
                int p = stk[i].back(); stk[i].pop_back();
                if (p == col) {
                    for (int j = 0; j <= n + 1; ++j) {
                        if (SZ(stk[j]) < k) {
                            cout << i << ' ' << k << '\n';
                            stk[j].pb(col);
                            break;
                        }
                    }
                } else {
                    for (int j = n + 1; j >= 0; --j) {
                        if (SZ(stk[j]) < k) {
                            cout << i << ' ' << k << '\n';
                            stk[j].pb(col);
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            while (!stk[0].empty()) {
                int p = stk[0].back(); stk[0].pop_back();
                stk[i].pb(p);
                cout << 0 << ' ' << i << '\n';
            }
            vis[i] = 1;
            break;
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            while (!stk[n + 1].empty()) {
                int p = stk[n + 1].back(); stk[n + 1].pop_back();
                stk[i].pb(p);
                cout << n + 1 << ' ' << i << '\n';
            }
            break;
        }
    }
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
