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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
int n;


void solve(int cas) {
    cin >> n;
    vector<pii> a(n + 1);
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fir;
        a[i].sec = i;
    }
    sort(a.begin() + 1, a.end());
    int l = 1, r = n;
    while (l < r) {
        // cout << l << ' ' <<r  << '\n';
        int dif = a[r].fir - a[l].fir;
        int mid = a[l].fir + a[r].fir >> 1;
        if (dif % 2) {
            int l1 = a[l].fir, r1 = mid;
            int l2 = mid + 1, r2 = a[r].fir;
            int pos = lower_bound(a.begin() + l, a.begin() + r + 1, mkp(l2, 0)) - a.begin();
            int cnt = r - pos + 1;
            int res = r - l + 1 - cnt;
            if (cnt <= res) {
                r--;
            } else l++;

        } else {
            int l1 = a[l].fir, r1 = mid;
            int l2 = mid + 1, r2 = a[r].fir;
            // cout << l1 <<' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';
            int pos = lower_bound(a.begin() + l, a.begin() + r + 1, mkp(l2, 0)) - a.begin();
            // cout << pos << '\n';
            int cnt = r - pos + 1;
            int res = r - l + 1 - cnt;
            if (cnt <= res) {
                r--;
            } else l++;
        }
    }
    cout << a[l].sec << '\n';
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
