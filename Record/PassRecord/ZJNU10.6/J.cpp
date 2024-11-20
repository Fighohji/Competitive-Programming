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

int a[maxn];
int pos[maxn], n;
int query_mex(int l, int r) {
    for (int i = 0; i < n; ++i) {
        if (pos[i] < l || pos[i] > r)
            return i;
    }
    return n;
}

int simulate(int n, int q, int k, int s) {
    std::mt19937 gen;
    gen.seed(s);
    int last = 0;
    while (q--) {
        int op = gen() % k;
        int i = (gen() + last) % n;
        if (!op && i) {
            std::swap(pos[a[i - 1]], pos[a[i]]);
            std::swap(a[i - 1], a[i]);
        } else {
            int j = gen() % n;
            last ^= query_mex(min(i, j), max(i, j));
        }
    }
    return last;
}

void solve() {
    int q, k, s; cin >> n >> q >> k >> s;
    pos[n] = n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    cout << simulate(n, q, k, s);
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
