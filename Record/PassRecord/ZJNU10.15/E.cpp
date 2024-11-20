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
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int p, k, t;
ll Ans = 0;
void dfs(ll now, int pos, ll val) {
    if (pos == t) {
        Ans = (Ans + now) % p;
        return ;
    }
    for (int i = val + 1; i <= p - 1; ++i) {
        if (i == k) continue;
        dfs(now * i % p, pos + 1, i);
    }
}
ll qpow(ll base, ll power, ll p)
{
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}

void solve() {
    cin >> p >> k >> t;
    cout << qpow(p - k, t, p) << '\n';
    // for (int i = 1;)
    // vector <int> prime = {3, 5, 7, 11, 13, 17};
    // cin >> p >> k;
    // for (auto P : prime) {
    //     p = P;
    //     for (k = 1; k < p; ++k) {
    //         for (int i = 1; i <= p - 2; ++i) {
    //             Ans = 0;
    //             t = i;
    //             dfs(1, 0, 0);
    //             cout << "t is " << t << ' ' << Ans << ' ';
    //         }
    //     }
    // }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
