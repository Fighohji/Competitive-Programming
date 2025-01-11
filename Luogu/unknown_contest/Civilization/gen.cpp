#include "testlib.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

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

void genTestCase(int n, int t, int k, int q) {
    vector<int> part = rnd.partition(k, n, 1);
    vector<pair<int, int>> edges;
    for (int i = 0, det = 0; i < k; ++i) {
        auto tmp = genTree(part[i], t); 
        for (auto &[x, y] : tmp)
            x += det, y += det;
        edges.insert(edges.end(), tmp.begin(), tmp.end());
        det += part[i];
    }
    shuffle(edges.begin(), edges.end());
    vector<int> perm = rnd.perm(n);
    int m = edges.size();
    println(n, m, q);
    for (auto edge : edges) {
        edge.first = perm[edge.first];
        edge.second = perm[edge.second];
        println(edge.first + 1, edge.second + 1);
    }
    int las = 1;
    for (int i = 0; i < q; ++i) {
        if (rnd.next(2) % 2) {
            println(1, las);
        } else {
            int u = rnd.next(n) + 1;
            int v = rnd.next(n) + 1;
            println(2, u, v);
            las = rnd.next(2) % 2 ? u : v;
        }
    }
}

void writeTest(int test) {
    // startTest(test);

    // int n = test * test;
    // int t = 1;
    // int k = rnd.next(1, n);
    // int q = n + 1; // number of query
    // genTestCase(n, t, k, q);
    string exec = "./main < " + to_string(test) + ".in > " + to_string(test) + ".out";
    system(exec.c_str());
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    for (int i = 1; i <= 28; ++i) {
        writeTest(i);
    }
}
