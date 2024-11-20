#include <map>
#include <numeric>
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



bool BEGIN;


int n, m;
ll mp[105][105];
struct node {
    int u, v;
    ll x;
    bool operator<(const node &t) const {
        return x > t.x;
    }
};
void solve(int cas) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mp[i][j] = LINF;
    for (int i  = 1; i <= m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        mp[u][v] = min((ll)t, mp[u][v]), mp[v][u] = mp[u][v];
    }
    ll t = 0, k = 0;
    vector<bool> vec(n + 1, 0);
    int cnt = n - 1;
    for (int i = 1; i <= n - 1; ++i) vec[i] = 1;

    vector<pair<vector<bool>, ll>> str;
    queue<int> q;
    q.push(n);
    while (vec[1]) {
        ll mn = LINF;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (vec[i] ^ vec[j])
                    mn = min(mn, mp[i][j]);
        if (mn == LINF) {
            cout << "inf\n";
            return ;
        }
        t += mn; k++;
        vector<int> tmp;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (!vec[j] && vec[i] && mn == mp[i][j])
                    tmp.pb(i);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (vec[i] ^ vec[j] && mp[i][j] != LINF)
                    mp[i][j] = mp[j][i] = mp[i][j] -= mn;
        str.pb({vec, mn});
        for (auto i : tmp)
            vec[i] = 0;
    }
    cout << t << ' ' << k << '\n';
    for (int i = 0; i < SZ(str); ++i) {
        for (int j = 1; j < SZ(str[i].fir); ++j)
            cout << str[i].fir[j];
        cout << ' ';
        cout << str[i].sec << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
