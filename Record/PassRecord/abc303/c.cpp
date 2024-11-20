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


void solve(int cas) {
    int n, m, h, k;
    map<pii, int> mp;
    string s;
    cin >> n >> m >> h >> k >> s;
    int x = 0, y = 0;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        mp[{u, v}] = 1;
    }
    for (int i = 0; i < n; ++i) {
        // cout << h << '\n';
        h--;
        if (h < 0) {
            cout << "No\n";
            return ;
        }
        if (s[i] == 'L') x--;
        if (s[i] == 'R') x++;
        if (s[i] == 'U') y++;
        if (s[i] == 'D') y--;
        // cout << x << ' ' << y << '\n';
        if (mp.count({x, y})) {
            if (h < k) {
                h = k;
                mp.erase({x, y});
            }
        }
    }
    cout << "Yes\n";
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
