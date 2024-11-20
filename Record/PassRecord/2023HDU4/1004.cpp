#include <cstdlib>
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
uniform_int_distribution<ull> dist(0, INF);//use dist(rnd)

bool BEGIN;


ll qpow(ll base, ll power, ll p)
{
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}


void solve(int cas) {
    int n, m; cin >> n >> m;
    // int T = 10000;
    // db ans = 0;
    // while (T--) {
    //     int res = 0;
    //     vector<int> a(n);
    //     iota(all(a), 0);
    //     for (int i = 0; i < m; ++i) {
    //         int x = dist(rnd) % n, y = dist(rnd) % n;
    //         swap(a[x], a[y]);
    //     }
    //     for (int i = 0; i < n; ++i) {
    //         if (a[i] != i) {
    //             res++;
    //         }
    //     }
    //     ans += res;
    // }
    // cout << ans / 10000 << '\n';
    if (n == 1) {
        cout << 0 << '\n';
    } else if (m == 0) {
        cout << 0 << '\n';
    } else if (n == 2) {
        cout << 1 << '\n';
    } else {

    }
}

bool END;
signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(3);
    // int size(512<<20); // 512M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    exit(0);
}
