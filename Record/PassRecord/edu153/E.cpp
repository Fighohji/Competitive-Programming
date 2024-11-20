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


void solve() {
    string s; cin >> s;
    int n = s.length();
    s = "~" + s;
    vector<int> pos[26][26];
    for (int i = 1; i < n; ++i) {
        pos[s[i] - 'a'][s[i + 1] - 'a'].pb(i);
    }
    vector dis(26, vector(26, vector<int>(n, -1)));
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j) {
            vector vis(26, vector<bool>(26));
            queue<int> q;
            vis[i][j] = 1;
            for (auto k : pos[i][j]) {
                q.push(k);
                dis[i][j][k] = 0;
            }
            while (!q.empty()) {
                int p = q.front(); q.pop();
                if (p - 1 > 0 && dis[i][j][p - 1] == -1) {
                    dis[i][j][p - 1] = dis[i][j][p] + 1;
                    q.push(p - 1);
                }
                if (p + 1 < n && dis[i][j][p + 1] == -1) {
                    dis[i][j][p + 1] = dis[i][j][p] + 1;
                    q.push(p + 1);
                }
                int l = s[p] - 'a', r = s[p + 1] - 'a';
                if (vis[l][r]) continue;
                vis[l][r] = 1;
                for (auto k : pos[l][r]) {
                    if (dis[i][j][k] == -1) {
                        dis[i][j][k] = dis[i][j][p] + 1;
                        q.push(k);
                    }
                }
            }
        }

    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        int ans = abs(r - l);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j) {
                if (pos[i][j].empty()) continue;
                ans = min(ans, dis[i][j][l] + dis[i][j][r] + 1);
            }
        cout << ans << '\n';
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
