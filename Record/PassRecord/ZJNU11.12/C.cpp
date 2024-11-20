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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

string s;
int n;
ll up = 1ll << 47;
ll check(__int128 x)
{
    __int128 r = x;
    for(int i = n - 1; i >= 0; --i)
    {
        if(s[i] == 'O') r = (r - 1) / 3;
        else r = r * 2;
        ll p = r;
        // cout << p << ' ';
    }
    // cout << '\n';
    if(r > up) return -1;
    ll res = r;
    // cout << res << '\n';
    for(int i = 0; i < n; ++i)
    {
        if(s[i] == 'O')
        {
            if(r % 2 == 0) return -1;
            r = r * 3 + 1;
        }
        else
        {
            if(r % 2 != 0) return -1;
            r = r / 2;
        }
        if(i != n - 1)
        {
            for(int j = 0; j < 70; ++j)
            {
                if(((__int128)1 << j) == r) return -1;
            }
        }

    }
    if(r != x) return -1;
    return res;
}
void solve()
{
    cin >> s;
    n = s.size();
    ll ans = LINF;
    for(int i = 0; i < 70; ++i)
    {
        ll tmp = check(((__int128)1 << i));
        if(tmp != -1) ans = min(tmp, ans);
    }
    if(ans != LINF) cout << ans << '\n';
    else cout << "INVALID\n";

}

signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
