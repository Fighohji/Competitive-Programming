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
constexpr int maxn = 2e3 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 998244353 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

vector<int> G[N];
int n;
ll dp[1010][1010];
ll ret[1010];
ll sz[1010];
void dfs(int x)
{
    sz[x] = 1;
    dp[x][0] = 1;
    dp[x][1] = 1;
    for(int y : G[x])
    {
        dfs(y);
        for(int i = 0; i <= sz[x] + sz[y]; ++i) ret[i] = 0;
        for(int i = 1; i <= sz[x]; ++i)
        {
            for(int j = 0; j <= sz[y]; ++j)
            {
                ret[i + j] = (ret[i + j] + dp[x][i] * dp[y][j] % mod) % mod;
            }
        }
        sz[x] += sz[y];
        for(int i = 1; i <= sz[x]; ++i) dp[x][i] = ret[i];
    }

    // cout << "* " << x << '\n';
    // cout << sz[x] << '\n';
    // for(int i = 0; i <= sz[x]; ++i) cout << dp[x][i] << ' ';
    // cout << '\n';
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; ++i)
    {
        int p; cin >> p;
        G[p].push_back(i);
    }
    dfs(0);
    for(int i = 1; i <= n; ++i)
    {
        ll ans = 0;
        for(int j = 0; j < n; ++j)
        {
            ans = (ans + dp[j][i]) % mod;
        }
        cout << ans << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
