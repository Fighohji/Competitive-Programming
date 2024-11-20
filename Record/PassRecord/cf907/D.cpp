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
constexpr int mod = 1e9 + 7; /* 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

vector<pll> lgx[60];

const ll Max = 1000000000000000000ll;

void init() {
    for (int j = 2; j < 60; ++j) {
        __int128 now = 1;
        for (;now <= Max;) {
            lgx[j].pb({now, min(now * j - 1, (__int128)Max)});
            now *= j;
        }
    }
}

void solve() {
    ll l, r; cin >> l >> r;
    ll ans = 0;
    for (int i = 2; i < lgx[2].size(); ++i) {
        auto [x, y] = lgx[2][i];
        if (y < l || x > r) continue;
        x = max(l, x); y = min(y, r);
        for (int j = 0; j < lgx[i].size(); ++j) {
            auto [X, Y] = lgx[i][j];
            if (Y < x || X > y) continue;
            X = max(x, X); Y = min(Y, y);
            ans = (ans + (Y - X + 1) * j % mod) % mod;
        }

    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();

    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
