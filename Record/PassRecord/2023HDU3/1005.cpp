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
constexpr int mod = 1e9 + 7; /*998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int a[3010],b[3010],cnt[3010];
ll dp[3010][3010];
ll pre[3010][3010];
void solve(int cas) {
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    b[n+1]=-1;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int tot=unique(a+1,a+n+1)-a-1;
    for(int i=1,j=1;i<=n&&j<=tot;++j)
    {
        int r=i;
        while(a[j]==b[r])++r;
        cnt[j]=r-1;
        i=r;
    }
    cout<<tot<<'\n';

    for(int k=0;k<=n;++k)for(int i=0;i<=n;++i)dp[k][i]=pre[k][i]=0;

    for(int i=1;i<=tot;++i)pre[1][i]=i;
    for(int k=2;k<=n;++k)
    {
        ll sum=0;
        for(int i=1;i<=tot;++i)
        {

            if(cnt[i]<k)continue;
            dp[k][i]=pre[k-1][i];
            sum+=dp[k][i];
            sum%=mod;
            // cout<<"*"<<k<<' '<<i<<' '<<dp[i]<<'\n';
        }
        // pre[0]=0;
        for(int i=1;i<=n;++i)
        {
            pre[k][i]=(pre[k][i-1]+dp[k][i]) % mod;
        }
        cout<<sum<<'\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
