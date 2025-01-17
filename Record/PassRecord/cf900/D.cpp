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



void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> tmpl(k + 1), tmpr(k + 1);
    set<pii> st;
    for (int i = 1; i <= k; ++i) {
        cin >> tmpl[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> tmpr[i];
        st.insert({tmpr[i], tmpl[i]});
    }
    vector<int> pre(n + 1);
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        auto [r, l] = *st.lower_bound({x, 0});
        int L = min(x, r + l - x), R = max(x, r + l - x);
        pre[L - 1] ^= 1, pre[R] ^= 1;
    }
    for (int i = 1; i < n; ++i) {
        pre[i] ^= pre[i - 1];
    }
    for (int i = 1; i <= k; ++i) {
        tmpl[i]--, tmpr[i]--;
        for (int j = tmpl[i]; j <= (tmpl[i] + tmpr[i]) / 2; ++j) {
            if (pre[j]) swap(s[j], s[tmpr[i] - (j - tmpl[i])]);
        }
    }
    cout << s << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
