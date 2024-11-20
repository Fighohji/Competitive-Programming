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
#include <climits>
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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

#define int long long

int solve(int l, int r) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int idl = solve(l, mid);
    int idr = solve(mid + 1, r);
    int x, y = 0;
    if (r - l + 1 > 2) {
        cout << "? " << idl << ' ' << idr << endl;
        cin >> x;
        if (idl + 1 != idr) {
            cout << "? " << idl << ' ' << idr - 1 << endl;
            cin >> y;
        }
    } else {
        cout << "? " << idl << ' ' << idr << endl;
        cin >> x;
    }
    return x > y ? idl : idr;
}

bool END;
signed main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = solve(1, n);
        cout << "! " << ans << endl;
    }
    return 0;
}
