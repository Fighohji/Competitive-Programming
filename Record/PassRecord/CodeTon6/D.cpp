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
#define GG { cout << "NO\n"; return; }
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


#define int long long

bool BEGIN;
struct node {
    int x, pos;
};

void solve() {
    int n; cin >> n;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].x;
    }
    int k; cin >> k;
    vector<int> tmp(n + 2);
    tmp[n + 1] = INF;
    for (int i = n; i >= 1; --i) {
        tmp[i] = min(tmp[i + 1], a[i].x);
    }
    vector<int> ans(n + 1);
    int pre = 0;
    ans[1] = k / tmp[1];
    pre = ans[1];
    k = k - ans[1] * tmp[1];
    for (int i = 2; i <= n; ++i) {
        if (tmp[i] == tmp[i - 1]) {
            ans[i] = ans[i - 1];
            continue;
        }
        ans[i] = min(k / (tmp[i] - tmp[i - 1]), pre);
        pre = ans[i];
        k -= pre * (tmp[i] - tmp[i - 1]);
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
