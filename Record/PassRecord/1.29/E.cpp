#include <map>
#include <numeric>
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

constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

pii c[maxn];

namespace DSU  {
    ll ans = 0;
    int fa[maxn];
    priority_queue<int, vector<int>, greater<int>> used[maxn];
    priority_queue<int> buc[maxn];
    void init(int n) {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
    }
    int find(int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        int xx = find(x), yy = find(y);
        if (xx == yy) return;
        if (SZ(buc[xx]) + SZ(used[xx]) > SZ(buc[yy]) + SZ(used[yy])) swap(xx, yy);
        while (!used[xx].empty()) {
            used[yy].push(used[xx].top());
            used[xx].pop();
        }
        while (!buc[xx].empty()) {
            buc[yy].push(buc[xx].top());
            buc[xx].pop();
        }
        while (!buc[yy].empty() && !used[yy].empty() && used[yy].top() < buc[yy].top()) {
            ans -= used[yy].top();
            ans += buc[yy].top();
            int tmpx = used[yy].top();
            int tmpy = buc[yy].top();
            used[yy].pop();
            buc[yy].pop();
            used[yy].push(tmpy);
            buc[yy].push(tmpx);
        }
        fa[xx] = yy;
    }
}
using namespace DSU;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &t)const {
        return w < t.w;
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> a(n + 1), b(m + 1);
    vector<pii> qry(q + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i].fir = a[i];
        c[i].sec = 1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        c[i + n].fir = b[i];
        c[i + n].sec = 0;
    }
    sort(c + 1, c + 1 + n + m);
    for (int i = 1; i <= n + m; ++i) {
        if (c[i].sec) used[i].push(c[i].fir);
        else buc[i].push(c[i].fir);
        ans += c[i].fir * c[i].sec;
    }
    vector<Edge> e;
    for (int i = 2; i <= n + m; ++i) {
        e.eb(i - 1, i, c[i].fir - c[i - 1].fir);
    }
    sort(all(e));
    for (int i = 1; i <= q; ++i) {
        cin >> qry[i].fir;
        qry[i].sec = i;
    }
    sort(qry.begin() + 1, qry.end());
    vector<ll> Ans(q + 1);
    init(n + m);
    int j = 0;
    for (int i = 1; i <= q; ++i) {
        while (j < SZ(e) && e[j].w <= qry[i].fir) {
            merge(e[j].u, e[j].v);
            ++j;
        }
        Ans[qry[i].sec] = ans;
    }
    for (int i = 1; i <= q; ++i) {
        cout << Ans[i] << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
