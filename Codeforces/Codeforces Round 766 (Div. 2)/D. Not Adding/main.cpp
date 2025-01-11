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

bool vis[N * 5];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int Max = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        vis[a[i]] = 1;
        Max = max(Max, a[i]);
    }
    int Ans = 0;
    for (int i = 1; i <= Max; ++i) {
        int g = 0;
        for (int j = i; j <= Max; j += i) {
            if (vis[j]) {
                g = gcd(g, j);
                if (g == i) {
                    Ans++;
                    break;
                }
            }
        }
    }
    cout << Ans - n << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
