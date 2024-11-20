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
    int n, q; cin >> n >> q;
    vector<pii> pre(n + q + 1);
    int now = n;
    for (int i = 1; i <= n; ++i) {
        pre[i] = {n - i + 1, 0};
    }
    pii po = {1, 0};
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            string s; cin >> s;
            if (s[0] == 'U') {
                po.sec += 1;
            } else if (s[0] == 'D') {
                po.sec -= 1;
            } else if (s[0] == 'L') {
                po.fir -= 1;
            } else {
                po.fir += 1;
            }
            pre[++now] = po;
        } else {
            int x; cin >> x;
            cout << pre[now - (x - 1)].fir << ' ' << pre[now - (x - 1)].sec << '\n';
        }
    }
    // split
    // for (int i = 1; i <= now; ++i) {
    //     cout << pre[i].fir << ' ' << pre[i].sec << '\n';
    // }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
