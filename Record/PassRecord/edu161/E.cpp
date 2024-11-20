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
    ll x; cin >> x;
    int now = 1000000000 - 1, Mx = 1000000000;
    vector<int> Ans, res;
    int hi = 0;
    for (int i = 62; i >= 0; --i) {
        if (1ll << i & x) {
            for (int j = i - 1; j >= 0; --j) {
                Ans.pb(now - j * 1000);
                // cout << now - j << ' ';
            }
            // res.pb(-Mx);
            now -= i;
            hi = i;
            break;
                // cout << Mx << ' ';
        }
    }
    for (int i = hi - 1; i >= 0; --i) {
        if (1ll << i & x) {
            if (i) Ans.pb(Ans[i - 1] + 1);
            else Ans.pb(-Mx);
            // res.pb(-Mx);
        }
    }
    cout << SZ(Ans) << '\n';
    for (auto i : Ans) cout << i << ' ';
    // for (auto i : res) cout << i << ' ';
    cout << '\n';
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
