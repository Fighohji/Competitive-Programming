#include "testlib.h"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <numeric>
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
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
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
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    vector<int> leaf;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1)
            leaf.push_back(i);
    }
    cerr << "number of leaf is " << leaf.size() << '\n';
    return leaf;
}

void genTestCase(int n, int t = 0) {
    auto edges = genTree(n, t);

    vector G(n, vector<int>());

    for (auto &[u, v] : edges) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> fa(n), dep(n);
    auto dfs = [&](auto self, int u, int p, int d) -> void {
        fa[u] = p;
        dep[u] = d;
        for (auto v : G[u]) {
            if (v == p) continue;
            self(self, v, u, d + 1);
        }
    };

    dfs(dfs, 0, -1, 1);
    int Max = *max_element(dep.begin(), dep.end());
    auto per = rnd.perm(Max);

    println(n, Max);

    for (int i = 0; i < n; ++i) {
        if (i < n - 1) printf("%d ", fa[i] + 1);
        else printf("%d\n", fa[i] + 1);
    }
    for (int i = 0; i < Max; ++i) {
        println(per[i] + 1);
    }
    
}
void writeTest(int test) {
    startTest(test);

    int n = 200000;
    int t = -1000000;
    genTestCase(n, t);

}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int l = opt<int>(1);
    int r = opt<int>(2);
    assert(l <= r);
    for (int i = l; i <= r; ++i) {
        writeTest(i);
    }
}
