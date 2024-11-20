#include <chrono>
#include <locale>
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
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)



void solve() {
    ll n, k; cin >> n >> k;
    ull ans = 0;
    vector<ll> a(n);
    map<int, int> vis;
    vector<int> fac;
    int tmp = k;
    for (int i = 2; i * i <= tmp; ++i) {
        if (tmp % i == 0) fac.pb(i);
        while (tmp % i == 0) tmp /= i;
    }
    if (tmp != 1) fac.pb(tmp);
    for (auto i : fac) vis[i] = 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += __gcd(a[i], k) * (ull)(n - 1);
        // if (vis.count(__gcd(a[i], k))) {
        //     ans -= __gcd(a[i], k);
        //     ans += 1;
        // }
    }
    for (int i = 0; i < n; ++i) {
        ll x = a[i] * a[i];
        ans += __gcd(x, k) / __gcd(a[i], k);
    }
    cout << ans << '\n';
}
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}