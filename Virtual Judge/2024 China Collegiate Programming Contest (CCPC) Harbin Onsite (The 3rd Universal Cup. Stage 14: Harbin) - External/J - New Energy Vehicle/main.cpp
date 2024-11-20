#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <queue>
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> x(m + 1), t(m + 1);
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> t[i];
        pos[t[i]].push_back(x[i]);
    }
    for (int i = 1; i <= n; ++i) {
        pos[i].push_back(LINF);
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; ++i) {
        q.push({pos[i][0], i});
    }
    vector<int> res = a;
    int Ans = 0;
    for (int i = 1; i <= m; ++i) {
        while (!q.empty() && x[i] > Ans) {
            auto [w, id] = q.top();
            q.pop();
            int tmp = min(x[i] - Ans, res[id]);
            Ans += tmp;
            res[id] -= tmp;
            if (res[id]) {
                q.push({w, id});
            }
        }
        if (x[i] > Ans) {
            cout << Ans << '\n';
            return ;
        }
        res[t[i]] = a[t[i]];
        if (!q.empty() && q.top().second == t[i]) q.pop();
        q.push({*upper_bound(all(pos[t[i]]), x[i]), t[i]});
    }
    cout << Ans + accumulate(all(res), 0ll) << '\n';
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
