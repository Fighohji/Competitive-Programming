#include <chrono>
#include <locale>
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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define maxm maxn

int st_min[19][maxm], st_max[19][maxm];

int lg[maxm];
int n;
void build_st(vector<int> &a) {
    for (int i = 2; i <= n; ++i)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; ++i)
        st_min[0][i] = st_max[0][i] = a[i];
    for (int j = 1; j <= 18; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st_min[j][i] = min(st_min[j - 1][i], st_min[j - 1][i + (1 << (j - 1))]),
            st_max[j][i] = max(st_max[j - 1][i], st_max[j - 1][i + (1 << (j - 1))]);
}

int query_min(int l, int r) {
    int k = lg[r - l + 1];
    return min(st_min[k][l], st_min[k][r - (1 << k) + 1]);
}

int query_max(int l, int r) {
    int k = lg[r - l + 1];
    return max(st_max[k][l], st_max[k][r - (1 << k) + 1]);
}

struct Bit {
    int sum[maxn];
    void add(int pos, int val) {
        pos = max(1, pos);
        while(pos <= n) {
            sum[pos] += val;
            pos += lowbit(pos);
        }
    }
    int query(int pos) {
        int val = 0;
        while (pos) {
            val += sum[pos];
            pos -= lowbit(pos);
        }
        return val;
    }
} bit;

void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    build_st(a);

    vector<pii> key(n + 1);
    for (int i = 1; i <= n; ++i) {
        int firstPos = n + 1, secondPos = n + 1;

        int l = i + 1, r = n;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query_max(i + 1, mid) > a[i]) {
                firstPos = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        l = firstPos, r = n;
        secondPos = firstPos;
        while (l <= r) {
            int mid = l + r >> 1;
            if (query_min(firstPos, mid) >= query_min(i, firstPos - 1) &&
                query_min(firstPos, mid) > query_max(i, firstPos - 1)) {
                secondPos = mid;
                l = mid + 1;
            } else r = mid - 1;
        }

        key[i] = {firstPos, secondPos};
    }

    int q; cin >> q;
    vector Q(n + 1, vector<pii>());
    for (int i = 1; i <= q; ++i) {
        int l, r ;cin >> l >> r;
        Q[l].pb({r, i});
    }

    stack<pair<int, pii>> stk;
    vector<bool> ans(q + 1);
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() && a[stk.top().fir] < a[i]) {
            auto [_, j] = stk.top(); stk.pop();
            auto [l, r] = j;
            bit.add(l, -1);
            bit.add(r + 1, 1);
        }
        if (key[i].fir != n + 1 && key[i].sec != n + 1) {
            stk.push({i, key[i]});
            bit.add(key[i].fir, 1);
            bit.add(key[i].sec + 1, -1);
        }
        for (auto [r, id] : Q[i])
            if (bit.query(r) > 0)
                ans[id] = 1;
    }
    for (int i = 1; i <= q; ++i)
        cout << (ans[i] ? "Yes\n" : "No\n");
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
