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

#define int long long

void solve() {
    int n, m; cin >> n >> m;
    vector<int> X(m);
    for (int i = 0; i < m; ++i) {
        cin >> X[i];
        --X[i];
    }
    ll Ans = 0, res = LINF;
    vector<ll> pre(2 * n + 2), cnt(2 * n + 2);
    for (int i = 1; i < m; ++i) {
        int val = min(abs(X[i] - X[i - 1]), n - abs(X[i] - X[i - 1]));
        Ans += val;
        int x = X[i], y = X[i - 1];
        if (x > y) swap(x, y);
        int nx = x + n;
        if (y - x < nx - y) {
            cnt[x]++;
            cnt[y]--;
            pre[x] += val;
            pre[y] -= val;
        } else {
            cnt[y]++;
            cnt[nx]--;
            pre[y] += val;
            pre[nx] -= val;
        }
    }
    for (int i = 1; i < 2 * n; ++i) {
        pre[i] += pre[i - 1];
        cnt[i] += cnt[i - 1];
    }
    for (int i = n; i < 2 * n; ++i) {
        res = min(res, Ans + (cnt[i] + cnt[i % n]) * n - (pre[i] + pre[i % n]) * 2);
    }
    cout << res << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
