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

struct node {
    bool l, r, cnt;
} mat[3005][3005];

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < n; ++j) {
            mat[i][j + 1] = (node){0, 0, (bool)(s[j] - '0')};
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int pre = 0;
        for (int j = 1; j <= n; ++j) {
            if (mat[i][j].l) pre ^= 1;
            mat[i][j].cnt ^= pre;
            mat[i + 1][max(j - 1, 1)].l ^= mat[i][j].cnt;
            mat[i + 1][min(j + 1, n)].r ^= mat[i][j].cnt;
            mat[i + 1][max(j - 1, 1)].l ^= mat[i][j].l;
            mat[i + 1][min(j + 1, n)].r ^= mat[i][j].r;
            if (mat[i][j].cnt) ans++;
            if (mat[i][j].r) pre ^= 1;
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

