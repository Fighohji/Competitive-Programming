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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = 50000000000ll;
    int Ans = 0;
    vector<int> tim;
    auto check = [&](int x) -> bool {
        int now = 0;
        vector<int> t(n);
        int j = 0, i = 0;
        while (j < d) {
            while (i < n && now < x) {
                t[i] = j;
                now += a[i++];
            }
            if (now < x) return 0;
            j++;
            now /= 2;
        }
        while (i < n)
            t[i++] = j - 1;
        tim = t;
        return 1;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            Ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << Ans << '\n';
    for (auto i : tim) {
        cout << i + 1 << '\n';
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
