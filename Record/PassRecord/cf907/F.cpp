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

constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


struct BIT {
    int MX;
    ll tr[maxn];
    void clear() {
        for (int i = 1; i <= MX; ++i)
            tr[i] = 0;
    }
    void update(int x, int val) {
        while (x <= MX) {
            tr[x] += val;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll sum = 0;
        while (x) {
            sum += tr[x];
            x -= lowbit(x);
        }
        return sum;
    }
} bit;
int q;

struct node {
    int tim, val;
};
int t[maxn], sz;
ll Ans[maxn];
vector<int> G[maxn];
vector<node> qr[maxn];
void clear() {
    bit.clear();
    for (int i = 1; i <= sz; ++i) {
        t[i] = 0;
        G[i].clear();
        qr[i].clear();
        Ans[i] = 0;
    }
    sz = 1;
}

void dfs(int u) {
    for (auto [tim, val] : qr[u]) bit.update(tim, val);
    Ans[u] = bit.query(q) - bit.query(t[u]);
    for (auto v : G[u]) dfs(v);
    for (auto [tim, val] : qr[u]) bit.update(tim, -val);
}

void solve() {
    cin >> q;
    bit.MX = q;
    clear();
    for (int i = 1; i <= q; ++i) {
        int op, v, x; cin >> op;
        if (op == 1) {
            cin >> v;
            t[++sz] = i;
            G[v].pb(sz);
        } else {
            cin >> v >> x;
            qr[v].pb({i, x});
        }
    }
    dfs(1);
    for (int i = 1; i <= sz; ++i) {
        cout << Ans[i] << " \n"[i == sz];
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
