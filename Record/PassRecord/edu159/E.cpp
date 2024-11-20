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

constexpr int maxn = 1e6 + 5;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int trie[maxn][26], idx, cnt[maxn];

void ins(const string &s) {
    int p = 0;
    for (auto i : s) {
        if (!trie[p][i - 'a'])
            trie[p][i - 'a'] = ++idx;
        p = trie[p][i - 'a'];
        cnt[p]++;
    }
}

ll query(const string &s) {
    int p = 0;
    ll res = 0;
    for (auto i : s) {
        if (!trie[p][i - 'a'])
            break;
        p = trie[p][i - 'a'];
        res += 2 * cnt[p];
    }
    return res;
}

string s[maxn];

void solve() {
    int n; cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        ins(s[i]);
        sum += 2ll * n * s[i].length();
    }
    for (int i = 0; i < n; ++i) {
        reverse(all(s[i]));
        sum -= query(s[i]);
    }
    cout << sum << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
