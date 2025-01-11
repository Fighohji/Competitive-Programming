#include <climits>
#include <iostream>
#include <numeric>
#include <random> #include <set>
#include <set>
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

constexpr int N = 2e5 + 50;
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

struct DSU {
    vector<int> fa, siz;
    DSU(int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0);
        siz.resize(n + 1, 1);
    }
    int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (siz[x] > siz[y]) swap(x, y);
        fa[x] = y;
        siz[y] += siz[x];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    DSU dsu(n * m);
    auto getId = [&](int x, int y) -> int {
        return x * m + y;
    };
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != '.')
                tot++;
            else
                continue;
            for (int k = 0; k < 4; ++k) {
                int nx = dir[k][0] + i, ny = dir[k][1] + j;
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '.')
                    continue;
                dsu.merge(getId(i, j), getId(nx, ny));
            }
        }
    }
    if (dsu.siz[dsu.find(0)] == tot) {
        
        if (n == 1) {

        }

    } else {
        if (s[a][b] != 'R' || s[c][d] != 'B') {
            cout << "NO\n";
            return;
        }
        set<char> sr, sb;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (s[i][j] == '.') continue;
                if (dsu.find(getId(i, j)) == dsu.find(getId(a, b))) {
                    sr.insert(s[i][j]);
                } else if (dsu.find(getId(i, j)) == dsu.find(getId(c, d))) {
                    sb.insert(s[i][j]);
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        if (sr.size() != 1 || sb.size() != 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
