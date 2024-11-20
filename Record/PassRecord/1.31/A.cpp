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
void brute_force() {
    for (int i : {0, 1}) {
        for (int j : {0, 1}) {
            for (int x : {0, 1}) {
                for (int y : {0, 1}) {
                    cout << i << ' ' << j << ' ' << x << ' ' << y << '\n';
                    cout << (((x - i) * (x - i) % 2 ^ (y - j) * (y - j) % 2) % 2
                            == (((x + y) % 2) ^ ((i + j) % 2)) % 2) << '\n';
                }
            }
        }
    }
}
void solve() {
    int n; cin >> n;
    vector<pii> p(n + 1);
    vector<int> val(n + 1);
    set<int> buc[2];
    int st;
    for (int i = 0; i <= n; ++i) {
        cin >> p[i].fir >> p[i].sec;
        val[i] = (p[i].fir + p[i].sec) % 2;
        if (i) buc[val[i]].insert(i);
    }
    st = (p[0].fir + p[0].sec) % 2;
    if (SZ(buc[st]) >= SZ(buc[st ^ 1])) {
        cout << "First" << endl;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                int x; cin >> x;
                if (buc[0].count(x)) buc[0].erase(x);
                if (buc[1].count(x)) buc[1].erase(x);
            } else {
                if (buc[st ^ 1].empty()) {
                    cout << *buc[st].begin() << endl;
                    buc[st].erase(buc[st].begin());
                } else {
                    cout << *buc[st ^ 1].begin() << endl;
                    buc[st ^ 1].erase(buc[st ^ 1].begin());
                }
            }
        }
    } else {
        cout << "Second" << endl;
        for (int i = 0; i < n; ++i) {
            if (!(i & 1)) {
                int x; cin >> x;
                if (buc[0].count(x)) buc[0].erase(x);
                if (buc[1].count(x)) buc[1].erase(x);
            } else {
                if (buc[st].empty()) {
                    cout << *buc[st ^ 1].begin() << endl;
                    buc[st ^ 1].erase(buc[st ^ 1].begin());
                } else {
                    cout << *buc[st].begin() << endl;
                    buc[st].erase(buc[st].begin());
                }
            }
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // brute_force();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
