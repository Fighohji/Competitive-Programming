#include <cstdlib>
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

db Max = 0;

void solve() {
    auto qry = [](int x) -> char {
        cout << "? " << x << endl;
        string tp; cin >> tp;
        return tp[0];
    };
    int n; cin >> n;
    vector<int> lo(n + 1, 1), hi(n + 1, n);
    int x = 1;
    for (int t = 1; t <= 20; ++t) {
        vector<int> order(n + 1);
        iota(all(order), 0);
        random_shuffle(order.begin() + 1, order.end());
        for (int i = 1; i <= n; ++i) {
            char tp = qry(order[i]);
            if (tp == '<') {
                hi[order[i]] = min(order[i], --x);
            } else if (tp == '>') {
                lo[order[i]] = max(order[i], ++x);
            } else {
                lo[order[i]] = x;
                hi[order[i]] = x;
            }
        }
    }
    vector<bool> vis(n + 1);
    vector<int> Ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (hi[i] == lo[i]) {
            vis[hi[i]] = 1;
            Ans[i] = hi[i];
        }
    }
    vector<int> id(n + 1);
    iota(all(id), 0);
    sort(id.begin(), id.end(), [&](int x, int y) {
        return (x > n / 2) ? (lo[x] > lo[y]) : (lo[x] < lo[y]);
    });
    for (int i = 1; i <= n; ++i) {
        int j = id[i];
        if (vis[j]) continue;
        while (1) {
            char tp = qry(j);
            if (tp == '=') {
                Ans[j] = x;
                break;
            } else if (tp == '<') {
                x = x - 1;
            } else {
                x = x + 1;
            }
        }
        Ans[j] = x;
    }
    cout << "!";
    for (int i = 1; i <= n; ++i) {
        cout << " " << Ans[i];
    }
    cout << endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    srand(time(nullptr));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
