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
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

map<char, int> d{
    {'S', 0},
    {'E', 1},
    {'N', 2},
    {'W', 3},
};

void solve() {
    int m;
    cin >> m;
    vector<pair<char, int>> Ans;
    int nx = 0, ny = 0;
    char flag = '?';
    cout << 2 * m - 1;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (flag == '?') {
            cout << ' ' << s[0] << '\n';
            flag = s[0];
        } else {
            if (d[s[0]] == (d[flag] + 1) % 4) {
                cout << 'L' << '\n';
            } else {
                cout << 'R' << '\n';
            }
            flag = s[0];
        }
        int x;
        cin >> x;
        cout << 'Z' << ' ' << x << '\n';
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
