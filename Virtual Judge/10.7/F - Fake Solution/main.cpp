#include <climits>
#include <iostream>
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> L(31);
    int Ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        Ans |= a[i];
        int las = 0;
        for (int j = 0; j < 30; ++j) {
            if (a[i] >> j & 1) {
                L[las] = max(L[las], j - 1);
                las = j + 1;
            }
        }
    }
    for (int i = 1; i < 30; ++i) {
        L[i] = max(L[i], L[i - 1]);
    }
    int Max = 0;
    for (int i = 0; i < 30; ++i) {
        if (Ans >> i & 1) {
            Max = i;
        }
    }
    int cnt = 0;
    for (int i = 0; i < Max; ++i) {
        if (Ans >> i & 1) continue;
        cnt++;
        i = L[i];
    }
    cout << (1 << (Max + 1)) - 1 << ' ' << cnt << '\n';
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
