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
    vector<pii> g(m);
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        cin >> g[i].first >> g[i].second;
        if (g[i].first < g[i].second) cnt++;
    }
    cout << "YES\n";
    if (cnt >= m / 2) {
        vector<int> Ans;
        for (int i = 0; i < m; ++i) {
            if (g[i].first < g[i].second) {
                Ans.push_back(i);
            }
        }
        cout << Ans.size() << '\n';
        for (auto i : Ans) {
            cout << i + 1 << ' ';
        }
    } else {
        vector<int> Ans;
        for (int i = 0; i < m; ++i) {
            if (g[i].first > g[i].second) {
                Ans.push_back(i);
            }
        }
        cout << Ans.size() << '\n';
        for (auto i : Ans) {
            cout << i + 1 << ' ';
        }
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
