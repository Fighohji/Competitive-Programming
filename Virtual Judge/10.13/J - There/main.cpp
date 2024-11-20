#include <array>
#include <climits>
#include <iostream>
#include <map>
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
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 2);
    string padding = "";
    for (int i = 0; i < m + 2; ++i)
        padding += '#';
    s[0] = s[n + 1] = padding;
    for (int i = n; i >= 1; --i) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    vector<vector<array<pii, 4>>> nxt(n + 2, vector<array<pii, 4>>(m + 2));
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (s[i][j] == '#')
                nxt[i][j][0] = {i, j};
            else
                nxt[i][j][0] = nxt[i - 1][j][0];
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            if (s[i][j] == '#')
                nxt[i][j][1] = {i, j};
            else
                nxt[i][j][1] = nxt[i][j - 1][1];
        }
    }
    for (int i = n + 1; i >= 0; --i) {
        for (int j = m + 1; j >= 0; --j) {
            if (s[i][j] == '#')
                nxt[i][j][2] = {i, j};
            else
                nxt[i][j][2] = nxt[i + 1][j][2];
        }
    }
    for (int i = n + 1; i >= 0; --i) {
        for (int j = m + 1; j >= 0; --j) {
            if (s[i][j] == '#')
                nxt[i][j][3] = {i, j};
            else
                nxt[i][j][3] = nxt[i][j + 1][3];
        }
    }
    map<char, int> d{
        {'D', 0},
        {'U', 2},
        {'R', 3},
        {'L', 1},
    };
    string t;
    cin >> t;
    int x = 1, y = 1;
    for (auto i : t) {
        // cerr << x << ' ' << y << '\n';
        auto tmp = nxt[x][y][d[i]];
        x = tmp.first, y = tmp.second;
        if (i == 'D') x++;
        if (i == 'U') x--;
        if (i == 'L') y++;
        if (i == 'R') y--;
    }
    cout << y << ' ' << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
