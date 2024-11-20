#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <random>
#include <set>
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

constexpr int N = 400 + 50;
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

vector<int> e[N];
int match[N];
bool used[N];
bool dfs(int u) {
    for (int v : e[u]) {
        if (!used[v]) {
            used[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
// int id=0;
void solve() {
    //     cout<<++id<<' ';
    for (int i = 1; i <= 400; i++) {
        match[i] = -1;
        e[i].clear();
    }
    int n;
    cin >> n;
    vector<pair<int, int>> v1(n + 1);
    vector<int> r, c;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        v1[i] = {x, y};
        r.push_back(x);
        r.push_back(x + 1);
        r.push_back(x - 1);
        c.push_back(y);
        c.push_back(y + 1);
        c.push_back(y - 1);
    }
    int m;
    cin >> m;
    vector<pair<int, int>> v2(m + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        v2[i] = {x, y};
        r.push_back(x);
        r.push_back(x + 1);
        r.push_back(x - 1);
        c.push_back(y);
        c.push_back(y + 1);
        c.push_back(y - 1);
    }
    sort(all(r));
    sort(all(c));
    r.erase(unique(all(r)), r.end());
    c.erase(unique(all(c)), c.end());

    int R = r.size(), C = c.size();
    for (int i = 1; i <= n; i++) {
        v1[i].first = lower_bound(all(r), v1[i].first) - r.begin() + 1;
        v1[i].second = lower_bound(all(c), v1[i].second) - c.begin() + 1;
    }
    for (int i = 1; i <= m; i++) {
        v2[i].first = lower_bound(all(r), v2[i].first) - r.begin() + 1;
        v2[i].second = lower_bound(all(c), v2[i].second) - c.begin() + 1;
    }
    vector<vector<int>> mp(R + 1, vector<int>(C + 1));
    vector<vector<int>> mp2(R + 1, vector<int>(C + 1));
    for (int i = 1; i <= n; i++) {
        auto &[x, y] = v1[i];
        mp[x][y] = -1;
    }
    for (int i = 1; i <= m; i++) {
        auto &[x, y] = v2[i];
        mp[x][y] = -2;
    }
    vector<pair<int, int>> vec;
    int tot = 0;
    for (int i = 1; i <= R; i++) {
        vector<pair<int, int>> v;
        for (int j = 1; j <= C; j++) {
            if (mp[i][j] < 0) { v.push_back({j, mp[i][j]}); }
        }
        for (int j = 0; j < (int)v.size() - 1; j++) {
            if (v[j].second == -1 && v[j + 1].second == -1) {
                ++tot;
                int l = v[j].first, r = v[j + 1].first;
                if (l == r - 1) {
                    cout << -1 << '\n';
                    return;
                }
                for (int k = l + 1; k <= r - 1; k++) {
                    mp[i][k] = tot;
                }
            }
        }
    }
    map<pair<int, int>, pair<int, int>> mpp;
    int NN = tot;
    for (int j = 1; j <= C; j++) {
        vector<pair<int, int>> v;
        for (int i = 1; i <= R; i++) {
            if (mp[i][j] < 0) { v.push_back({i, mp[i][j]}); }
        }
        for (int i = 0; i < (int)v.size() - 1; i++) {
            if (v[i].second == -1 && v[i + 1].second == -1) {
                ++tot;
                int l = v[i].first, r = v[i + 1].first;
                if (l == r - 1) {
                    cout << -1 << '\n';
                    return;
                }
                for (int k = l + 1; k <= r - 1; k++) {
                    if (mp[k][j] > 0) {
                        e[mp[k][j]].push_back(tot);
                        mpp[{mp[k][j], tot}] = {k, j};
                    }
                    mp2[k][j] = tot;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= NN; i++) {
        memset(used, 0, sizeof used);
        ans += dfs(i);
    }
    cout << tot - ans << '\n';
    vector<int> vis(tot + 1);
    int cnt = 0;
    for (int i = NN + 1; i <= tot; i++) {
        if (match[i] != -1) {
            vis[i] = 1;
            vis[match[i]] = 1;
            auto &[x, y] = mpp[{match[i], i}];
            cnt++;
            cout << r[x - 1] << ' ' << c[y - 1] << '\n';
        }
    }
    set<int> st;
    for (int i = 1; i <= tot; i++) {
        if (!vis[i]) { st.insert(i); }
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if ((mp[i][j] > 0 || mp2[i][j] > 0) &&
                (st.lower_bound(mp[i][j]) != st.end() ||
                 st.lower_bound(mp2[i][j]) != st.end())) {
                st.erase(mp[i][j]);
                st.erase(mp2[i][j]);
                cnt++;
                cout << r[i - 1] << ' ' << c[j - 1] << '\n';
            }
        }
    }
    assert(tot - ans == cnt);
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
