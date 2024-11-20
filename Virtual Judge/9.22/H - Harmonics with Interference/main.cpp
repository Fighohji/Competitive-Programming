#include <cassert>
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
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*')
            pos.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] == '*') 
            pos.push_back(i + n);
    }
    assert(pos.size() <= 16); 
    int k = pos.size();
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            x += (1 << (n - i - 1));
    }
    for (int i = 0; i < m; ++i) {
        if (t[i] == '1')
            y += (1 << (m - i - 1));
    }
    for (int i = 0; i < (1 << k); ++i) {
        int dx = 0, dy = 0;
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) {
                if (pos[j] < n) {
                    dx += (1 << (n - pos[j] - 1));
                } else {
                    dy += (1 << (m - pos[j] + n - 1));
                }
            }
        }
        if ((x + dx) % (y + dy) == 0) {
            for (int i = n - 1; i >= 0; --i) {
                cout << ((x + dx) >> i & 1);
            }
            return;
        }
    }
    cout << "-1\n";
    assert(1 == 0);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
