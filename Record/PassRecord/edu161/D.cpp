#include <iterator>
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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    set<int> s, t;
    for (int i = 1; i <= n; ++i) s.insert(i);
    auto judge = [&](auto idx) {
        if (idx == s.end()) return false;
        int res = 0;
        if (idx != s.begin()) res += a[*prev(idx)];
        if (next(idx) != s.end()) res += a[*next(idx)];
        return res > d[*idx];
    };
    for (set<int>::iterator i = s.begin(); i != s.end(); ++i) {
        // cout << *i << ' ';
        if (judge(i)) {
            t.insert(*i);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << SZ(t) << ' ';
        set<int> nt;
        for (auto it : t) s.erase(it);
        for (auto it : t) {
            // cout << it << ' ';
            if (judge(s.lower_bound(it))) {
                nt.insert(*(s.lower_bound(it)));
            }
            if (s.lower_bound(it) != s.begin() && judge(prev(s.lower_bound(it)))) {
                nt.insert(*(prev(s.lower_bound(it))));
            }
        }
        t.swap(nt);
    }
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
