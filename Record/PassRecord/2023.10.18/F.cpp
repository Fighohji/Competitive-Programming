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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define int long long
int a[maxn];
struct node {
    int id, val;
    bool operator<(const node &t) const {
        return val < t.val;
    }
};
void solve() {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum >= n * (n - 1)) {
        cout << "Recurrent\n";
        return ;
    }
    priority_queue<node> q;
    int cnt = n + 1;
    int add = 0;
    vector<int> sub(n + 1);
    for (int i = 1; i <= n; ++i) {
        q.push({i, a[i]});
    }
    while (cnt--) {
        auto [id, val] = q.top(); q.pop();
        ll nval = add + a[id] + sub[id];
        add += nval / (n - 1);
        sub[id] -= nval / (n - 1) * n;
        q.push({id, add + a[id] + sub[id]});
    }
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; ++i) {
        a[i] = add + a[i] + sub[i];
        assert(a[i] < 2 * n);
        sub[i] = 0;
        q.push({i, a[i]});
    }
    add = 0;
    cnt = n + 1;
    while (cnt--) {
        auto [id, val] = q.top(); q.pop();
        ll nval = add + a[id] + sub[id];
        add += nval / (n - 1);
        sub[id] -= nval / (n - 1) * n;
        q.push({id, add + a[id] + sub[id]});
    }
    vector<int> Ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        Ans[i] = add + a[i] + sub[i];
        if (Ans[i] >= n - 1) {
            cout << "Recurrent\n";
            return ;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << Ans[i] << " \n"[i == n];
    }

}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
