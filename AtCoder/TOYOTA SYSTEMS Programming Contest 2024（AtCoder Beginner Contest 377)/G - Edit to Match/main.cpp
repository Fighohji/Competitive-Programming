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

int T[N][26], idx, Min[N], flag[N];
void ins(const string &s) {
    int u = 1;
    Min[u] = min(Min[u], (int)s.length());
    for (auto i : s) {
        if (!T[u][i - 'a']) T[u][i - 'a'] = ++idx;
        u = T[u][i - 'a'];
        Min[u] = min(Min[u], (int)s.length());
    }
    flag[u] = 1;
}
int qry(const string &s) {
    int Ans = s.length();
    int u = 1;
    int cnt = 0;
    for (auto i : s) {
        if (!T[u][i - 'a']) break;
        u = T[u][i - 'a'];
        cnt++;
        Ans = min(Ans, (int)s.length() - cnt + Min[u] - cnt);
    }
    return Ans;
}
void solve() {
    idx = 1;
    memset(Min, 0x3f, sizeof Min);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << qry(s) << '\n';
        ins(s);
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
