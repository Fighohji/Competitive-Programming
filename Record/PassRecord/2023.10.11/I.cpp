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
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


bool check(db r, vector <array<int, 3>> &p) {
    int n = SZ(p);
    vector<pair<db, db>> seg;
    vector<db> tmp;
    for (int i = 0; i < n; ++i) {
        db dis = p[i][0] * p[i][0] + p[i][1] * p[i][1];
        if (dis > r * r) continue;;
        db half = sqrt(r * r - dis);
        seg.pb({p[i][2] - half, p[i][2] + half});
        tmp.pb(p[i][2] - half);
        tmp.pb(p[i][2] + half);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    vector<int> pre(SZ(tmp) + 10);
    for (int i = 0; i < SZ(seg); ++i) {
        // cout << lower_bound(all(tmp), seg[i].fir) - tmp.begin() << ' ' << lower_bound(all(tmp), seg[i].sec) - tmp.begin() << '\n';
        pre[lower_bound(all(tmp), seg[i].fir) - tmp.begin()]++;
        pre[lower_bound(all(tmp), seg[i].sec) - tmp.begin() + 1]--;
    }
    for (int i = 0; i < SZ(tmp) + 10; ++i) {
        if (i) pre[i] += pre[i - 1];
        if (pre[i] >= n / 2) return 1;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    vector <array<int, 3>> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    db ans = 40000;
    for (int i = 0; i < 3; ++i) {
        db l = 0, r = 40000;
        while (r - l > eps) {
            db mid = (l + r) / 2;
            // cout << mid << '\n';
            if (check(mid, p)) r = mid;
            else l = mid;
        }
        ans = min(ans, l);
        for (int j = 0; j < n; ++j) {
            swap(p[j][i], p[j][2]);
        }
    }
    cout << ans << '\n';
}
/*
5 11
1
1
3
3
1 1 0 2
2 1
2 2
3 3
2 4
3 1
1 3 1 3
2 3
2 4
3 1
2 1
*/

signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
