#include <climits>
#include <iostream>
#include <random>
#include <string>
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

int pre[N * 5];
void init() {
    int now = 0;
    int M = 1000000;
    string s;
    while (s.length() < M) {
        now++;
        for (int i = 0; i < now && s.length() < M; ++i)
            s += to_string(now);
    }
    for (int i = 0; i < M; ++i) {
        pre[i + 1] = pre[i] + s[i] - '0';
    }
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
