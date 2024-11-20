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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


void solve()
{
    int n, m; cin >> n >> m;
    vector<vector<int>>a(n + 1);
    int sum = 0;
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int p; cin >> p;
        a[i].resize(p);
        sum += p;
        for(int j = 0; j < p; ++j)
        {
            cin >> a[i][j];
        }
        ans += a[i][p - 1];
    }
    if(sum <= m)
    {
        cout << ans << '\n';
        return ;
    }
    vector<vector<ll>> pre(n + 1, vector<ll>(m + 1, -LINF));
    vector<vector<ll>> suf(n + 2, vector<ll>(m + 1, -LINF));
    pre[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        int w = a[i].size();
        int v = a[i][w - 1];
        for(int j = 0; j <= m; ++j) pre[i][j] = pre[i - 1][j];
        for(int j = 0; j + w <= m; ++j)
        {
            if(pre[i - 1][j] != -LINF)
                pre[i][j + w] = max(pre[i - 1][j] + v, pre[i][j + w]);
            // cout << i << ' ' << j + w << ' ' << pre[i][j + w] << '\n';
        }
    }
    suf[n + 1][0] = 0;
    for(int i = n; i; --i)
    {
        int w = a[i].size();
        int v = a[i][w - 1];
        for(int j = 0; j <= m; ++j) suf[i][j] = suf[i + 1][j];

        for(int j = 0; j + w <= m; ++j)
        {
            if(suf[i + 1][j] != -LINF)
                suf[i][j + w] = max(suf[i][j + w], suf[i + 1][j] + v);
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            for(int p = 0; p < a[i].size(); ++p)
            {
                int v = m - j - p - 1;
                if(v < 0) continue;
                res = max(res, pre[i - 1][j] + a[i][p] + suf[i + 1][v]);
            }
        }
    }
    cout << res << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
