#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <random>
#include <tuple>
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

struct STTable {
    vector<vector<int>> st_max;
    vector<int> lg;
    STTable() {}
    STTable(int n, const vector<int> &a) {
        lg.resize(n + 1);
        int LG = 1;
        while ((1 << LG) < n)
            LG++;
        st_max.resize(LG + 1, vector<int>(n + 1));
        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i >> 1] + 1;
        for (int i = 1; i <= n; ++i)
            st_max[0][i] = a[i - 1];
        for (int j = 1; j <= LG; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
    }

    int query_max(int l, int r) {
        l++, r++;
        int k = lg[r - l + 1];
        return max(st_max[k][l], st_max[k][r - (1 << k) + 1]);
    }
};
using node = tuple<int, int, int>;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 3>>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, c, l;
        cin >> u >> v >> c >> l;
        G[u].push_back({v, c, l});
        G[v].push_back({u, c, l});
    }
    vector<STTable> st(m + 1);
    vector<vector<int>> tick(m + 1), tim(m + 1);
    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> a[i] >> b[i];
        tick[a[i]].push_back(b[i]);
        tim[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; ++i) {
        st[i] = STTable(tick[i].size(), tick[i]);
    }
    vector<bool> vis(n + 1);
    vector<pii> dis(n + 1, {INF, INF});
    priority_queue<node, vector<node>, greater<node>> q;
    dis[1] = {0, INF};
    q.push({0, INF, 1});
    while (!q.empty()) {
        auto [t, d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i][0], c = G[u][i][1], l = G[u][i][2];
            pii w = {0, 0};
            if (a[t] == c && b[t] >= l + d) {
                w = {t, l + d};
            } else {
                auto it = upper_bound(all(tim[c]), t);
                if (it == tim[c].end()) continue;
                int id = it - tim[c].begin();
                int L = id, R = (int)tim[c].size() - 1;
                int pos = R + 1;
                while (L <= R) {
                    int mid = (L + R) >> 1;
                    if (st[c].query_max(id, mid) >= l) {
                        pos = mid;
                        R = mid - 1;
                    } else {
                        L = mid + 1;
                    }
                }
                if (pos == tim[c].size()) continue;
                w = {tim[c][pos], l};
            }
            if (dis[v] > w) {
                dis[v] = w;
                q.push({w.first, w.second, v});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << vis[i];
    }
    cout << '\n';
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
