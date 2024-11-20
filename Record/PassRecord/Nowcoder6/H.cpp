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
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
#define int long long
int CNT;
struct Line {
    int k, b;
    Line() {}
    Line(int _k, int _b) : k(_k), b(_b) {}
    int getY(int x) { return k * x + b; }
} s[maxn];

int cmp(int x, int y) {
    if (x > y) return 1;
    if (y > x) return -1;
    return 0;
}
pii pmax(pii x, pii y) {
    if (x.fir < y.fir) return y;
    if (x.fir > y.fir) return x;
    return x.sec < y.sec ? x : y;
}

void add(int k, int b) { s[++CNT] = Line(k, b); }

struct LcSeg {
    int node[maxn << 2];
    
    void upd(int p, int l, int r, int u) {
        int &v = node[p], mid = l + r >> 1;
        int flag = cmp(s[u].getY(mid), s[v].getY(mid)); //判断中点
        if (flag == 1 || (!flag && u < v)) swap(u, v);
        int flagl = cmp(s[u].getY(l), s[v].getY(l)), flagr = cmp(s[u].getY(r), s[v].getY(r));
        if (flagl == 1 || (!flagl && u < v)) upd(p << 1, l, mid, u);
        if (flagr == 1 || (!flagr && u < v)) upd(p << 1 | 1, mid + 1, r, u);
    }
    void update(int p, int l, int r, int ql, int qr, int u) {
        if (ql <= l && r <= qr) {
            upd(p, l, r, u);
            return ;
        }
        int mid = l + r >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, u);
        if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, u);
    }
    pii query(int p, int l, int r, int x) {
        if (r < x || x < l) return {0, 0};
        int mid = l + r >> 1;
        int res = s[node[p]].getY(x);
        if (l == r) return {res, node[p]};
        return pmax({res, node[p]}, pmax(query(p << 1, l, mid, x),
                                        query(p << 1 | 1, mid + 1, r, x)));
    }
} Seg[4];
int Ansk, Ansb;
map<pii, bool> mp;
void solve(int cas) {
    int n, T; cin >> n >> T;
    vector<vector<pair<int, Line>>> e(n + 1), G(n + 1);
    vector<int> deg(n + 1, 0);
    bool f = 0;
    for (int i = 1; i <= n + 1; ++i) {
        int u, v, k, b; cin >> u >> v >> k >> b;
        Line l(k, b);
        Ansb += b;
        Ansk += k;
        e[u].pb({v, l}); e[v].pb({u, l});
        deg[u]++; deg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) 
            q.push(i);
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        if (!deg[p]) continue;
        deg[p]--;
        for (auto [v, l] : e[p]) {
            if (deg[v]) deg[v]--;
            if (deg[v] == 1) q.push(v); 
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) continue;
        for (auto [v, l] : e[i]) {
            if (!deg[v]) continue;
            G[i].pb({v, l});
        }
    }
    vector<vector<Line>> link(4);
    int cnt = 0;
    auto dfs = [&](auto self, int u) -> void {
        if (deg[u] > 2 || !deg[u]) return ;
        deg[u] = 0;
        for (auto [v, l] : G[u]) {
            if (!deg[v]) continue;
            link[cnt].pb(l);
            self(self, v);
        }
    };
    int mx = *max_element(all(deg));
    bool flag = 0;
    vector<int> pos;
    if (mx == 3) {
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 3) {
                pos.pb(i);
            }
        }
        vector<bool> vis(n + 1, 0);
        auto Try = [&](auto self, int u) -> void {
            if (vis[u] || deg[u] == 3) return ;
            vis[u] = 1;
            for (auto [v, l] : G[u]) {
                self(self, v);
            }  
        };
        auto get = [&]() -> void {
            for (int i = 1; i <= n; ++i) {
                if (!deg[i] || vis[i]) continue;
                for (auto [v, l] : G[i]) {
                    if (i > v) continue;
                    if (vis[v]) continue;
                    link[cnt].pb(l);
                }
            }
        };
        auto work = [&]() -> bool {
            vis[pos[0]] = 1;
            for (auto [v, l] : G[pos[0]]) {
                Try(Try, v);
            }
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i] && deg[i]) res++;
            }
            if (res == 1) return 0;
            ++cnt;
            get();
            fill(all(vis), 0);
            vis[pos[1]] = 1;
            for (auto [v, l] : G[pos[1]]) {
                Try(Try, v);
            }
            ++cnt;
            get();
            return 1;
        };
        flag = work();
    }
    if (!flag) {
        if (mx == 4) {
            for (int i = 1; i <= n; ++i) {
            if (deg[i] == 2) {
                    ++cnt;
                    dfs(dfs, i);
                }
            }
        } else {
            vector<bool> vis(n + 1, 0);
            vis[pos[0]] = 1;
            for (auto [v, l] : G[pos[0]]) {
                int now = v;
                ++cnt;
                link[cnt].pb(l);
                while (deg[now] < 3 && !vis[now]) {
                    vis[now] = 1;
                    for (auto [nxt, nl] : G[now]) {
                        if (vis[nxt]) continue;
                        now = nxt; l = nl;
                        link[cnt].pb(l);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        cout << i << '\n';
        for (auto l : link[i]) {
            cout << l.k << ' ' << l.b << '\n';
            add(l.k, l.b);
            Seg[i].update(1, 0, T, 0, T, CNT);
        }
    }
    for (int i = 0; i <= T; ++i) {
        int Ans = Ansk * i + Ansb;
        vector<int> tmp;
        for (int j = 1; j <= cnt; ++j) {
            tmp.pb(Seg[j].query(1, 0, T, i).fir);
        }
        sort(all(tmp));
        for (int j = SZ(tmp) - 1; j >= SZ(tmp) - 2; --j) {
            Ans -= tmp[j];
        }
        cout << Ans << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

