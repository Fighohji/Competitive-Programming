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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


void solve(int cas) {
    int n, k;
    cin >> n >> k;
    if (n == k || k == n - 2) {
        cout << "-1\n";
        return ;
    }
    if (k) {
        int p = k + 1;
        vector<pii> ans;
        for (int i = 1; i <= k; ++i) {
            ans.eb(i, p);
        }
        for (int i = p + 1; i <= n; ++i) {
            ans.eb(p, i);
        }
        for (int i = p + 1; i < n; i += 2) {
            ans.eb(i, i + 1);
        }
        if ((n - p) % 2) {
            ans.eb(p + 1, n);
        }
        cout << SZ(ans) << '\n';
        for (auto i : ans) {
            cout << i.fir << ' ' << i.sec << '\n';
        }
    } else {
        if (n == 3 || n == 4 || n == 5) {
            cout << n << "\n";
            for (int i = 1; i <= n; ++i) {
                cout << (i - 1) % n + 1 << ' ' << i % n + 1 << '\n';
            }
        } else {
            vector<pii> ans1, ans2;
            for (int i = 1; i < n; ++i) {
                ans1.eb(i, n);
            }
            for (int i = 1; i < n - 1; i += 2) {
                ans1.eb(i, i + 1);
            }
            if (n % 2 == 0) {
                ans1.eb(1, n - 1);
            }
            ans2.eb(1, 2);
            ans2.eb(1, 3);
            ans2.eb(2, 4);
            for (int i = 5; i <= n; ++i) {
                ans2.eb(i, 3);
                ans2.eb(i, 4);
            }
            if (SZ(ans1) > SZ(ans2)) {
                cout << SZ(ans2) << '\n';
                for (auto i : ans2) {
                    cout << i.fir << ' ' << i.sec << '\n';
                }
             } else {
                cout << SZ(ans1) << '\n';
                for (auto i : ans1) {
                    cout << i.fir << ' ' << i.sec << '\n';
                }

             }
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
