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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int n, q;

pii operator+ (const pii &x, const pii &y) {
    return {x.fir + y.fir, x.sec + y.sec};
}
pii operator- (const pii &x, const pii &y) {
    return {x.fir - y.fir, x.sec - y.sec};
}

void solve() {
    cin >> n >> q;
    string s; cin >> s;
    vector<pii> pre(n + 1), suf(n + 2);
    map<char, pii> di = {{'U', {0, 1}}, {'D', {0, -1}}, {'L', {-1, 0}}, {'R', {1, 0}}};
    map<pii, vector<int>> pr, su;
    pr[{0, 0}].pb(0);
    su[{0, 0}].pb(0);
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] + di[s[i - 1]];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + di[s[i - 1]];
        pr[pre[i]].pb(i);
        su[suf[i]].pb(i);
    }
    auto check = [&](const vector<int> &vec, int L, int R) -> bool {
        if (vec.empty() || L > R) return false;
        auto it = lower_bound(all(vec), L);
        if (it == vec.end()) return false;
        if ((*it) > R) return false;
        return true;
    };
    while (q--) {
        int x, y, l, r; cin >> x >> y >> l >> r;
        if (pr.count({x, y})) {
            if (check(pr[{x, y}], 0, l - 1) || check(pr[{x, y}], r + 1, n)) {
                cout << "YES\n";
                continue;
            }
        }
        pii now = {x, y};
        if (su.count(now - pre[l - 1] + suf[r + 1])) {
            if (check(su[now - pre[l - 1] + suf[r + 1]], l, r)) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
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
