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

void brute_force() {
    map<multiset<int>, vector<int>> vec;
    for (int i = 1; i <= 100000; ++i) {
        ll val = (ll)i * i;
        multiset<int> s;
        while (val) {
            s.insert(val % 10);
            val /= 10;
        }
        vec[s].pb(i);
    }
    for (auto [x, y] : vec) {
        if (SZ(x) % 2 == 0) continue;
        multiset<int> s = {1, 6, 9};
        while (SZ(s) < SZ(x)) s.insert(0);
        if (s != x) continue;
        cout << "set: \n";
        for (auto i : x) {
            cout << i << ' ';
        }
        cout << '\n';
        cout << "number: \n";
        for (auto j : y) {
            cout << j << ' ' << j * j << '\n';
        }
    }
}

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n";
    } else {

    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // brute_force();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
