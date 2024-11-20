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
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};




void solve() {
    int n; cin >> n;
    int Ans = 0;
    string s; cin >> s;
    int y; cin >> y;
    vector<int> c(4, -1);
    auto dfs = [&](auto self, int p, int val, bool flag) -> void {
        if (p == n) {
            Ans += (val <= y && val % 8 == 0);
            return ;
        }
        if (isdigit(s[p])) {
            if (!flag && s[p] == '0') return ;
            self(self, p + 1, val * 10 + s[p] - '0', 1);
        } else {
            if (isalpha(s[p]) && c[s[p] - 'a'] == -1) {
                for (int i = 0; i < 10; ++i) {
                    bool f = 1;
                    for (int j = 0; j < 4; ++j) {
                        if (j == s[p] - 'a') continue;
                        if (c[j] == i) f = 0;
                    }
                    if (!f) continue;
                    if (!flag && !i) continue;
                    if (isalpha(s[p])) c[s[p] - 'a'] = i;
                    self(self, p + 1, val * 10 + i, 1);
                    c[s[p] - 'a'] = -1;
                }
            } else if (isalpha(s[p]) && c[s[p] - 'a'] != -1) {
                self(self, p + 1, val * 10 + c[s[p] - 'a'], 1);
            } else {
                for (int i = 0; i < 10; ++i) {
                    if (!flag && !i) continue;
                    self(self, p + 1, val * 10 + i, 1);
                }
            }
        }
    };
    dfs(dfs, 0, 0, 0);
    if (n == 1 && (s[0] == '0' || s[0] == '_' || isalpha(s[0]))) Ans++;
    cout << Ans << '\n';
}
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
