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
constexpr int maxn = 100;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
vector<ll> ans;
ll n;
ll mp[N][N];
void dfs(ll x,ll y)
{
    if(x>n) return;
    ans.push_back(mp[x][y]);
    if(x%2)
    {
        if(y<n) dfs(x,y+1);
        else dfs(x+1,n);
        return;
    }
    if(y!=1) dfs(x,y-1);
    else dfs(x+1,1);
}
void solve()
{
    ans.clear();
   cin>>n;
   for(int i=1;i<=n;++i)
   {
        for(int j=1;j<=n;++j) cin>>mp[i][j];
   }
    dfs(1,1);
    ll n1=0,n2=0;
    for(int i=1;i<ans.size();++i)
    {
        if(ans[i]>ans[i-1]) n1++;
        if(ans[i]<ans[i-1]) n2++;
    }
    if(n1>n2) reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();++i)
    {
        cout<<ans[i];
        if(i<ans.size()-1) cout<<" ";
    }
    cout<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
