
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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct Hash1 {
    ull seed = 131, p = 998244853;
    ull hash[maxn], power[maxn];
    void init(const string &s) {
        power[0] = 1;
        for (int i = 1; i <= SZ(s); ++i) {
            hash[i] = hash[i - 1] * seed + s[i - 1];
            power[i] = power[i - 1] * seed;
        }
    }
    ull get_hash(int l, int r) {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1];
        return a - b;
    }
} hs1;


void solve() {
    int n; cin >> n;
    string t;
    vector<string> s(n);
    vector<ull> hs(n);
    vector<int> len(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        len[i] = s[i].length();
        for (char j : s[i]) {
            hs[i] = hs[i] * 131 + j;
        }
    }
    cin >> t;
    hs1.init(t);
    vector<int> dp(t.length() + 1);
    dp[0] = 1;
    for (int i = 1; i <= t.length(); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - len[j] >= 0)
                dp[i] |= (dp[i - len[j]] & (hs[j] == hs1.get_hash(i - len[j], i - 1)));
        }
    }
    cout << (dp[t.length()] ? "YES" : "NO");
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
