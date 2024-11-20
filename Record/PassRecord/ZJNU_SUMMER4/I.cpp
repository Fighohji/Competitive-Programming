#include <limits>
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
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

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
constexpr int maxn = 3e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
ll s,n;
const ll N=1e5+10;
struct ty
{
    ll a,h;
}mas[N];
bool cmp(ty a,ty b)
{
    return a.h<b.h;
}
ll dp[N][250];
void solve(int cas) 
{
    cin>>s>>n;
    for(int i=1;i<=s;++i) cin>>mas[i].a>>mas[i].h;

    sort(mas+1,mas+1+s,cmp);

    memset(dp,-0x3f,sizeof dp);
    dp[0][0]=0;
    // for(int i=0;i<=n;++i) dp[i][0]=0;
    for(int i=1;i<=s;++i)
    {
        for(int j=1;j<=min((ll)i,n);++j)
        {
            if(j==1) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+mas[i].a+mas[i].h);
            else if(j==n) dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+mas[i].a-mas[i].h);
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+mas[i].a);
        }
    }
    cout<<dp[s][n]<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
