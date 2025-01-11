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

vector<pair<int, int>> genTree(int n, int &rt, int t = 0) {
    vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, t);
    vector<int> perm = rnd.perm(n);
    rt = perm[0];
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());
    return edges;
}

void genTestCase(int n, int t = 0) {
    int rt = 0;
    auto edges = genTree(n, rt, t);
    vector<int> deg(n);
    for (auto &[u, v] : edges) {
        deg[u]++, deg[v]++;
    }
    vector<int> leaf;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1)
            leaf.push_back(i);
    }
    // println("leaf", leaf.size());
    int m = n;
    println(n, m, rt + 1);
    for (int i = 0; i < n - 1; ++i)
        println(edges[i].first + 1, edges[i].second + 1);
    for (int i = 0; i < n; ++i) {
        int u = rnd.any(leaf);
        int v = rnd.any(leaf);
        println(u + 1, v + 1);
    }
}

void writeTest(int test) {
    startTest(test);
    int n = 200000;
    int t = 1000000;
    genTestCase(n, t);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 24; i <= 24; ++i) {
        writeTest(i);
    }
}
