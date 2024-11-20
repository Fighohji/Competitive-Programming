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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = count(all(s), 'B');
    // cout << cnt << '\n';
    if (cnt == k) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
        string t = s;
        for (int i = 0; i < n; ++i) {
            t[i] = 'A';
            if (count(all(t), 'B') == k) {
                cout << i + 1 << ' ' << 'A' << '\n';
                return ;
            }
        }
        t = s;
        for (int i = 0; i < n; ++i) {
            t[i] = 'B';
            if (count(all(t), 'B') == k) {
                cout << i + 1 << ' ' << 'B' << '\n';
                return ;
            }
        }

    }
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