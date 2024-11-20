#include <climits>
#include <iostream>
#include <map>
#include <random>
#include <queue>
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
    int L, R;
    cin >> L >> R;
    int hL = -1, hR = -1;
    const int X = 20;
    for (int i = 0; i < X; ++i) {
        if (L >> i & 1) hL = i;
        if (R >> i & 1) hR = i;
    }
    vector<vector<pii>> G(101);
    int idx = 0;
    if (hL == hR) {

        int f = hL, s = hL;
        for (int i = hL; i >= 0; --i) {
            if ((L >> i & 1) == (R >> i & 1)) {
                s = i;
            } else
                break;
        }

        int S = 1, T = 2;
        idx = 3;
        int pre = 3;
        vector<int> id(20);

        for (int i = f; i >= s; --i) {
            if (i)
                G[S].push_back({++idx, L >> i & 1});
            else
                G[S].push_back({T, L >> i & 1});
            S = idx;
        }

        for (int i = X - 1; i >= 0; --i) {
            if (i) {
                G[pre].push_back({++idx, 1});
                G[pre].push_back({idx, 0});
            } else {
                G[pre].push_back({T, 1});
                G[pre].push_back({T, 0});
            }
            pre = idx;
            if (!i) pre = T;
            id[i] = pre;
        }

        pre = S;
        for (int i = s - 1; i >= 0; --i) {
            if (i)
                G[pre].push_back({++idx, L >> i & 1});
            else
                G[pre].push_back({T, L >> i & 1});
            if (!(L >> i & 1) && i != s - 1) { G[pre].push_back({id[i], 1}); }
            pre = idx;
        }

        pre = S;
        for (int i = s - 1; i >= 0; --i) {
            if (i)
                G[pre].push_back({++idx, R >> i & 1});
            else
                G[pre].push_back({T, R >> i & 1});
            if ((R >> i & 1) && i != s - 1) { G[pre].push_back({id[i], 0}); }
            pre = idx;
        }


    } else {

        int S = 1, T = 2;
        idx = 2;
        int pre = 2;
        vector<int> id(20);
        for (int i = X - 1; i >= 0; --i) {
            G[pre].push_back({++idx, 1});
            G[pre].push_back({idx, 0});
            pre = idx;
            id[i] = pre;
        }

        T = pre;

        pre = S;
        for (int i = hL; i >= 0; --i) {
            if (i)
                G[pre].push_back({++idx, L >> i & 1});
            else
                G[pre].push_back({T, L >> i & 1});
            if (!(L >> i & 1)) { G[pre].push_back({id[i], 1}); }
            pre = idx;
        }
        pre = S;
        for (int i = hR; i >= 0; --i) {
            if (i)
                G[pre].push_back({++idx, R >> i & 1});
            else
                G[pre].push_back({T, R >> i & 1});
            if ((R >> i & 1) && i != hR) { G[pre].push_back({id[i], 0}); }
            pre = idx;
        }

        for (int i = hL + 1; i < hR; ++i) {
            G[S].push_back({id[i], 1});
        }
    }

    vector<int> deg(idx + 1);
    for (int i = 1; i <= idx; ++i) {
        for (auto [j, w] : G[i]) {
            deg[j]++;
        }
    }
    queue<int> q;
    vector<int> vis(idx + 1, 1);
    for (int i = 1; i <= idx; ++i) {
        if (!deg[i] && i != 1) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] :  G[u]) {
            deg[v]--;
            if (!deg[v])
                q.push(v);
        }
    }
    int tot = 0;
    map<int, int> ord;
    for (int i = 1; i <= idx; ++i) {
        if (vis[i]) 
            ord[i] = ++tot;
    }
    cout << tot << '\n';
    for (int i = 1; i <= idx; ++i) {
        if (!ord.count(i)) continue;
        vector<int> node;
        for (auto [j, w] : G[i]) {
            if (!ord.count(j)) continue;
            node.push_back(j);
        }
        cout << node.size() << ' ';
        for (auto [j, w] : G[i]) {
            if (!ord.count(j)) continue;
            node.push_back(j);
            cout << ord[j] << ' ' << w << ' ';
        }
        cout << '\n';
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
