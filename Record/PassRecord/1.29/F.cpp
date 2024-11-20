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

constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<pii> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i].fir, a[i].sec = i;
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    sort(all(a), greater());
    vector nxt(m, vector<int>(n, n));
    for (int i = 0; i < m; ++i) {
        int r = 0;
        for (int l = 0; l < n; ++l, r = max(l, r)) {
            while (r < n && a[r].fir * (r - l + 1) < b[i]) ++r;
            nxt[i][l] = r;
            // cout << nxt[i][l] << " \n"[l == n - 1];
        }
    }
    vector<int> dp(1 << m, n), pre(1 << m);
    dp[0] = -1;
    for (int i = 0; i < (1 << m); ++i) {
        for (int j = 0; j < m; ++j) {
            if (1 << j & i || dp[i] >= n - 1) continue;
            if (dp[1 << j | i] > nxt[j][dp[i] + 1])
                dp[1 << j | i] = nxt[j][dp[i] + 1],
                pre[1 << j | i] = i;
        }
    }
    if (dp[(1 << m) - 1] == n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector Ans(m, vector<int>());
        int now = (1 << m) - 1;
        while (now) {
            int las = pre[now];
            int id = __builtin_ffs(now - las) - 1;
            for (int i = dp[las] + 1; i <= dp[now]; ++i)
                Ans[id].pb(a[i].sec);
            now = las;
        }
        for (int i = 0; i < m; ++i) {
            cout << SZ(Ans[i]);
            for (auto j : Ans[i])
                cout << " " << j + 1;
            cout << '\n';
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
