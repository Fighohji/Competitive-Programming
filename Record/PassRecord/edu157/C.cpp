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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll cnt[11][91][11][91];

void solve() {
    int n; cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    for (int i = 0; i < n; ++i) {
        int l = vec[i].length();
        vector<int> pre(l);
        for (int j = 0; j < l; ++j) {
            pre[j] = vec[i][j] - '0';
            if (j) pre[j] += pre[j - 1];
        }
        for (int j = 0; j < l; ++j)
            cnt[j + 1][pre[j]][l - j - 1][pre[l - 1] - pre[j]]++;
        cnt[0][0][l][pre[l - 1]]++;
    }
    ll ans = 0;
    for (int i = 2; i <= 10; i += 2) {
        for (int j = 0; j <= 45; ++j)
            ans += cnt[0][0][i / 2][j] * cnt[0][0][i / 2][j];
        for (int j = 1; j < i / 2; ++j)
            for (int k = 0; k <= 45; ++k)
                for (int p = k; p <= 45; ++p)
                    ans += cnt[0][0][j][k] * cnt[i / 2 - j][p - k][i / 2][p],
                    ans += cnt[i / 2][p][i / 2 - j][p - k] * cnt[0][0][j][k];
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
