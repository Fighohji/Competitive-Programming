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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


int n, k;
int cost[5005];
int trie[1000005][26], idx;
int val[1000005];
void insert(string &s) {
    int now = 1;
    int m = s.length();
    for (int i = 0; i < m; ++i) {
        if (!trie[now][s[i] - 'a'])
            trie[now][s[i] - 'a'] = ++idx;
        now = trie[now][s[i] - 'a'];
        val[now] = min(val[now], cost[(k - (m - i - 1) % k) % k] + (m - i - 1 + k - 1) / k + ((k - (m - i - 1) % k) % k > 0));
    }
}

int dp[5005];
string s[maxn];
void solve() {
    for (int i = 1; i <= idx; ++i) {
        for (int j = 0; j < 26; ++j)
            trie[i][j] = 0;
        val[i] = INF;
    }
    idx = 1;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) cost[i] = INF;
    cost[0] = 0;
    set<int> len;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        cost[SZ(s[i]) % k] = min(SZ(s[i]) / k, cost[SZ(s[i]) % k]);
        len.insert(SZ(s[i]));
    }
    for(int j = 0; j < 6; ++j)
        for (auto L : len) {
            for (int i = 0; i < k; ++i)
                cost[(i + L) % k] = min(cost[(i + L) % k], cost[i] + 1 + (i + L) / k);
            for (int i = 0; i < k; ++i)
                cost[(i + L) % k] = min(cost[(i + L) % k], cost[i] + 1 + (i + L) / k);
        }

    for (int i = 0; i < n; ++i) insert(s[i]);
    string t; cin >> t;
    int tl = t.length();
    for (int i = 0; i <= tl; ++i) dp[i] = INF;
    dp[0] = 0;
    for (int i = 0; i < tl; ++i) {
        int now = 1;
        for (int j = i; j < tl; ++j) {
            now = trie[now][t[j] - 'a'];
            if (!now) break;
            dp[j + 1] = min(dp[j + 1], dp[i] + val[now] + 1);
        }
    }
    if (dp[tl] == INF) {
        cout << "-1\n";
    } else {
        cout << dp[tl] << '\n';
    }
}
/*
2
2 3
defgh
abc
abcde
1 1
a
b

*/
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i <= 1000000; ++i)
        val[i] = INF;
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
