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

void solve() {
    int n = 1000;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // a[i] = n;
    }
    vector<int> b(n + 1), id(n + 1);
    vector<pii> Ans;
    iota(all(id), 0);
    sort(all(id), [&](int x, int y) {
        return a[x] < a[y];
    });
    auto calc = [&](auto self, int l, int r) -> void {
        if (l > r) return;
        int mid = (l + r) >> 1;
        int w = a[id[mid]];
        for (int i = mid; i <= r; ++i) {
            if (b[i] < w) {
                b[i]++;
                Ans.push_back({2, id[i]});
            }
        }
        // cerr << l << ' ' << r << ' ' << b[mid] << '\n';
        for (int i = b[mid] + 1; i <= a[id[mid]]; ++i) {
            Ans.push_back({1, i - 1});
        }
        for (int i = mid; i <= r; ++i) {
            b[i] = a[id[mid]];
        }
        self(self, l, mid - 1);
        self(self, mid + 1, r);
    };
    calc(calc, 1, n);
    cout << Ans.size() << '\n';
    for (auto &[x, y] : Ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

