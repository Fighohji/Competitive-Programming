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
constexpr int mod = 1e9 + 7; /*  */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct Po {
    int x, y, r;
    int id;
    bool operator<(const Po &t) const {
        return sqrt(x * x + y * y) - r < (sqrt(t.x * t.x + t.y * t.y) - t.r);
    }
};

void solve() {
    int n; cin >> n;
    vector<pii> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i].fir;
        w[i].sec = i + 1;
    }
    int k; cin >> k;
    vector<Po> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].r;
        p[i].id = i + 1;
    }
    sort(all(w), [&](pii x, pii y) {
        return x.fir < y.fir;
    });
    sort(all(p));

    vector<pii> Ans;
    int j = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (sqrt(1000000.0 / w[i].fir) < sqrt(p[j].x * p[j].x + p[j].y * p[j].y) - p[j].r) {
            continue;
        }
        if (j < k) {
            Ans.pb({w[i].sec, p[j].id});
            j++;
        }
    }
    cout << SZ(Ans) << '\n';
    for (auto [x, y] : Ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
