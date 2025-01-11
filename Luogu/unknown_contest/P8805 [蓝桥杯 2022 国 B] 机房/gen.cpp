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

void genTestCase(int n, int m, int t = 0) {
    auto edges = genTree(n, t);
    println(n, m);
    for (auto &[u, v] : edges) {
        println(u + 1, v + 1);
    }
    for (int i = 0; i < m; ++i) {
        int u = rnd.next(n);
        int v = rnd.next(n);
        println(u + 1, v + 1);
    }
}

void writeTest(int test) {
    startTest(test);
    int n = 100000;
    int m = 100000;
    int t = 1000000;
    genTestCase(n, m, t);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 23; i <= 23; ++i) {
        writeTest(i);
    }
}
