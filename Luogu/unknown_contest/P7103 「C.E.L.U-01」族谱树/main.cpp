#include <climits>
#include <cstring>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 5e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

namespace FastIOT {
const int bsz = 1 << 18;
char bf[bsz], *head, *tail;
inline char gc() {
    if (head == tail) tail = (head = bf) + fread(bf, 1, bsz, stdin);
    if (head == tail) return 0;
    return *head++;
}
template <typename T>
inline void read(T &x) {
    T f = 1;
    x = 0;
    char c = gc();
    for (; c > '9' || c < '0'; c = gc())
        if (c == '-') f = -1;
    for (; c <= '9' && c >= '0'; c = gc())
        x = (x << 3) + (x << 1) + (c ^ 48);
    x *= f;
}
template <typename T>
inline void print(T &x) {
    if (x < 0) putchar(45), x = -x;
    if (x > 9) print(x / 10);
    puchar(x % 10 + 48);
}
template <typename T>
inline void println(T &x) {
    print(x);
    putchar('\n');
}
} // namespace FastIOT
using namespace FastIOT;
int hea[N], cnt;
struct Edge {
    int nxt, v;
} edge[N << 1];

void add_edge(int u, int v) {
    edge[++cnt].nxt = hea[u];
    hea[u] = cnt;
    edge[cnt].v = v;
}

int in[N], out[N], idx;

int Min[N], Max[N], Ans[N], fa[N], id, Maxdep;

inline void dfs(int u, int p, int dep = 1) {
    fa[u] = p;
    in[u] = ++idx;
    if (Min[dep] == 0) Min[dep] = idx;
    Min[dep] = min(Min[dep], idx);
    Max[dep] = max(Max[dep], idx);
    if (dep > Maxdep) {
        Maxdep = dep;
        id = u;
    }
    for (int i = hea[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].v;
        if (v == p) continue;
        dfs(v, u, dep + 1);
    }
    out[u] = idx;
}

bool contain(int x, int y) { return x >= in[y] && x <= out[y]; }

void solve() {
    int n, m;
    // cin >> n >> m;
    read(n);
    read(m);
    memset(hea, -1, sizeof hea);
    for (int i = 1; i <= n; ++i) {
        int f;
        // cin >> f;
        read(f);
        if (i == 1) continue;
        add_edge(f, i);
        add_edge(i, f);
    }
    dfs(1, 0);
    for (int i = Maxdep; i >= 1; --i) {
        while (!contain(Min[i], id) || !contain(Max[i], id)) {
            id = fa[id];
        }
        Ans[i] = id;
    }
    for (int i = 0; i < m; ++i) {
        int k;
        // cin >> k;
        read(k);
        // cout << Ans[k] << '\n';
        printf("%d\n", Ans[k]);
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
