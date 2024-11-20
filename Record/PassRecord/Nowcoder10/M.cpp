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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int trans(string s) {
    int res = 0;
    for (auto i : s) {
        res = res * 10 + i - '0';
    }
    return res;
}

bool check(string x, string y, string z) {
    // cout << x << ' ' << y << ' ' << z << '\n';
    int X = 0, Y = 0, Z = 0;
    X = trans(x); Y = trans(y), Z = trans(z);
    if (X + Y == Z) {
        cout << "Yes\n";
        cout << X << " + " << Y << " = " << Z << '\n';
    }
    return X + Y == Z;
}

void solve() {
    string x, y, z; string tmp;
    cin >> x >> tmp;
    cin >> y >> tmp;
    cin >> z;
    if (check(x, y, z)) {
        return ;
    }
    for (int i = 0; i <= SZ(x); ++i) {
        for (char c = '0'; c <= '9'; ++c) {
            if (check(x.substr(0, i) + c + (i != SZ(x) ? x.substr(i) : ""), y, z)) {
                // cout << "Yes\n";
                return ;
            }
        }
    }
    for (int i = 0; i <= SZ(y); ++i) {
        for (char c = '0'; c <= '9'; ++c) {
            if (check(x, y.substr(0, i) + c + (i != SZ(y) ? y.substr(i) : ""), z)) {
                // cout << "Yes\n";
                return ;
            }
        }
    }
    for (int i = 0; i <= SZ(z); ++i) {
        for (char c = '0'; c <= '9'; ++c) {
            if (check(x, y, z.substr(0, i) + c + (i != SZ(z) ? z.substr(i) : ""))) {
                // cout << "Yes\n";
                return ;
            }
        }
    }
    cout << "No\n";
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
