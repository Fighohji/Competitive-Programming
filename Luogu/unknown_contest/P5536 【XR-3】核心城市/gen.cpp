#include "testlib.h"

#include <cassert>
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

void genTestCase(int n, int k, int t = 0) {
    auto edges = genTree(n, t);
    println(n, k);
    for (auto &[u, v] : edges) {
        println(u + 1, v + 1);
    }
}

void writeTest(int test) {
    startTest(test);
    
    int n = 100000;
    int k = 1;
    int t = -2000000;
    genTestCase(n, k, t);

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
