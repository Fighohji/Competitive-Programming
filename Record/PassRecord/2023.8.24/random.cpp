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


void solve() {
    int n = dist(rnd) % 4 + 3, k = dist(rnd) % (n - 2) + 2;
    int p = n * n / 2;
    int x = dist(rnd) % p;
    int y = x + 1 * (dist(rnd) % 2 ? 1 : -1);
    cout << n << ' ' << k << '\n';
    vector<char> a(n * n);
    for (int i = 0; i < n * n; ++i) {
        if (x) {
            x--;
            a[i] = 'x';
            continue;
        }
        if (y) {
            y--;
            a[i] = 'o';
            continue;
        }
        a[i] = '.';
    }
    random_shuffle(all(a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i * n + j];
        }
        cout << '\n';
    }
}

bool END;
signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(10);
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T;
    cout << (T = 100) << '\n';
    while (T--)
    solve();
    fclose(stdin);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
