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

vector<int>G[maxn];
int cnt[3][maxn];
int cnt2[310][110][3];
int a[110];
void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i)cnt[0][i] = 0;
    for(int i = 1; i <= n; ++i)cnt[1][i] = 0;
    for(int i = 1; i <= n; ++i)cnt[2][i] = 0;
    for(int i = 0; i <= 300; ++i)
    {
        for(int j = 0; j <= m; ++j)
        {
            for(int k = 0; k < 3; ++k)
            {
                cnt2[i][j][k] = 0;
            }
        }
    }
    for(int i = 1; i <= m; ++i)
    {
        G[i].clear();
    }
    for(int i = 1; i <= k; ++i)
    {
        int x, y; cin >> x >> y;
        G[y].emplace_back(x);
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cin >> a[j];
            cnt[a[j]][j]++;
        }
        for(int j = 1; j <= m; ++j)
        {
            if(G[j].empty()) continue;
            ll r = 0;
            for(auto pre:G[j])
            {
                r = r * 3 + a[pre];
            }
            cnt2[r][j][a[j]]++;
        }
    }
    for(int i = 1; i < m; ++i) cin >> a[i];
    double ans[3];
    for(int p = 0; p < 3; ++p)
    {
        a[m] = p;
        ans[p] = 1;
        queue<int>q;
        q.push(m);
        while(!q.empty())
        {
            int x = q.front();q.pop();
            if(!G[x].empty())
            {
                ll r = 0;
                for(auto pre:G[x])
                {
                    r = r * 3 + a[pre];
                }
                if(cnt2[r][x][0] + cnt2[r][x][1] + cnt2[r][x][2] == 0)
                {
                    ans[p] = 0;
                    // cout << "ppp is " << p << ' ' << r << ' ' << x << ' ' << 0 << '\n';
                }
                else
                {
                    ans[p] *= 1.0 * cnt2[r][x][a[x]] / (cnt2[r][x][0] + cnt2[r][x][1] + cnt2[r][x][2]);
                    // cout << "p is " << p << ' ' << x << ' ' << 1.0 * cnt2[r][x][a[x]] / (cnt2[r][x][0] + cnt2[r][x][1] + cnt2[r][x][2]) << '\n';
                }

            }
            else
            {
                ans[p] *= 1.0 * cnt[a[x]][x] / n;
                // cout << "pp is " << p << ' ' << x << ' ' << 1.0 * cnt[a[x]][x] / n << '\n';
            }
            for(auto y:G[x])
            {
                q.push(y);
            }
        }
    }
    int resp = 0;
    if(ans[resp] < ans[1]) resp = 1;
    if(ans[resp] < ans[2]) resp = 2;
    // cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    cout << resp << '\n';
}

bool END;
signed main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
