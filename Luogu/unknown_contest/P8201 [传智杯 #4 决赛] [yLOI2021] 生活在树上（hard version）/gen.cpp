#include "testlib.h"

#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
vector<int> genArray(int n, int Min = 0, int Max = 1000'000'000, int t = 0) {
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = rnd.wnext(Min, Max, t);
    return arr;
}

vector<pair<int, int>> genTree(int n, int t = 0) {
    vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, t);
    vector<int> perm = rnd.perm(n);

    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));
    shuffle(edges.begin(), edges.end());
    return edges;
}

vector<int> getLeaves(const vector<pair<int, int>> &edges) {
    int n = edges.size() + 1;
    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    vector<int> leaf;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) leaf.push_back(i);
    }
    return leaf;
}

vector<int> getLink(const vector<pair<int, int>> &edges,
                    const vector<int> &leaf) {
    int n = edges.size() + 1;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        auto &[u, v] = edges[i];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> link;
    auto dfs = [&](auto self, int u, int p) -> void {
        link.push_back(u);
        shuffle(G[u].begin(), G[u].end());
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u);
            return;
        }
    };
    dfs(dfs, rnd.any(leaf), 0);
    return link;
}

constexpr int N = 500005;
int fa[N][20], dep[N], w[N], pre[N];
void dfs(int u, int p, const vector<vector<int>> &G) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    pre[u] = pre[p] ^ w[u];
    for (auto v : G[u])
        if (v != p) dfs(v, u, G);
}
void init_lca(int n) {
    for (int j = 1; j < 20; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 19; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i)) v = fa[v][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}
void genTestCase(int n, int m, int tW = 0, int tT = 0, int tOK = 0) {
    auto edges = genTree(n, tT);
    for (auto &[u, v] : edges) {
        u++, v++;
    }
    for (int i = 1; i <= n; ++i) {
        w[i] = rnd.wnext(0, 1000000, tW);
    }
    vector<vector<int>> G(n + 1, vector<int>());
    for (auto &[u, v] : edges) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0, G);
    init_lca(n);
    println(n, m);
    for (int i = 1; i <= n; ++i) {
        if (i < n) printf("%d ", w[i]);
        else printf("%d\n", w[i]);
    }
    for (auto &[u, v] : edges)
        println(u, v);
    vector<vector<int>> links(10);
    vector<int> leaf = getLeaves(edges);
    cerr << leaf.size() << '\n';
    for (int i = 0; i < 10; ++i) {
        links[i] = getLink(edges, leaf);
    }
    for (int i = 0; i < m; ++i) {
        if (rnd.wnext(2, tOK)) {
            int id = rnd.next(10);
            // int u = rnd.any(links[id]);
            // int v = rnd.any(links[id]);
            int u = links[id][0];
            int v = links[id].back();
            int lca = get_lca(u, v);
            if (rnd.next(2)) swap(u, v);
            int k = pre[u] ^ pre[v] ^ w[lca] ^ w[rnd.any(links[id])];
            println(u, v, k);
        } else {
            int u = rnd.next(n);
            int v = rnd.next(n);
            int k = rnd.next(0, 10000000);
            println(u + 1, v + 1, k);
        }
    }
}

void writeTest(int test) {
    startTest(test);
    int n = 300000;
    int m = 300000;
    int tw = 40;
    int tt = 1000000;
    int tOK = 0;
    genTestCase(n, m, tw, tt, tOK);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    cerr << "generated testcase " << test << '\n';
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 32; i <= 32; ++i) {
        writeTest(i);
    }
}
