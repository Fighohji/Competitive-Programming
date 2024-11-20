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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, m, k;

vector<int> e[maxn];
void solve(int cas) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        e[u].eb(v); e[v].eb(u);
    }
    vector<int> tmp;
    for (int i = 1; i <= n; ++i) {
        tmp.eb(i);
    }
    int T = 1000;
    while (T--) {
        random_shuffle(all(tmp));
        int l = k + 1, r = SZ(tmp) - k - 1;
        // cerr << l << ' ' << r << '\n';
        int p = rand() % (r - l + 1) + l;
        vector<int> col(n + 1, 0);
        for (int i = 0; i < p; ++i)
            col[tmp[i]] = 1;
        bool f = 1;
        for (int i = 0; i < p; ++i) {
            int cnt = 0;
            for (auto v : e[tmp[i]]) {
                if (col[i] ^ col[v]) cnt++;
            }
            if (cnt < k + 1) {
                f = 0;
                break;
            }
        }
        if (!f) continue;
        for (int i = p; i < SZ(tmp); ++i) {
            int cnt = 0;
            for (auto v : e[tmp[i]]) {
                if (col[i] ^ col[v]) cnt++;
            }
            if (cnt < k + 1) {
                f = 0;
                break;
            }
        }
        if (!f) continue;
        cout << p << ' ';
        for (int i = 0; i < p; ++i) cout << tmp[i] << ' ';
        cout << '\n';
        cout << SZ(tmp) - p << ' ';
        for (int i = p; i < SZ(tmp); ++i) cout << tmp[i] << ' ';
        cout << '\n';
        break;
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(9);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
