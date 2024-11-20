#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int siz[maxn], mx[maxn];
int rt, n;
vector<int> G[maxn];
void find_rt(int id,int fa)
{
    siz[id]=1;mx[id]=0;
    for(auto y : G[id])
    {
        if(y==fa) continue;
        find_rt(y,id);
        mx[id]=max(mx[id],siz[y]);
        siz[id]+=siz[y];
    }
    mx[id]=max(mx[id],n-siz[id]);//这里是nt-siz[id],因为重心要在不同子树里面求
    if(mx[id]<mx[rt])
    {
        rt=id;
    }
}
int fa[maxn];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve() {
    cin >> n;
    int m; cin >> m;
    for (int i = 1; i <= n; ++i) {
        G[i].clear();
        fa[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        if (find(u) == find(v)) continue;
        fa[find(u)] = find(v);
        G[u].pb(v); G[v].pb(u);
        // cout << u << ' ' << v << '\n';
    }
    // rt = 0;
    // find_rt(1, 0);
    int block = sqrt(n);
    while (block * block < n) block++;
    vector vec(block + 1, vector<int>());
    vector<int> Ans;
    auto dfs = [&](auto &&dfs, int u, int p, int dep) -> void {
        vec[dep % block].pb(u);
        for (auto v : G[u]) {
            if (v == p) continue;
            dfs(dfs, v, u, dep + 1);
        }
    };
    // cout << rt << '\n';
    dfs(dfs, 1, 0, 0);
    for (int i = 0; i < block; ++i) {
        if (SZ(vec[i]) < block || SZ(vec[i]) <= block && i == 0) {
            // cout << "YES\n";
            if (i != 0) vec[i].pb(1);
            cout << SZ(vec[i]) << '\n';
            for (auto j : vec[i]) {
                cout << j << ' ';
            }
            cout << '\n';
    // split
            return;
        }
    }
    cout << "-1\n";
}
/*
2
4 3
1 2
2 3
3 4
6 7
1 2
2 3
3 1
1 4
4 5
5 6
6 4

*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
