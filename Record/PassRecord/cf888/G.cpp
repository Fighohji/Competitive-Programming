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
#define GG { cout << "NO\n"; return; }
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

bool BEGIN;


void solve(int cas) {
    int n, m; cin >> n >> m;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    struct Info {
        int u, v, e, id;  
        int cp;
        bool operator<(const Info &t) const {
            return cp < t.cp;
        }
    };
    struct edge {
        int u, v;
        int mx;
        bool operator<(const edge &t) const {
            return mx < t.mx;
        }
    };
    vector<edge> e(m + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        e[i] = {u, v, max(h[u], h[v])};
    }
    sort(e.begin() + 1, e.end());
    int q; cin >> q;
    vector<Info> qr(q + 1);
    for (int i = 1; i <= q; ++i) {
        int u, v, c; cin >> u >> v >> c;
        qr[i] = {u, v, c, i, h[u] + c};
    }
    sort(qr.begin() + 1, qr.end());
    vector<int> fa(n + 1);
    iota(all(fa), 0);
    auto find = [&](auto self, int x) -> int{
        return x == fa[x] ? x :fa[x] = self(self, fa[x]);
    };
    int p = 1;
    vector<bool> ans(q + 1, 0);
    for (int i  = 1; i <= q; ++i) {
        int mx = qr[i].cp;
        while (p <= m && e[p].mx <= mx) {
            auto [u, v, w] = e[p];
            u = find(find, u);
            v = find(find, v);
            fa[u] = v;
            p++;
        }
        if (find(find, qr[i].u) == find(find, qr[i].v)) {
            ans[qr[i].id] = 1;
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << (ans[i] ? "Yes\n" : "No\n");
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

