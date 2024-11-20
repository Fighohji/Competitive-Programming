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

int query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int t;
    cin >> t;
    return t;
}
void print(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
    int t;
    cin >> t;
}

void solve() {
    int n; cin >> n;
    if (n == 2) {
        print(1, 2);
    } else {
        int i = 1, j = 2, k = 3, t = 4;
        while (i <= n && j <= n && k <= n) {
            int x = query(i, k);
            int y = query(j, k);
            if (x == y)
                k = t++;
            if (x > y)
                j = t++;
            if (x < y)
                i = t++;
        }
        if (k > n)
            print(i, j);
        if (i > n)
            print(j, k);
        if (j > n)
            print(i, k);
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
