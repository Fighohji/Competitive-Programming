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

void genTestCase(int n, int m, int tT = 0, int tS = 0) {
    string s;
    auto tmp = genArray(n, 0, 1, tS);
    for (int i = 0; i < n; ++i)
        s += 'G';
    auto edges = genTree(n, tT);
    println(n, m);
    println(s);
    for (auto &[x, y] : edges) {
        println(x + 1, y + 1);
    }
    auto leaf = getLeaves(edges);
    // cerr << leaf.size() << '\n';
    for (int i = 0; i < m; ++i) {
        int a = rnd.any(leaf);
        int b = rnd.any(leaf);
        string c = "H";
        println(a + 1, b + 1, c);
    }
}

void writeTest(int test) {
    startTest(test);
    // rnd.next(10);
    int n = 100000, m = 100000;
    int tT = 500000;
    int tS = 5;
    genTestCase(n, m, tT, tS);
    string exec =
        "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 28; i <= 28; ++i) {
        writeTest(i);
    }
}