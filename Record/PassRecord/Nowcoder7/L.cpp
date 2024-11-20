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

#define int long long
int nxt[maxn];
il void getNxt(vector<int> &s) {
    int n = SZ(s) - 1;
    for (int i = 1; i <= n; ++i) nxt[i] = 0;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && s[i] != s[j + 1]) j = nxt[j];
        if (s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}
il void getF(vector<int> &s, vector<int> &t, vector<int> &f) {
    int n = SZ(s) - 1, m = SZ(t) - 1;
    for (int i = 1, j = 0; i <= m; ++i) {
        while (j && (j == n || t[i] != s[j + 1])) j = nxt[j];
        if (t[i] == s[j + 1]) j++;
        f[i] = j;
    }
}
void solve(int cas) {
    int n, m, b, p; cin >> n >> m >> b >> p;
    int ans = 0;
    int x = 0, y = 0, base = b % p;
    vector<int> s(n + 1);
    for (int i = 1; i <= n; ++i) cin >> s[i];
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int X, C; cin >> X >> C;
            int z = x * y;
            X = (X ^ z) % n + 1;
            C ^= z;
            s[X] = C;
        } else {
            int sz; cin >> sz;
            vector<int> t(sz + 1);
            int z = x * y;
            for (int i = 1; i <= sz; ++i) {
                cin >> t[i];
                t[i] ^= z;
            }
            if (sz < n) {
                x = 0;
            } else {
                vector<int> f(sz + 1, 0);
                getNxt(s);
                getF(s, t, f);
                int X = 0, Y = 0;
                for (int i = 1; i <= sz; ++i) {
                    if (f[i] == n) X++;
                }
                Y = nxt[n];
                ans = (ans + X * Y % p * base % p) % p;
                x = X, y = Y;
            }
            base = base * b % p;
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
