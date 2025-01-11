#include "testlib.h"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <vector>

std::vector<int> genArray(int n, int Min = 0, int Max = 1000'000'000, int t = 0) {
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        arr[i] = rnd.wnext(Min, Max, t);
    return arr;
}

template <typename T>
typename std::enable_if<std::is_same<T, std::vector<typename T::value_type>>::value ||
                       std::is_same<T, std::string>::value,
                   T>::type
sample(const T &container, int length, int num) {
    std::vector<int> vec = rnd.partition(num, length, 1);
    T result;
    int tmp = 0;
    for (int i = 0; i < vec.size(); ++i) {
        result.push_back(container[rnd.next(tmp, tmp + vec[i] - 1)]);
        tmp += vec[i];
    }
    shuffle(result.begin(), result.end());
    return result;
}

std::vector<std::pair<int, int>> genTree(int n, int t = 0) {
    std::vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, t);
    std::vector<int> perm = rnd.perm(n);

    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        if (rnd.next(2))
            edges.push_back(std::make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(std::make_pair(perm[p[i]], perm[i]));

    shuffle(edges.begin(), edges.end());
    return edges;
}

std::vector<std::pair<int, int>> genConnectedDirectedGraph(int n, int m, int &s,
                                                 int t = 0) {
    assert(m >= n - 1);
    std::vector<int> p(n);
    for (int i = 1; i < n; i++)
        p[i] = rnd.wnext(i, t);
    std::vector<int> perm = rnd.perm(n);

    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i < n; i++)
        edges.push_back(std::make_pair(perm[p[i]], perm[i]));
    s = perm[0];
    for (int i = n; i <= m; ++i) {
        std::vector<int> node = sample(perm, n, 2);
        edges.push_back(std::make_pair(node[0], node[1]));
    }
    shuffle(edges.begin(), edges.end());
    return edges;
}

std::vector<int> getLeaves(const std::vector<std::pair<int, int>> &edges) {
    int n = edges.size() + 1;
    std::vector<int> deg(n);
    for (int i = 0; i < n - 1; ++i) {
        deg[edges[i].first]++;
        deg[edges[i].second]++;
    }
    std::vector<int> leaf;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 1) leaf.push_back(i);
    }
    std::cerr << "number of leaf is " << leaf.size() << '\n';
    return leaf;
}

void genTestCase(int n, int m, int &s, int edgeWeight, int t) {
    auto edges = genConnectedDirectedGraph(n, m, s, t);
    println(n, m, s + 1);
    auto w = rnd.partition(m, rnd.next(m, edgeWeight));
    for (int i = 0; i < m; ++i) {
        println(edges[i].first + 1, edges[i].second + 1, w[i]);
    }
}

void writeTest(int test) {
    startTest(test);
    
    int n = 100000;
    int m = 200000;
    int s, edgeW = rnd.next(100000000, 1000000000);
    int t = -10000;
    genTestCase(n, m, s, edgeW, t);
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
