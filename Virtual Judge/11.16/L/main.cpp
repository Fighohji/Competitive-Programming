#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

#define int long long

__int128 check(ll x)
{
    ll ans = x;
    for(__int128 i = 1; i; i *= 100)
    {
        ans = ans - (x / (4 * i)) + (x / (100 * i));
        if(x < 100 * i) break;
    }
    // cout << ans << '\n';
    return ans - 1533;
}
/*
5
2
3
4
114514
998244353
*/
void solve() {
    ll k; cin >> k;
    ll l = 2024, r = 4e18;
    ll ans = 0;
    // check(2024);
    while(l <= r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid) >= k)
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

