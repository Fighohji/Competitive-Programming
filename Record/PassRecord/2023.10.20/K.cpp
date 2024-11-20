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

int n, q;

int trie[maxn][26], cnt[maxn], idx;
ll Ans[26][26];
ll sum = 0;
void ins(const string &s) {
    int now = 0;
    for (auto &i : s) {
        cnt[now]++;
        for (int j = 0; j < 26; ++j) {
            if (j == i - 'a') continue;
            if (trie[now][j]) Ans[i - 'a'][j] += cnt[trie[now][j]];
        }
        if (!trie[now][i - 'a']) trie[now][i - 'a'] = ++idx;
        now = trie[now][i - 'a'];
    }
    cnt[now]++;
    for (int i = 0; i < 26; ++i) {
        if (trie[now][i])
            sum += cnt[trie[now][i]];
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        ins(s);
    }

    while (q--) {
        string ord; cin >> ord;
        ll res = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < i; ++j) {
                res += Ans[ord[j] - 'a'][ord[i] - 'a'];
            }
        }
        cout << res + sum << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
