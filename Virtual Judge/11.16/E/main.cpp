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

    if (n % 4 == 0) {
        cout << "YES\n";
        int id = 0;
        vector<vector<int>> Ans(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; j += 4) {
                id++;
                for (int k = 0; k < 4; ++k) {
                    Ans[j + k][i] = id;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cout << Ans[i][j] << " \n"[j == m];
            }
    } else if (m % 4 == 0) {
        cout << "YES\n";
        int id = 0;
        vector<vector<int>> Ans(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; j += 4) {
                id++;
                for (int k = 0; k < 4; ++k) {
                    Ans[i][j + k] = id;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cout << Ans[i][j] << " \n"[j == m];
            }
    } else if (n % 2 == 0 && m % 2 == 0) {
        if (n == 2 && m == 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            bool flag = 1;
            if (n > m) swap(n, m), flag = 0;
            vector<vector<int>> Ans(n + 1, vector<int>(m + 1));
            int id = 0;
            for (int i = 1; i <= n; i += 2) {
                for (int j = 1; j <= 3; ++j) {
                    Ans[i][j] = id + 1;
                    Ans[i][j + 3] = id + 2;
                }
                Ans[i + 1][1] = id + 1, Ans[i + 1][6] = id + 2;
                for (int j = 2; j <= 5; ++j)
                    Ans[i + 1][j] = id + 3;
                id += 3;
                for (int j = 7; j <= m; j += 4) {
                    for (int k = 0; k < 4; ++k) {
                        Ans[i][j + k] = id + 1;
                        Ans[i + 1][j + k] = id + 2;
                    }
                    id += 2;
                }
            }
            if (!flag) {
                for (int i = 1; i <= m; ++i)
                    for (int j = 1; j <= n; ++j) {
                        cout << Ans[j][i] << " \n"[j == n];
                    }
            } else {
                for (int i = 1; i <= n; ++i)
                    for (int j = 1; j <= m; ++j) {
                        cout << Ans[i][j] << " \n"[j == m];
                    }
            }
        }
    } else {
        cout << "NO\n";
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

