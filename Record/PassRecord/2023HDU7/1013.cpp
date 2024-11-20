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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct BIT {
    int MX;
    ll tr[maxn];
    void init(int n) {
        MX = n;
        for (int i = 1; i <= MX; ++i)
            tr[i] = 0;
    }
    void update(int x, int val) {
        while (x <= MX) {
            tr[x] += val;
            x += lowbit(x);
        }
    }
    ll query(int x) {
        ll sum = 0;
        while (x) {
            sum += tr[x];
            x -= lowbit(x);
        }
        return sum;
    }
} bit;


void solve(int cas) {
    ll n; cin >> n;
    // n = 2332;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        // a[i] = n - i + 1;
    }
    if (n == 1) {
        cout << 0 << ' ' << 1 << '\n';
        return ;
    }
    bit.init(n);
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += bit.query(n) - bit.query(a[i]);
        bit.update(a[i], 1);
    }
    ll mn = sum % 2 ? 2 : 0;
    ll mx = max(mn, mn ^ 1);
    for (int i = 0; i <= n - 1; ++i) {
        ll x = (n - i) * (n - i - 1) / 2;
        if (x % 2) x = 1;
        else x= 0;
        mx = max(mx, (n - i) ^ mn ^ (2 * x));
        mx = max(mx, (n - i) ^ mn ^ (2 * x) ^ 1);
    }
    cout << mn << ' ' << mx << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
