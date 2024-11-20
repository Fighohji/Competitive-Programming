#include "bits/stdc++.h"
#include <cstdint>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

struct DSU {
    vector<int> f, siz, rnk;
    int cc;
        
    DSU() {}
    DSU(int n) {
        init(n);
    }
        
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        rnk.assign(n, 0);
        cc = n;
    }
        
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
        
    bool same(int x, int y) {
        return find(x) == find(y);
    }
        
    int merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return -1;
        --cc;
        if (rnk[x] > rnk[y]) swap(x, y);
        siz[y] += siz[x];
        f[x] = y;
        if (rnk[x] == rnk[y]) rnk[y]++;
        return y;
    }
        
    int size(int x) {
        return siz[find(x)];
    }
};

inline void yes() { cout  << "YES" << "\n"; return; }
inline void no() { cout << "NO" << "\n"; return; }

template<typename T>
bool chmin(T &x, T val) { if (val < x) { x = val; return true; } return false; }
template<typename T>
bool chmax(T &x, T val) { if (x < val) { x = val; return true; } return false; }

#define DEBUG 1
#define MULTI_TEST 0

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<pii> e1(m), e2(q);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        if (x > y) swap(x, y);
        e1[i] = {x, y};
    }
    set<pii> S;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y;
        --x, --y;
        if (x > y) swap(x, y);
        e2[i] = {x, y};
        S.insert({x, y});
    }

    vector<pii> e;
    for (int i = 0; i < m; i++) {
        if (!S.count(e1[i])) {
            e.push_back(e1[i]);
        }
    }
    for (int i = q - 1; i >= 0; i--) {
        e.push_back(e2[i]);
    }


    DSU dsu(n);
    // 1: tree edge, 2: cross / back edge
    vector<int> type(m);

    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        auto [x, y] = e[i];
        if (dsu.same(x, y)) {
            type[i] = 2;
        }
        else {
            type[i] = 1;
            dsu.merge(x, y);
            g[x].push_back({y, i});
            g[y].push_back({x, i});
        }
    }

    vector<bool> vis(n);
    vector<int> par(n), pare(n), dep(n);
    iota(par.begin(), par.end(), 0);
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        vis[u] = true;
        for (auto [v, eid]: g[u]) {
            if (v == p) continue;
            par[v] = u;
            pare[v] = eid;
            dep[v] = dep[u] + 1;
            dfs(dfs, v, u);
        }
    };
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(dfs, i, -1);
    }

    vector<int> dsu2(n);
    iota(dsu2.begin(), dsu2.end(), 0);
    auto mnnode = dsu2;
    auto find = [&](auto &&find, int x) {
        if (dsu2[x] == x) return x;
        else return dsu2[x] = find(find, dsu2[x]);
    };
    auto merge = [&](int x, int y) {
        x = find(find, x);
        y = find(find, y);
        if (x == y) return -1;
        dsu2[x] = y;
        if (dep[mnnode[x]] < dep[mnnode[y]]) {
            mnnode[y] = mnnode[x];
        }
        return y;
    };
    auto Mnnode = [&](int x) {
        x = find(find, x);
        return mnnode[x];
    };

    vector<vector<int>> sp(18, vector<int>(n));
    sp[0] = par;
    for (int i = 1; i < 18; i++) {
        for (int j = 0; j < n; j++) {
            sp[i][j] = sp[i - 1][sp[i - 1][j]];
        }
    }

    auto lca = [&](int x, int y) {
        for (int i = 17; i >= 0; i--) {
            if (dep[sp[i][x]] >= dep[y]) {
                x = sp[i][x];
            }
            if (dep[sp[i][y]] >= dep[x]) {
                y = sp[i][y];
            }
        }
        if (x == y) return x;
        for (int i = 17; i >= 0; i--) {
            if (sp[i][x] != sp[i][y]) {
                x = sp[i][x];
                y = sp[i][y];
            }
        }
        return par[x];
    };


    vector<int> dead(m, m);
    for (int i = 0; i < m; i++) {
        if (type[i] == 2) { // handle killing tree edge in new-formed cycle
            auto [x, y] = e[i];
            int l = lca(x, y);
            while (dep[x] > dep[l]) {
                if (Mnnode(x) != x) { x = Mnnode(x); continue; }
                chmin(dead[pare[x]], i);
                merge(x, par[x]);
                x = par[x];
            }
            while (dep[y] > dep[l]) {
                if (Mnnode(y) != y) { y = Mnnode(y); continue; }
                chmin(dead[pare[y]], i);
                merge(y, par[y]);
                y = par[y];
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //  cout << i << " par: " << par[i] << " " << pare[i] << endl;
    // }

    // for (int i = 0; i < m; i++) {
    //  cout << i << " dead: " << dead[i] << endl; 
    // }

    vector<int> D(m + 1);
    for (int i = 0; i < m; i++) {
        if (type[i] == 1) { // handle tree edge live time
            D[i]++;
            D[dead[i]]--;
        }
    }

    vector<int> ans(q);
    for (int i = 0; i < m; i++) {
        if (i > 0) D[i] += D[i - 1];
    }
    for (int i = m - 2, j = 0; i >= -1 && j < q; i--, j++) {
        int x = (i == -1) ? 0 : D[i];
        ans[j] = x;
    }

    for (auto x: ans) cout << x << "\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    if (MULTI_TEST) {
        int t;
        cin >> t;
        while (t--) {
            solve();
        }
    }
    else {
        solve();
    }
}
