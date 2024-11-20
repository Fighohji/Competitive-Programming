#include <climits>
#include <iostream>
#include <set>
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
    string s;
    cin >> s;
    string t = s;
    int n;
    cin >> n;
    int k = s.length();
    while (k < n) {
        s += t;
        k += s.length();
    }
    while (k > n) {
        s.pop_back();
        k--;
    }
    set<string> vis;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vis.insert(s.substr(i, j - i + 1));
        }
    }
    cout << vis.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

