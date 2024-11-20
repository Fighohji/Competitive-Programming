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

//ccddeneeeezmige
//ccddeneeeeezmig
//ccddeneeeeegzmi
//ccddeneeeeegimz
//ccddeneeeeegimz

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int las = 0;
    vector<int> pos;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] >= las) {
            las = s[i];
            ans++;
            pos.pb(i);
        }
    }
    string t = s;
    for (int i = 0; i < SZ(pos); ++i) {
        t[pos[SZ(pos) - i - 1]] = s[pos[i]];
    }
    sort(all(s));
    // cout << s << ' ' << t << '\n';
    if (s == t) {
        reverse(all(pos));
        while (SZ(pos) > 1 && s[pos[SZ(pos) - 1]] == s[pos[SZ(pos) - 2]]) {
            pos.pop_back();
        }
        cout << (int)SZ(pos) - 1 << '\n';
    } else {
        cout << "-1\n";
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
