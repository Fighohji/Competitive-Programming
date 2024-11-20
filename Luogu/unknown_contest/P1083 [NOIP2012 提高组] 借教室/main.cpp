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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> d(m + 1), s(m + 1), t(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> d[i] >> s[i] >> t[i];
    }
    int l = 1, r = m;
    int Ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        auto check = [&](int x) -> bool {
            vector<int> c(n + 2);
            for (int i = 1; i <= x; ++i)
                c[s[i]] += d[i], c[t[i] + 1] -= d[i];
            for (int i= 1; i <= n; ++i) {
                c[i] += c[i - 1];
                if (c[i] > a[i]) return false;
            }
            return true;
        };
        if (check(mid)) {
            l = mid + 1;
            Ans = mid;
        } else {
            r = mid - 1;
        }
    }
    if (Ans == m) {
        cout << 0 << '\n';
    } else {
        cout << -1 << "\n";
        cout << Ans + 1 << '\n';
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
