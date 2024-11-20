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
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int idx;
map<ull, int> trie[maxn];
int val[maxn];
void ins(vector<ull> &node) {
    int now = 0;
    for (auto i : node) {
        if (!trie[now][i]) {
            trie[now][i] = ++idx;
        }
        now = trie[now][i];
    }
    val[now]++;
}
ll dp[maxn], dis[maxn];

void dfs(int u) {
    for (auto [v, nxt] : trie[u]) {
        if (trie[nxt].empty()) {
            dp[u] += val[nxt];
            dis[u] += val[nxt];
        }
        else
        {
            dfs(nxt);
            dp[u] += dp[nxt];
            dis[u] += dis[nxt] + dp[nxt];
        }

    }
}
void dfs2(int u)
{
    for (auto [v, nxt] : trie[u]) {
        if (trie[nxt].empty()) {
            continue;
        }
        else
        {
            dis[nxt] =  dis[u] - dp[nxt] + (dp[0] - dp[nxt]);
            dfs2(nxt);
        }

    }
}

void solve() {
    int n; cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        vector<ull> node;
        string s; cin >> s;
        int j = 0;
        while (j < s.length()) {
            j++;
            ull hs = 0;
            while (j < s.length() && s[j] != '/') {
                hs = hs * 131ull + s[j];
                j++;
            }
            node.pb(hs);
        }
        ins(node);
    }
    // cout << idx << '\n';
    dfs(0);
    dfs2(0);
    ll ans = LINF;
    for(int i = 0; i <= idx; ++i)
    {
        if(trie[i].empty()) continue;
        ans = min(ans, dis[i]);
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
