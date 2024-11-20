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
#define GG { cout << "NO\n"; return; }
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

bool BEGIN;

int get(char c) {
    if (isdigit(c)) return c - '0' + 26;
    if (isupper(c)) return c - 'A';
    return 36;
}
char rev(int c) {
    if (c >= 0 && c <= 25) return (char)(c + 'A');
    if (c > 25 && c < 36) return (char)(c - 26 + '0');
    return ' ';
}
string s;
void solve() {
    int n; cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    char c = getchar();
    // cout << (int)c << '\n';
    getline(cin, s);
    int l = SZ(s);
    int res = n - l % n;
    int tmp = res;
    if (res == n) res = 0;
    while(res) {
        s.pb(' ');
        res--;
    }
    l = SZ(s) / n;
    vector<vector<int>> vec(l, vector<int>(n));
    for (int i = 0; i < l * n; ++i) {
        int bl = i / n, id = i % n;
        vec[bl][id] = get(s[i]);
    }
    string Ans;
    for (int i = 0; i < l; ++i) {
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ans[j] += a[j][k] * vec[i][k] % 37;
                ans[j] %= 37;
            }
        }
        for (int j = 0; j < n; ++j) {
            Ans.pb(rev(ans[j]));
        }
    }
    for (int i = 0; i < n * l; ++i) {
        cout << Ans[i];
    }
    // cout << s << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
