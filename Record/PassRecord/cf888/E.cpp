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


void solve(int cas) {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<bool> free(n + 1, 0);
    for (int i = 1; i <= k; ++i) {
        int id; cin >> id;
        free[id] = 1;
        a[id] = 0;
    }
    vector<vector<int>> e(n + 1), tmp(n + 1); 
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int m; cin >> m;
        for (int j = 1; j <= m; ++j) {
            int p; cin >> p;
            tmp[i].eb(p);
            if (free[i]) continue;
            if (!free[p]) {
                deg[i]++;
                e[p].eb(i);
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (free[i]) continue;
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        int res = 0;
        for (auto i : tmp[p]) {
            res += a[i];
        }
        if (SZ(tmp[p]) == 0) res = a[p];
        a[p] = min(a[p], res);
        for (auto i : e[p]) { 
            if (free[i]) continue;
            deg[i]--;
            if (!deg[i]) {
                q.push(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
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

