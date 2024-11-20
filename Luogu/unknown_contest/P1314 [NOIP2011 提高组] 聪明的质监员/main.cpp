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
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> w(n), v(n), l(m), r(m);
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i < m; ++i)
        cin >> l[i] >> r[i];
    int L = 0, R = 1000000;
    int Ans = LINF;
    while (L <= R) {
        int mid = (L + R) >> 1;
        auto check = [&](int W) -> __int128 {
            vector<int> c(n + 1), p(n + 1);
            for (int i = 1; i <= n; ++i) {
                c[i] = (w[i - 1] >= W);
                p[i] = v[i - 1] * c[i];
                c[i] += c[i - 1];
                p[i] += p[i - 1];
            }
            __int128 res = 0;
            for (int i = 0; i < m; ++i) {
                res += (p[r[i]] - p[l[i] - 1]) * (c[r[i]] - c[l[i] - 1]);
            }
            return res;
        };
        __int128 res = check(mid);

        if (res <= s) {
            Ans = min(Ans, s - (int)res);
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    L = 0, R = 1000000;
    while (L <= R) {
        int mid = (L + R) >> 1;
        auto check = [&](int W) -> __int128 {
            vector<int> c(n + 1), p(n + 1);
            for (int i = 1; i <= n; ++i) {
                c[i] = (w[i - 1] >= W);
                p[i] = v[i - 1] * c[i];
                c[i] += c[i - 1];
                p[i] += p[i - 1];
            }
            __int128 res = 0;
            for (int i = 0; i < m; ++i) {
                res += (p[r[i]] - p[l[i] - 1]) * (c[r[i]] - c[l[i] - 1]);
            }
            return res;
        };
        __int128 res = check(mid);

        if (res >= s) {
            Ans = min((__int128)Ans, res - s);
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
