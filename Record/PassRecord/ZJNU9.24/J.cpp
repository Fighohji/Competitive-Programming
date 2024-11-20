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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'


void solve()  {
    int n; cin >> n;
    vector<int> a(n + 1), c(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        deg[a[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        cout << p << ' ';
        deg[a[p]]--;
        if (!deg[a[p]]) {
            q.push(a[p]);
        }
    }
    vector<vector<int>> cir;
    int head = -1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0) {
            head = i;
            vector<int> tmp;
            while (deg[head]) {
                tmp.pb(head);
                deg[head]--;
                head = a[head];
            }
            cir.pb(tmp);
        }
    }

    for (int j = 0; j < SZ(cir); ++j) {
        int Min = INF, id = -1;
        for (int i = 0; i < SZ(cir[j]); ++i) {
            if (Min > c[cir[j][i]]) {
                Min = c[cir[j][i]];
                id = i;
            }
        }
        for (int i = (id + 1) % SZ(cir[j]), k = 0; k < SZ(cir[j]); ++k) {
            cout << cir[j][(i + k) % SZ(cir[j])] << ' ';
        }

    }
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
