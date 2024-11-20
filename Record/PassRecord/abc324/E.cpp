#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct SequenceAutoMaton {
    vector<vector<int> > nxt;
    void init(int n, int char_size, const string &s) {
        nxt.clear();
        nxt.resize(n + 1, vector<int>(char_size, n));
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
    }
};
string S[maxn];
ll dp[maxn];
void solve() {
    int n; cin >> n;
    string t; cin >> t;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        S[i] = s;
        int m = s.length();
        SequenceAutoMaton sq = SequenceAutoMaton();
        sq.init(m, 26, s);
        int now = -1;
        int idx = 0;
        while (now < m && idx < t.length()) {
            int nxt = sq.nxt[now + 1][t[idx] - 'a'];
            if (nxt < m) dp[idx]++;
            now = nxt;
            idx++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        SequenceAutoMaton sq = SequenceAutoMaton();
        reverse(all(S[i]));
        int m = S[i].length();
        sq.init(S[i].length(), 26, S[i]);
        int now = -1;
        int idx = t.length() - 1;
        while (now < m && idx >= 0) {
            int nxt = sq.nxt[now + 1][t[idx] - 'a'];
            now = nxt;
            if (now >= m) break;
            idx--;
        }
        // cout << idx << '\n';
        if (idx >= 0) ans += dp[idx];
        else ans += n;
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
