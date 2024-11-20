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
int w[300];
void solve() {
    string s;
    cin >> s;
    int Ans = 0;
    int n = s.length();
    int j = n - 1, i = j;
    while (j >= 0) {
        i = j - 1;
        while (i >= 0 && w[s[i]] < w[s[j]]) {
            Ans -= w[s[i]];
            i--;
        }
        Ans += w[s[j]];
        j = i;
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    w['I'] = 1, w['V'] = 5, w['X'] = 10, w['L'] = 50;
    w['C'] = 100, w['D'] = 500, w['M'] = 1000;
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
