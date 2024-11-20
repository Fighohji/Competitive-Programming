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


ll dp[N][20];
string s, t;
vector<int> a;
int n, A;
ll dfs(int pos, int r, int cnt, int lead, int limit)
{
    // if(cnt > A) return 0;
    if(!limit && dp[pos][cnt] != -1) return dp[pos][cnt];
    if(pos == n) return cnt == A;
    int up = limit ? a[pos] : 9;
    ll res = 0;
    for(int i = lead; i <= up; ++i)
    {
        if((r >> i) & 1)
        {
            res += dfs(pos + 1, r, cnt, 0, limit && i == up);
            res %= mod;
        }
        else
        {
            res += dfs(pos + 1, r | (1 << i), cnt + 1, 0, limit && i == up);
            res %= mod;
        }
    }
    // cout << lead << ' ' << up << '\n';
    // cout << pos << ' ' << cnt << ' ' << res << ' ' << limit << '\n';
    if(!limit) dp[pos][cnt] = res;
    return res;
}
int check(string &s)
{
    int r = 0;
    for(int i = 0; i < n; ++i)
    {
        r |= (1 << (s[i] - '0'));
    }
    int cnt = 0;
    for(int i = 0; i < 10; ++i)
    {
        if(r & (1 << i)) cnt++;
    }
    return cnt == A;
}
ll work(string &s)
{
    a.resize(n);
    for(int i = 0; i < n; ++i)
    {
        a[i] = s[i] - '0';
    }
    return dfs(0, 0, 0, 1, 1);
}
void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> s >> t;
    cin >> A;
    // cout << work(s) << '\n' << work(s) << '\n' << check(s) << '\n' ;
    ll res = work(t) - work(s) + check(s);
    res = (res % mod + mod) % mod;
    cout << res;

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
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
