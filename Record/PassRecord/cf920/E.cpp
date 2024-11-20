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
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> ya >> xa >> yb >> xb;
    ya = h - ya + 1, yb = h - yb + 1;
    if (ya <= yb) {
        cout << "Draw\n";
        return ;
    }
    if (w == 1) {
        cout << ((ya - yb) % 2 ? "Alice\n" : "Bob\n");
    } else {
        if ((ya - yb) % 2) {
            if (abs(xa - xb) <= 1) {
                cout << "Alice\n";
            } else {
                int res = 0;
                if (xa < xb) {
                    res = w - xb;
                } else {
                    res = xb - 1;
                }
                res = (ya - yb + 1) / 2 - res;
                if (res >= abs(xa - xb)) {
                    cout << "Alice\n";
                } else {
                    cout << "Draw\n";
                }
            }
        } else {
            if (abs(xa - xb) == 0) {
                cout << "Bob\n";
            } else {
                int res = 0;
                if (xa < xb) {
                    res = xa - 1;
                } else {
                    res = w - xa;
                }
                res = (ya - yb) / 2 - res;
                if (res >= abs(xa - xb)) {
                    cout << "Bob\n";
                } else {
                    cout << "Draw\n";
                }
            }
        }
    }
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
