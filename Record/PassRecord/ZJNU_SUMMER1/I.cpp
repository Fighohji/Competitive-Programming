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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


struct Node {
    int val, id;
    Node () { val = 1; id = 0; }
    Node (int x, int y) { val = x, id = y; }
    bool operator < (const Node &t) const {
        return val < t.val;
    }
} Ans[maxn][2];
struct Seg_Info {
    struct Info {
        Node nd[2];
        Info () { nd[0] = nd[1] = Node(); }
        Info operator + (const Node &t) {
            Info np = *this;
            if (np.nd[0] < t) {
                np.nd[1] = np.nd[0];
                np.nd[0] = t;
            } else if (np.nd[1] < t) {
                np.nd[1] = t;
            }
            return np;
        }
    } node[maxn << 2];
    void update(int p, int l, int r, int ql, int qr, Node val) {
        if (ql <= l && r <= qr) {
            node[p] = node[p] + val;
            return ;
        }
        int mid = l + r >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
        if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
    }
    void dfs(int p, int l, int r, Info val = Info()) {
        val = val + node[p].nd[0];
        val = val + node[p].nd[1];
        if (l == r) {
            Ans[l][0] = val.nd[0];
            Ans[l][1] = val.nd[1];
            return ;
        }
        int mid = l + r >> 1;
        dfs(p << 1, l, mid, val);
        dfs(p << 1 | 1, mid + 1, r, val);
    }
} tr1;

struct Seg_Max {
    struct Max {
        int mx, lazy;
        Max () { mx = lazy = 0; }
        Max (int x, int y) { mx = x, lazy = y; }
    } node[maxn << 2];
    void push(int p) {
        if (node[p].lazy) {
            node[p << 1].mx += node[p].lazy;
            node[p << 1 | 1].mx += node[p].lazy;
            node[p << 1].lazy += node[p].lazy;
            node[p << 1 | 1].lazy += node[p].lazy;
            node[p].lazy = 0;
        }
    }
    void build(int p, int l, int r) {
        if (l == r) {
            node[p] = Max(l, 0);
            return;
        }
        int mid = l + r >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        node[p].mx = max(node[p << 1].mx, node[p << 1 | 1].mx);
    }
    void update(int p, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            node[p].mx += val;
            node[p].lazy += val;
            return ;
        }
        push(p);
        int mid = l + r >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
        if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
        node[p].mx = max(node[p << 1].mx, node[p << 1 | 1].mx);
    }
    int query() { return node[1].mx; }
    int query(int p, int l, int r, int pos) {
        if (l == r) return node[p].mx;
        push(p);
        int mid = l + r >> 1;
        if (pos <= mid) return query(p << 1, l, mid, pos);
        else return query(p << 1 | 1, mid + 1, r, pos);
    }
} tr2;

int n, m;
vector<int> G[maxn];
tuple<int, int, int> a[maxn];
void work(int x) {
    // cout << x << '\n';
    priority_queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        if (Ans[i][0].id == x) {
            q.emplace(Ans[i][1].val, i);
            // cout << Ans[i][1].val << ' ' << i << '\n';
        }
        else {
            q.emplace(Ans[i][0].val, i);
            // cout << Ans[i][0].val << ' ' << i << '\n';
        }
    }
    int now = n;
    vector<int> ans(n + 1);
    while (!q.empty()) {
        auto [x, y] = q.top(); q.pop();
        ans[y] = now--;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
}
void solve(int cas) {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int h, l, r; cin >> h >> l >> r;
        a[i] = {h, l, r};
        tr1.update(1, 1, n, l, r, Node(h, i));
    }
    tr1.dfs(1, 1, n);
    tr2.build(1, 1, n);
    for (int i = 1; i <= n; ++i) {
        if (Ans[i][0].id > 0) {
            G[Ans[i][0].id].eb(i);
        }
        tr2.update(1, 1, n, 1, Ans[i][0].val, 1);
    }
    for (int i = 1; i <= m; ++i) {
        for (auto v : G[i]) {
            tr2.update(1, 1, n, 1, Ans[v][0].val, -1);
            tr2.update(1, 1, n, 1, Ans[v][1].val, 1);
        }
        if (tr2.query() <= n + 1) {
            cout << "YES\n";
            work(i);
            return ;
        }
        for (auto v : G[i]) {
            tr2.update(1, 1, n, 1, Ans[v][0].val, 1);
            tr2.update(1, 1, n, 1, Ans[v][1].val, -1);
        }
    }
    cout << "NO\n";
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
