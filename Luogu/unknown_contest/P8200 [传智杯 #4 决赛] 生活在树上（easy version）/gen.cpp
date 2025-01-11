#include "testlib.h"

#include <climits>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define ull unsigned long long

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
    vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    vector<int> leaf;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) leaf.push_back(i);
    }
    return leaf;
}

void genTestCase(int n, int m, int t = 0, int tv = 0) {
    auto edges = genTree(n, t);
    vector<ull> w(n);
    for (int i = 0; i < n; ++i) {
        w[i] = rnd.next(LLONG_MAX);
    }
    vector G(n, vector<pair<int, ull>>());
    println(n, m);
    for (int i = 0; i < n - 1; ++i) {
        println(edges[i].first + 1, edges[i].second + 1, w[i]);
        G[edges[i].first].push_back({edges[i].second, w[i]});
        G[edges[i].second].push_back({edges[i].first, w[i]});
    }
    vector<ull> pre(n);
    auto dfs = [&](auto self, int u, int p) -> void { for (auto &[v, w] : G[u]) {
            if (v == p) continue;
            pre[v] = pre[u] ^ w;
            self(self, v, u);
        }
    };
    vector<int> leaf = getLeaves(edges);
    cerr << leaf.size() << '\n';
    dfs(dfs, 0, -1);
    for (int i = 0; i < m; ++i) {
        int a = rnd.any(leaf);
        int b = rnd.any(leaf);
        ull c = rnd.next(LLONG_MAX);
        if (rnd.next(2)) c = pre[a] ^ pre[b];
        println(a + 1, b + 1, c);
    }
}

void writeTest(int test) {
    startTest(test);

    int n = 100000;
    int m = 100000;
    int t = 500000;
    genTestCase(n, m, t);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 17; i <= 17; ++i) {
        writeTest(i);
    }
}
