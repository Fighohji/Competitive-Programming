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
#define endl '\n'

void solve() 
{
    int n; cin >> n;
    vector<ll>a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = n;
    while(l <= n && a[l] == 1) l++;
    if(l > n)
    {
        cout << 1 << ' ' << 1 << '\n';
        return ;
    }
    while(r >= l && a[r] == 1) r--;
    double ans = 1.0;
    int f = 1;
    for(int i = l; i <= r; ++i)
    {
        if(ans  >= 4e14 / (1.0 * a[i]))
        {
            f = 0;
            break;
        }
        ans *= a[i];
    }
    if(!f)
    {
        cout << l << ' ' << r << '\n';
        return ;
    }
    vector<int>pos;
    for(int i = l; i <= r; ++i) if(a[i] != 1) pos.push_back(i);
    vector<ll>pre(n + 1);
    for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
    int m = pos.size();
    ll Ansl = 1, Ansr = 1, Ans = 0;
    for(int i = 0; i < m; ++i)
    {
        ll r = 1;
        for(int j = i; j < m; ++j)
        {
            r *= a[pos[j]];
            if(Ans < r + pre[pos[i] - 1] + pre[n] - pre[pos[j]])
            {
                Ans = r + pre[pos[i] - 1] + pre[n] - pre[pos[j]];
                Ansl = pos[i];
                Ansr = pos[j];
            }
            // Ans = max(Ans, r + pre[pos[i] - 1] + pre[n] - pre[pos[j]]);
        }
    }
    // cout << "* " << l << ' ' << r << '\n';
    // cout << Ans << '\n';
    cout << Ansl << ' ' << Ansr << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
