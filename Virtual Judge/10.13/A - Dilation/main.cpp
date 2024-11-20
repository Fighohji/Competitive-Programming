#include <climits>
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

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[8][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
    {-1,  1},
    { 1,  1},
    { 1, -1},
    {-1, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s, t;
    string padding;
    for (int i = 1; i <= m + 2; ++i)
        padding += '#';
    s.push_back(padding);
    for (int i = 1; i <= n; ++i) {
        s.push_back(string());
        cin >> s[i];
        s[i] = '#' + s[i] + '#';
    }
    s.push_back(padding);
    t.push_back(padding);
    for (int i = 1; i <= n; ++i) {
        t.push_back(string());
        for (int j = 0; j < m; ++j) {
            t[i] += '.';
        }
        t[i] = '#' + t[i] + '#';
    }
    t.push_back(padding);
    if (s == t) {
        cout << "Possible\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cout  << s[i][j];
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') continue;
            bool f = 1;
            for (int k = 0; k < 8; ++k) {
                if (s[i + dir[k][0]][j + dir[k][1]] == '.') { f = 0; }
            }
            if (f) t[i][j] = '#';
        }
    }
    // for (int i = 0; i <= n + 1; ++i)
    //     cout << t[i] << '\n';
    auto Ans = t;
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < 8; ++k) {
                int nx = dir[k][0] + i;
                int ny = dir[k][1] + j;
                if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                if (t[nx][ny] == '#') { vis[i][j] = 1; }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j])
                t[i][j] = '#';
        }
    }
    if (s == t) {
        cout << "Possible\n";
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j)
                cout << Ans[i][j];
            cout << '\n';
        }
     } else {
        cout << "Impossible\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
