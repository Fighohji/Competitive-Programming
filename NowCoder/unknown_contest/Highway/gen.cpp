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

void genTestCase(int n, int t, int Min = 1, int Max = 1000'000'000) {
    auto edges = genTree(n, t);
    vector<int> weight = genArray(n, Min, Max, 1000);
    println(n);
    for (int i = 0; i < n - 1; ++i)
        println(edges[i].first + 1, edges[i].second + 1, weight[i]);
}

void writeTest(int test) {
    startTest(test);

    int T = 2;
    println(T);
    for (int i = 0; i < T; ++i) {
        int n = 100000;
        int t = -10000;
        genTestCase(n, t, 1, 100000000);
    }
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 14; ++i) {
        writeTest(i);
    }
}
