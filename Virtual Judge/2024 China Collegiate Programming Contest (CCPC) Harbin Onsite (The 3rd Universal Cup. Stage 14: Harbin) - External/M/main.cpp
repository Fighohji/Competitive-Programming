#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <random>
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

#define int long long

void solve() {
    int n;
    cin >> n;
    int Ans = 0;
    int cnt = 0;
    vector<int> fac;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != 1) fac.push_back(i);
            if (n / i != i) fac.push_back(n / i);
        }
    }
    sort(all(fac));
    int pre = 1;
    for (int i : fac) {
        Ans += (i - pre) * (n / pre);
        pre = i;
    }
    cout << Ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

