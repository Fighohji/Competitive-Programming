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

constexpr int N = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};


int trie[N][26], idx, flag[N], fa[N], par[N];
void ins(const string &s, int id) {
    int u = 1;
    for (auto i : s) {
        if (!trie[u][i - 'a'])
            trie[u][i - 'a'] = ++idx;
        par[trie[u][i - 'a']] = u;
        u = trie[u][i - 'a'];
    }
    flag[u] = id;
}

int find(int x) {
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);
}
void dfs(int u) {
    for (int i = 0; i < 26; ++i) {
        if (trie[u][i])
            dfs(trie[u][i]);
    }
    if (u == 1) return ;
    int p = par[u], son = 0;
    for (int i = 0; i < 26; ++i)
        son += (trie[p][i] != 0 && !flag[p]);
    if (son == 1) {
        fa[p] = find(u);
    }
}
void solve() {
    idx = 1;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ins(s, i + 1);
    }
    string t;
    cin >> t;
    par[1] = 1;
    int cnt = 0, u = 1;
    for (int i = 1; i <= idx; ++i)
        fa[i] = i;
    dfs(1);
    for (char i : t) {
        if (i == 'B') {
            if (cnt)
                cnt--;
            else {
                u = par[u];
            }
        } else if (i == 'T') {
            if (!cnt) u = find(u);
        } else if (i == 'E') {
            if (flag[u] && !cnt) {
                cout << flag[u] << ' ';
            } else {
                cout << "-1 ";
            }
            u = 1, cnt = 0;
        } else {
            if (trie[u][i - 'a'] && !cnt) {
                u = trie[u][i - 'a'];
            } else {
                cnt++;
            }
        }
    }
}
/*
7 3
kill
killall
rm
rmdir
ifconfig
ifdown
ll
kTE
*/
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
