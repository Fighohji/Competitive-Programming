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
    int p, a, b, q, c, d;
    cin >> p >> a >> b >> q >> c >> d;
    int m, t;
    cin >> m >> t;
    if (m < p) {
        cout << m << '\n';
        return ;
    }
    while (t) {
        int cnt = m / p;
        int w = (cnt + 1) * p - m;
        int k = (w + (q - p) * cnt - 1) / ((q - p) * cnt);
        int tot = (a * cnt + b + c * cnt + d) * k;
        // cerr << tot << ' ' << t << '\n';
        if (t >= tot) {
            t -= tot;
            m = k * (q - p) * cnt + m;
        } else {
            break;
        }
    }
    int cnt = m / p;
    int num = t / (a * cnt + b + c * cnt + d);
    m += (q - p) * num * cnt;
    t -= num * (a * cnt + b + c * cnt + d);
    num = (t - b - d) / (a + c);
    num = max(0ll, num);
    num = min(cnt, num);
    m += num * (q - p);
    cout << m << '\n';
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
