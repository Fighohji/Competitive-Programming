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
constexpr int maxn = 1e4 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, q;
int a[maxn];
int bit[maxn][31], cntbit[maxn][31];
int tot[maxn];
int idx[31];
int root[31][maxn], ls[31][maxn << 4], rs[31][maxn << 4], cnt[31][maxn << 4];
void update(int id, int rtu, int &rtv,int l, int r, int pos, int val) {
    rtv = ++idx[id];
    ls[id][rtv] = ls[id][rtu], rs[id][rtv] = rs[id][rtu];
    cnt[id][rtv] = cnt[id][rtu];
    if (l == r) {
        cnt[id][rtv]++;
        return ;
    }
    int mid = l + r >> 1;
    if (pos <= mid) update(id, ls[id][rtu], ls[id][rtv], l, mid, pos, val);
    else update(id, rs[id][rtu], rs[id][rtv], mid + 1, r, pos, val);
    cnt[id][rtv] = cnt[id][ls[id][rtv]] + cnt[id][rs[id][rtv]];
}
int query(int id, int rtu, int rtv, int l, int r, int kth) {
    if (l == r) return l;
    int mid = l + r >> 1;
    int res = cnt[id][rs[id][rtv]] - cnt[id][rs[id][rtv]];
    if (res >= kth) return query(id, rs[id][rtu], rs[id][rtv], mid + 1, r, kth);
    else return query(id, ls[id][rtu], ls[id][rtv], l, mid, kth - res);
}
void solve(int cas) {
    cin >> n >> q;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int tmp = a[i];
        while (tmp) {
            bit[i][++tot[i]] = tmp;
            tmp >>= 1;
            sum++;
        }
        cntbit[i][tot[i]]++;
    }
    for (int i = 1; i <= 30; ++i)
        for (int j = 1; j <= n; ++j)
            cntbit[j][i] += cntbit[j - 1][i];

    for (int j = 1; j <= n; ++j)
        for (int i = tot[j]; i >= 1; --i) {
            if (bit[j][i]) {
                int p = tot[j] - i + 1;
                update(p, root[p][j - 1], root[p][j], (1 << (p - 1)), (1 << p) - 1, bit[j][i], 1);
            }
        }
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        if (k >= sum) {
            cout << 0 << '\n';
            continue;
        }
        int pre = 0;
        int id = 30;
        for (; id >= 1; --id) {
            int res = pre + cntbit[r][id] - cntbit[l - 1][id];
            if (k < pre + res) break;
            k -= pre + res;
            pre += cntbit[r][id] - cntbit[l - 1][id];
        }
        k++;
        cout << query(id, root[id][l - 1], root[id][r], (1 << (id - 1)), (1 << id) - 1, k) << '\n';
    }
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
