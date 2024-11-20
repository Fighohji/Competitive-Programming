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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int lg[maxn];

void solve() {
    int n, k; cin >> n >> k;
    int lim = lg[n - k + 1] + 1;
    string s; cin >> s;
    for (auto &i : s) {
        i = 97 - i;
    }
    vector<bool> vis(1 << lim);
    int Max = 1 << lim;
    int l = 0, r = 0, sum = 0;
    while (l < n && r < n) {
        while (r < n && sum < Max && r - l < k) {
            sum = sum * 2 + s[r] - '0';
            r++;
        }
        if (r - l == k && sum < Max) {
            vis[sum] = 1;
            sum -= ((s[l] - '0') << (r - l - 1));
            l++;
        }
        while (sum >= Max) {
            sum -= ((s[l] - '0') << (r - l - 1));
            l++;
        }
    }
    int ans = -1;
    int top = 1, tmp = k;
    while (top <= 1000000 && tmp) {
        top <<= 1;
        tmp -= 1;
    }
    for (int i = 0; i < top; ++i) {
        if (!vis[i]) {
            ans = i;
            break;
        }
    }
    if (ans == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<bool> Ans;
        int len = 0;
        while (ans) {
            Ans.pb(ans % 2);
            ans >>= 1;
            len++;
        }
        while (len < k) Ans.pb(0), len++;
        reverse(all(Ans));
        for (auto i : Ans) cout << i;
        cout << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 2; i <= 1000000; ++i) lg[i] = lg[i >> 1] + 1;
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
