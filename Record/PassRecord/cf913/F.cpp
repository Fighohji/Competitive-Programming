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



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    if (n == 1) {
        cout << "0\n";
        return ;
    }
    vector<int> b(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        b[i] = a[i % n];
    }
    vector<int> lis(2 * n);
    lis[2 * n - 1] = 1;
    int Ans = INF, now = 0;
    for (int i = 2 * n - 2; i >= 0; --i) {
        if (b[i] >= b[i + 1]) {
            lis[i] = lis[i + 1] + 1;
        } else {
            lis[i] = 1;
        }
        if (i < n) now++;
        if (lis[i] == n) {
            Ans = min(Ans, now + 1);
            break;
        }
    }
    // cout << Ans << ' ';
    for (int i = 0; i < 2 * n; ++i) {
        lis[i] = 0;
        b[i] = a[i % n];
    }
    lis[2 * n - 1] = 1;
    now = 0;
    for (int i = 2 * n - 2; i >= 0; --i) {
        if (b[i] <= b[i + 1]) {
            lis[i] = lis[i + 1] + 1;
        } else {
            lis[i] = 1;
        }
        if (i < n) now++;
        // cout << now << ' ' << lis[i] << '\n';
        if (lis[i] == n) {
            Ans = min(Ans, now);
            break;
        }
    }
    reverse(all(a));
    for (int i = 0; i < 2 * n; ++i) {
        lis[i] = 0;
        b[i] = a[i % n];
    }
    lis[2 * n - 1] = 1;
    now = 0;
    for (int i = 2 * n - 2; i >= 0; --i) {
        if (b[i] <= b[i + 1]) {
            lis[i] = lis[i + 1] + 1;
        } else {
            lis[i] = 1;
        }
        if (i < n) now++;
        // cout << now << ' ' << lis[i] << '\n';
        if (lis[i] == n) {
            Ans = min(Ans, now + 1);
            break;
        }
    }
    for (int i = 0; i < 2 * n; ++i) {
        lis[i] = 0;
        b[i] = a[i % n];
    }
    lis[2 * n - 1] = 1;
    now = 0;
    for (int i = 2 * n - 2; i >= 0; --i) {
        if (b[i] >= b[i + 1]) {
            lis[i] = lis[i + 1] + 1;
        } else {
            lis[i] = 1;
        }
        if (i < n) now++;
        // cout << now << ' ' << lis[i] << '\n';
        if (lis[i] == n) {
            Ans = min(Ans, now + 2);
            break;
        }
    }
    cout << (Ans == INF ? -1 : Ans) << '\n';
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
