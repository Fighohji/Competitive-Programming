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

void solve() {
    int n; cin >> n;
    int m = 1, ans = 0;
    while (m < n) {
        m <<= 1;
        ans++;
    }
    vector<vector<int>> Ans(ans, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < ans; ++j)
            if (1 << j & i)
                Ans[j][i] = 1;
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        cout << count(all(Ans[i]), 1);
        for (int j = 0; j < n; ++j)
            if (Ans[i][j])
                cout << " " << j + 1;
        cout << endl;
    }
    string s; cin >> s;
    reverse(all(s));
    cout << stoi(s, 0, 2) + 1 << endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
