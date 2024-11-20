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

int qry(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int t; cin >> t;
    return t;
}

int solve(int l, int r) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int idl = solve(l, mid);
    int idr = solve(mid + 1, r);
    int x = 0, y = 0;
    x = qry(idl, idr);
    if (idl + 1 != idr) y = qry(idl, idr - 1);
    return x > y ? idl : idr;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // brute_force();
    int _ = 1;
    cin >> _;
    while (_--) {
        int n; cin >> n;
        int Ans = solve(1, n);
        cout << "! " << Ans << endl;
    }
    return 0;
}
