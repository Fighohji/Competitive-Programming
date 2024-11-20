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


// #define int long long
ll dp[510][2010];
ll pre[510][2010];
ll n,p,m;
void solve() {
    dp[0][0]=1;
    cin>>n>>p>>m;
    ll sum,xor_sum;
    for(int k=1;k<=n-p;++k)
    {
        for(int num=1;num<=(n-p)/k;++num)
        {
            sum=num*k;
            if(num%2) xor_sum=k;
            else xor_sum=0;
            for(int i=0;i<=n-p-sum;++i)
            {
                for(int j=0;j<=(n)*2;++j)
                {
                    pre[i+sum][j^xor_sum]=(pre[i+sum][j^xor_sum]+dp[i][j])%m;
                }
            }
        }
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=(n)*2;++j)
            {
                dp[i][j]=pre[i][j];
                //pre[i][j]=0;
            }
        }
    }
    cout<<dp[n-p][p]<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
