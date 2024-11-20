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
    int n, X, Y; cin >> n >> X >> Y;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = abs(X - Y), r = 1e9, Ans = l;
    while (l <= r) {
        int mid = l + r >> 1;
        auto check = [&](int x) -> bool {
            set<int> s = {X, Y};
            for (int i = 1; i <= n; ++i) {
                while (!s.empty() && a[i] - *s.begin() > x) s.erase(s.begin());
                while (!s.empty() && *s.rbegin() - a[i] > x) s.erase(*s.rbegin());
                if (s.empty()) return 0;
                s.insert(a[i]);
            }
            return 1;
        };
        if (check(mid)) {
            Ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
