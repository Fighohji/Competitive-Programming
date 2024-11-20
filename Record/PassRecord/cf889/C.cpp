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

#define int long long

void solve(int cas){
    int n; cin >> n;
    vector<int> a(n + 1);
    bool f = 0, f1 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) f = 1;
        if (a[i] > 0) f1 = 1;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return ;
    }
    if (!f) {
        cout << "0\n";
        return ;
    }
    vector<pii> ans;
    if (f1) {
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) {
                pos = i;
                break;
            }
        }
        if (pos != n) {
            while (a[n] + a[pos] <= 0) {
                ans.eb(pos, pos);
                a[pos] *= 2;
            }
            if (a[n] <= 0) {
                ans.eb(n, pos);
                a[n] += a[pos];
            }
        }//让a[n] > 0
        while (a[n] <= 64) {
            ans.eb(n, n);
            a[n] = a[n] * 2;
        }
        for (int i = 2; i < n; ++i) {

            ans.eb(n, n);


            ans.eb(i, n);

        }

            ans.eb(n, n);

    } else {
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) {
                pos = i;
                break;
            }
        }
        if (pos != 1) {
            while (a[1] + a[pos] >= 0) {
                a[pos] *= 2;
                ans.eb(pos, pos);
            }
            if (a[1] >= 0) {
                a[1] += a[pos];
                ans.eb(1, pos);
            }
        }//a[1] < 0
        while (a[1] >= -64) {
            a[1] *= 2;
            ans.eb(1, 1);
        }
        for (int i = n - 1; i >= 1; --i) {
                ans.eb(1, 1);
                ans.eb(i, 1);
        }

            ans.eb(1, 1);

    }
    cout << SZ(ans) << '\n';
    for (auto i : ans) {
        cout << i.fir << ' ' << i.sec << '\n';
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
