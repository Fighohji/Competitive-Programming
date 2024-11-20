#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <utility>
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
    int n, m, k;
    cin >> n >> m >> k;
    int tot = (n - 1) * m + (m - 1) * n, node = n * m;

    map<int, vector<pii>> seg;
    for (int i = 0; i < k; ++i) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        seg[y].push_back({x1, x2});
        node -= (x2 - x1 + 1);
    }
    for (auto &[y, p] : seg) {
        sort(all(p));
    }

    int lasy = 0;
    vector<pii> lasp{make_pair(1, n)};
    for (auto &[y, p] : seg) {
        int lastx = 0;
        for (auto &[l, r] : p) {
            // top
            if (lastx + 1 < l) tot--;
            // buttom
            if (r != n) tot--;
            lastx = r;
            
            // left
            tot -= (r - l + 1);
            if (lasy + 1 == y) {
                auto it = lower_bound(all(lasp), make_pair(l, 0));
                if (it != lasp.begin() && prev(it)->second >= l) it = prev(it);
                while (it != lasp.end() && it->first <= r) {
                    tot += (min(r, it->second) - max(l, it->first) + 1);
                    it = next(it);
                }
            }

            // right
            if (y != m) tot -= (r - l + 1);
            tot -= (r - l);
        }
        lasy = y;
        lasp = p;
    }

    cout << (node - 1 == tot ? "YES\n" : "NO\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
