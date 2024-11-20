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
ll n,k;
ll judge(ll n)
{
    ll sum=0,now=1;
    while(n%2==0)
    {
        sum+=now;
        now*=2;
        n/=2;
    }
    return sum>=k;
}
int ans[1010][1010];
void solve()
{
    cin>>n>>k;
    // cout<<n<<' '<<k<<endl;
    if(!judge(n))
    {
        cout<<"Impossible"<<endl;
        return;
    }
    // k--;
    int step = 2;
    for(int i = 1; i <= k; ++i)
    {
        if(i == step) step *= 2;
        if(i == 1)
        {
            for(int j = 0; j < n; ++j) ans[i][j] = j ^ 1;
            continue;
        }
        else
        {
            ans[i][0] = i;
            ans[i][i] = 0;
            for(int j = 1; j < step / 2; ++j)
            {
                int to = ans[j][i];
                ans[i][j] = to;
                ans[i][to] = j;
            }
            for(int j = step; j < n; j += step)
            {
                for(int k = 0; k < step; ++k)
                {
                    ans[i][j + k] = ans[i][k] + j;
                }
            }
        }
    }

    for(int i = 1; i <= k; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cout << ans[i][j] + 1 << " \n"[j + 1 == n];
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
