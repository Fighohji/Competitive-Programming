#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 100000 + 15
using namespace std;
vector<int> vec[MAXN];
int n, q, v, u, a, b, c, d;
int deep[MAXN], dad[MAXN], siz[MAXN], top[MAXN];
#define endl "\n"
void dfs(int x) {
    siz[x] = 1;
    deep[x] = deep[dad[x]] + 1;
    for (int i = 0; i < vec[x].size(); i++)
        if (dad[x] != vec[x][i]) {
            dad[vec[x][i]] = x;
            dfs(vec[x][i]);
            siz[x] += siz[vec[x][i]];
        }
}
void dfs1(int x) {
    int t = 0;
    if (!top[x]) top[x] = x;
    for (int i = 0; i < vec[x].size(); i++)
        if (dad[x] != vec[x][i] && siz[vec[x][i]] > siz[t]) t = vec[x][i];
    if (t) {
        top[t] = top[x];
        dfs1(t);
    }
    for (int i = 0; i < vec[x].size(); i++)
        if (dad[x] != vec[x][i] && vec[x][i] != t) dfs1(vec[x][i]);
}
int LCA(int x, int y) {
    for (; top[x] != top[y];) {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        x = dad[top[x]];
    }
    if (deep[x] > deep[y]) swap(x, y);
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1);
    dfs1(1);
    for (int i = 1; i <= q; i++) {
        cin >> a >> b >> c >> d;
        int S = LCA(a, b);
        int T = LCA(c, d);
        if (deep[S] < deep[T]) {
            swap(S, T);
            swap(a, c);
            swap(b, d);
        }
        if (LCA(S, c) == S || LCA(S, d) == S)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
}
