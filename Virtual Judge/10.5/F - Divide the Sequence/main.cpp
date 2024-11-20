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

#define int long long
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), suf(n + 2);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = n; i >= 1; --i) suf[i] = suf[i + 1] + a[i];

    vector<int> Ans(n + 1);
    Ans[1] = suf[1];
    sort(suf.begin() + 2, suf.begin() + n + 1, greater<int>());
    for(int i = 2; i <= n; ++i)
    {
        Ans[i] = Ans[i - 1] + suf[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        cout << Ans[i] << " \n"[i == n];
    }
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
