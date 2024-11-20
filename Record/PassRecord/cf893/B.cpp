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

ll pre[maxn];
int val[maxn];
void solve() {
    int n, m, d; cin >> n >> m >> d;
    vector<int> s(m + 2);
    for (int i = 1; i <= m; ++i) {
        cin >> s[i];
        val[i] = 1;
    }
    for (int i = 0; i <= m + 1; ++i) pre[i] = 0;
    int l = 0, r = m + 1;
    s[0] = 1, s[m + 1] = n;
    val[0] = (s[1] != 1);
    val[m + 1] = 0;
    for (int i = l; i <= r; ++i) {
        pre[i] += val[i];
        if (i) pre[i] += pre[i - 1];
        if (i) pre[i] += (s[i] - s[i - 1] - val[i] - val[i - 1] + 1) / d;
    }
    ll Min = LINF, cnt = 0;
    // for (int i = 0; i <= m + 1; ++i) {
    //     cout << pre[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= m; ++i) {
        if (s[i] == 1) continue;
        ll Suf = pre[m + 1] - pre[i + 1];
        ll Pre = pre[i - 1];
        // cout << Pre << ' ' << Suf << '\n';
        ll Nmin = Pre + Suf + (s[i + 1] - s[i - 1] - val[i - 1] - val[i + 1] + 1) / d + val[i + 1];
        // cout << i << ' ' << Nmin << '\n';
        if (Nmin < Min) {
            Min = Nmin;
            cnt = 1;
        } else if (Min == Nmin) cnt++;
    }
    if (s[1] == 1) {
        ll Suf = pre[m + 1] - pre[1 + 1];
        ll Pre = pre[1 - 1];
        // cout << Pre << ' ' << Suf << '\n';
        ll Nmin = Pre + Suf + (s[1 + 1] - s[1 - 1] - val[1 - 1] - val[1 + 1] + 1) / d + val[1 + 1];
        // cout << i << ' ' << Nmin << '\n';
        Nmin++;
        if (Nmin < Min) {
            Min = Nmin;
            cnt = 1;
        } else if (Min == Nmin) cnt++;
    }
    cout << Min << ' ' << cnt << '\n';
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
