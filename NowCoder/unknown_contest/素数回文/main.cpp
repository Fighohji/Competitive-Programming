#include <climits>
#include <iostream>
#include <random>
#include <string>
#include <algorithm>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    ll x;
    cin >> x;
    string s = to_string(x);
    string t = s;
    t.pop_back();
    reverse(all(t));
    s += t;
    x = 0;
    for (auto i : s)
        x = x * 10 + i - '0';
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) {
            cout << "noprime\n";
            return;
        }
    cout << "prime\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
