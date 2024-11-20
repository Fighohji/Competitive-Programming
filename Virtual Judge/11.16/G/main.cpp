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

constexpr int N = 1e6 + 50;
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

int st[20][N];

int lg[N];

void init(const vector<int> &a, int n) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
        st[0][i] = a[i];
    for (int i = 1; i < 20; ++i)
        for (int j = 1; j + (1 << i) - 1 <= n; ++j)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int qry(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    vector buc(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        buc[a[i]].push_back(i);
    }
    init(a, n);
    ll Ans = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = lower_bound(all(buc[a[i]]), i);
        if (buc[a[i]].end() - it < k) continue;
        int nl = i, nr = i;
        int l = i, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (qry(i, mid) <= a[i]) {
                nr = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        l = 1, r = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (qry(mid, i - 1) < a[i]) {
                nl = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ll rval = max(0, min(n, nr) - *(it + k - 1) + 1);
        ll lval = i - nl + 1;
        Ans += rval * lval; 
    }
    cout << Ans << '\n';
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

