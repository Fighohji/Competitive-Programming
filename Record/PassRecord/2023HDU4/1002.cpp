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
constexpr int maxn = 1.2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int a[maxn], n, Len;
struct node {
    int v, w, id;
};
vector<node> e[maxn];

int cnt[maxn], Ans[maxn];
vector<int> tmp;
int Max[maxn * 21], root[maxn * 21], ls[maxn * 21], rs[maxn * 21], idx;

void build(int &rt, int l, int r) {
    if (!rt) rt = ++idx;
    if (l == r) {
        Max[rt] = cnt[l];
        return ;
    }
    int mid = l + r >> 1;
    build(ls[rt], l, mid); build(rs[rt], mid + 1, r);
    Max[rt] = max(Max[ls[rt]], Max[rs[rt]]);
}

void insert(int &rt, int rt0, int l, int r, int pos, bool rev) {
    if (!rt) rt = ++idx;
    if (l == r) {
        Max[rt] = (rev ? cnt[l] - 1 : 1);//残树的值？
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) insert(ls[rt], ls[rt0], l, mid, pos, rev);
    else insert(rs[rt], rs[rt0], mid + 1, r, pos, rev);
    Max[rt] = max(Max[ls[rt] ? ls[rt] : ls[rt0]], Max[rs[rt] ? rs[rt] : rs[rt0]]);
}

void merge(int &rtu, int rtv, int rt, bool rev, int l = 1, int r = Len) {
    if (!rtv || !rtu) {
        rtu |= rtv;
        return ;
    }
    if (l == r) {
        Max[rtu] += (rev ? Max[rtv] - cnt[l] : Max[rtv]);
        return ;
    }
    int mid = l + r >> 1;
    merge(ls[rtu], ls[rtv], ls[rt], rev, l, mid);
    merge(rs[rtu], rs[rtv], rs[rt], rev, mid + 1, r);
    Max[rtu] = max(Max[ls[rtu] ? ls[rtu] : ls[rt]], Max[rs[rtu] ? rs[rtu] : rs[rt]]);
}

int query(int rtu, int rt, int l, int r, int lim, bool rev) {
    if (Max[rtu ? rtu : rt] < lim) return 0;
    if (l == r) return tmp[l - 1];
    int mid = l + r >> 1;
    int res =  query(rs[rtu], rs[rt], mid + 1, r, lim, rev);
    if (res) return res;
    return query(ls[rtu], ls[rt], l, mid, lim, rev);
}

void dfs(int u, int p, bool rev) {
    insert(root[u], root[0], 1, Len, a[u], rev);
    for (auto [v, w, id] : e[u]) {
        if (v == p) continue;
        dfs(v, u, rev);
        Ans[id] = max(Ans[id], query(root[v], root[0], 1, Len, w, rev));
        merge(root[u], root[v], root[0], rev);
    }
}
void Clear() {
    for (int i = 1; i <= n; ++i) {
        root[i] = 0;
    }
    for (int i = 0; i <= idx; ++i) {
        root[i] = ls[i] = rs[i] = Max[i] = 0;    
    }
    idx = 0;
}

void solve(int cas) {
    cin >> n;
    tmp.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tmp.eb(a[i]);
        Ans[i] = 0;
        e[i].clear();
        cnt[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        e[u].pb({v, w, i});
        e[v].pb({u, w, i});
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    Len = SZ(tmp);
    for (int i = 1; i <= Len; ++i) cnt[i] = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(all(tmp), a[i]) - tmp.begin() + 1;
        cnt[a[i]]++;
    }
    dfs(1, 0, 0);
    Clear();
    build(root[0], 1, Len);
    dfs(1, 0, 1);
    for (int i = 1; i < n; ++i) {
        cout << Ans[i] << '\n';
    }
    Clear();
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("1002.in", "r", stdin);
    // freopen("ans.out", "w", stdout);
    int T; cin >> T; while (T--)
    solve(1);
    // fclose(stdin);
    // fclose(stdout);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    exit(0);
}
