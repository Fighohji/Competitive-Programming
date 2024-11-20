#include <algorithm>
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 1000000000000ll;
    int Max = r;
    auto checkMax = [&](int x) -> bool {
        int w = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > x) {
                w += a[i] - x;
            } else {
                w -= min(x - a[i], w);
            }
        }
        return w == 0;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (checkMax(mid)) {
            Max = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    l = 1, r = Max;
    int Min = l;
    auto checkMin= [&](int x) -> bool {
        int w = 0, can = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > Max) {
                w += a[i] - Max;
                continue;
            }
            int tmp = min(w, Max - a[i]);
            w -= tmp;
            can += tmp;
            if (a[i] < x) {
                can -= x - a[i];
                if (can < 0) return 0;
            }
        }
        return w == 0;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (checkMin(mid)) {
            Min = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << Max - Min << '\n';
    cerr << "------\n";
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
