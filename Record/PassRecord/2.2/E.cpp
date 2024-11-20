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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

struct node {
    int val, id;
    bool operator<(const node &t) const {
        if (val != t.val) return val > t.val;
        return id < t.id;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> edge(m);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        edge[i] = {u, v};
    }
    int Ans = n;
    int Max = 1;
    for (int i = 1; i <= m; ++i) Max *= 3;
    for (int sta = 0; sta < Max; ++sta) {
        vector<int> res(m);
        int base = 1;
        for (int j = 0; j < m; ++j) {
            res[j] = sta / base % 3;
            // cout << res[j] << " \n"[j == m - 1];
            base *= 3;
        }
        vector<node> s(n + 1);
        for (int j = 1; j <= n; ++j) {
            s[j] = {a[j], j};
        }
        for (int j = 0; j < m; ++j) {
            if (res[j] == 2) {
                s[edge[j].fir].val += 1;
                s[edge[j].sec].val += 1;
            } else {
                s[edge[j].fir].val += (res[j] ^ 1) * 3;
                s[edge[j].sec].val += res[j] * 3;
            }
        }
        sort(s.begin() + 1, s.end());
        for (int i = 1; i <= n; ++i) {
            // cout << s[i].val << ' ' << s[i].id << '\n';
            if (s[i].id == 1) {
                Ans = min(Ans, i);
            }
        }
    }
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
