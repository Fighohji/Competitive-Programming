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

#define int long long
/*
记录每种最少拿出的数量
总共能拿出的最少最大数量
每行其余能拿出的最大数量
*/
void solve() {
    int m; cin >> m;
    vector<int> n(m), l(m), r(m);
    vector a(m, vector<int>()), c(m, vector<int>()), res(m, vector<int>());
    map<int, int> Ans, oth;
    int Max = 0, Min = 0;
    for (int i = 0; i < m; ++i) {
        cin >> n[i] >> l[i] >> r[i];
        Min += l[i], Max += r[i];
        a[i].resize(n[i]);
        c[i].resize(n[i]);
        res[i].resize(n[i]);
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
            if (!Ans.count((a[i][j]))) Ans[a[i][j]] = 0;
        }
        int tot = 0;
        for (int j = 0; j < n[i]; ++j) {
            cin >> c[i][j];
            tot += c[i][j];
        }
        for (int j = 0; j < n[i]; ++j) {
            if (tot - c[i][j] <= l[i])
                Ans[a[i][j]] += l[i] - (tot - c[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int tot = 0;
        for (int j = 0; j < n[i]; ++j) tot += c[i][j];
        for (int j = 0; j < n[i]; ++j) {
            if (!oth.count(a[i][j])) oth[a[i][j]] = Max;
            if (tot - c[i][j] < r[i]) oth[a[i][j]] -= r[i] - (tot - c[i][j]);
        }
    }
    if (Max - Min + 1 > Ans.size()) {
        cout << 0 << '\n';
        return ;
    }
    for (int i = Min; i <= Max; ++i) {
        if (!Ans.count(i)) {
            cout << 0 << '\n';
            return ;
        }
    }
    int ans = LINF;
    for (int x = Min; x <= Max; ++x) {
        if (oth[x] < x - Ans[x]) {
            ans = min(ans, x - oth[x]);
        } else ans = min(ans, Ans[x]);
    }
    cout << ans << '\n';
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
