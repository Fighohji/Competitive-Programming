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
    vector<int> a(n + 1), ans(n + 1), nxt(n + 1);
    int head = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == -1) {
            head = i;
            ans[i] = 1;
        } else {
            nxt[a[i]] = i;
        }
    }
    cout << head << ' ' << nxt[3] << '\n';
    int cnt = 1;
    while (nxt[head]) {
        head = nxt[head];
        ans[head] = ++cnt;
    }
    vector<int> Ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        Ans[ans[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << ' ';
    }

}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
