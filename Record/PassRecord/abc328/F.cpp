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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
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

constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define int long long
vector<int> G[maxn];
ll a[maxn], b[maxn], d[maxn], dis[maxn];
void dfs(int u, ll val) {
    dis[u] += val;
    for (auto v : G[u])
        dfs(v, val);
}

int fa[maxn], sz[maxn];
void init(int n) { for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1; }
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(int x, int y, ll val)
{
    int xx = find(x), yy = find(y);
    if (xx == yy) return;
    if (sz[xx] < sz[yy]) {
        swap(xx, yy);
        swap(x, y);
        val = -val;
    }
    fa[yy] = xx; //x 不变
    sz[xx] += sz[yy];
    int dif = val - (dis[x] - dis[y]);
    dif = -dif;
    dfs(yy, dif);
    G[xx].pb(yy);
}



void solve() {
    int n, q; cin >> n >> q;
    init(n);
    for (int i = 1; i <= q; ++i) {
        cin >> a[i] >> b[i] >> d[i];
        if (find(a[i]) != find(b[i])) {
            merge(a[i], b[i], d[i]);
            cout << i << ' ';
        } else {
            if (dis[a[i]] - dis[b[i]] == d[i]) {
                cout << i << ' ';
            }
        }

    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
