#include <climits>
#include <deque>
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
    string s;
    cin >> s;
    if (s.length() == 1) {
        cout << 0 << '\n';
        return ;
    }
    int n = s.length();
    s = s + s;
    int Ans = 0;
    int cnt = 0;
    deque<pair<int, int>> q;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] == s[i]) j++;
        q.push_back({i, j - 1});
        cnt += (j - i) / 2;
        i = j;
    }
    Ans = cnt;
    for (int i = n; i < 2 * n; ++i) {
        auto &[x, y] = q.front();
        q.pop_front();
        cnt -= (y - x + 1) / 2;
        x++;
        if (x <= y) q.push_front({x, y});
        cnt += (y - x + 1) / 2;

        if (s[i] == s[i - 1]) {
            auto &[x, y] = q.back();
            cnt -= (y - x + 1) / 2;
            q.pop_back();
            y++;
            cnt += (y - x + 1) / 2;
            q.push_back({x, y});
        } else {
            q.push_back({i, i});
        }
        Ans = min(Ans, cnt);
    }
    cout << Ans << '\n';
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
