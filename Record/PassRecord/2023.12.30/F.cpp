
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

int a[2010];
int ans[2010];
int dp[2010][2010];
// int vis[2010][2010];

// map<pll,ll> mp;
ll cnt=0;
int query(int l, int r)
{
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    cout << "? " << l << ' ' << r << endl;
    cnt++;
    assert(cnt<=40000);
    int ans; cin >> ans;
    dp[l][r] = ans;
    // vis[l][r]=1;
    return ans;
}
bool check(int x, int y)// x < y && ans[x] > ans[y];
{
    if(x < y)
    {
        int c1 = query(x, y);
        int c2 = query(x + 1, y);
        int c3 = query(x, y - 1);
        int c4 = query(x + 1, y - 1);
        return c1 ^ c2 ^ c3 ^ c4;
    }
    else
    {
        swap(x, y);
        int c1 = query(x, y);
        int c2 = query(x + 1, y);
        int c3 = query(x, y - 1);
        int c4 = query(x + 1, y - 1);
        return c1 ^ c2 ^ c3 ^ c4 ^ 1;
    }
}
ll cal()
{
    ll ans=0;
    for(int i=2;i<=2000;++i)
    {
        ans+=2*(ll)log2(i-1);
    }
    return ans;
}
void solve() {
    // memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    a[1] = 1;
    // ans[1]=1;
    for(int i = 1; i <= n; ++i) dp[i][i] = 0;
    for(int i = 2; i <= n; ++i)
    {
        int l = 1, r = i - 1;
        int p = i;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(a[mid], i))
            {
                p = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        // cerr << "pos i " << p << '\n';
        // int p=r+1;
        for(int j = i; j > p; --j)
        {
            a[j] = a[j - 1];
            // ans[a[j]]=j;
        }
        a[p] = i;
        // ans[a[p]]=p;
        for(int j = 1; j <= i; ++j) ans[a[j]] = j;
        int pre = 0;
        for(int j = i - 1; j > 0; --j)
        {
            pre ^= (ans[j] > ans[i]);
            dp[j][i] = dp[j][i - 1] ^ pre;
            // vis[j][i]=1;
        }
    }
    cout<<"! ";
    // for(int i = 1; i <= n; ++i) ans[a[i]] = i;
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << endl;

    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=i+1;j<=n;++j)
    //     {
    //         cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
    //     }
    // }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
