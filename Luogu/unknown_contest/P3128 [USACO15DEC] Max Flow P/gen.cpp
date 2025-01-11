#include "testlib.h"

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
    return leaf;
}

void genTestCase(int n, int k, int t = 0) {
    auto edges = genTree(n, t);
    println(n, k);
    for (auto &[u, v] : edges) {
        println(u + 1, v + 1);
    }
    vector<int> node = vector<int>(n);
    iota(node.begin(), node.end(), 0);
    cerr << "number of leaf is " << node.size() << '\n';
    for (int i = 0; i < k; ++i) {
        int s = rnd.any(node);
        int t = rnd.any(node);
        println(s + 1, t + 1);
    }
}

void writeTest(int test) {
    startTest(test);

    int n = rnd.next(10, 100);
    int k = rnd.next(50, 500);
    int t = rnd.next(-10, 10);
    genTestCase(n, k, t);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
    cerr << "generated test case " << test << '\n';
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 10; ++i) {
        writeTest(i);
    }
}
