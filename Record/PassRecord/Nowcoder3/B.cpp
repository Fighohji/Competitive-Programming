#include <map>
#include <pthread.h>
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

#define N 610
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
bool BEGIN;
ll mod,n;
ll C[N][N];
ll T[N][N];
ll p[N];
void init()
{
    p[0]=1;
    for(ll i=1;i<=600;++i) p[i]=p[i-1]*i%mod;

    for(int i=0;i<=600;++i) C[i][0]=1;
        C[1][1]=1;
    for(int i=1;i<=600;++i)
    {
        for(int j=1;j<=i;++j)
        {
            if(i==1&&j==1) continue;
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    T[0][0]=1;
    for(int i=1;i<=600;++i)
    {
        for(int j=1;j<=600;++j)
        {
            T[i][j]=(T[i-1][j-1]+T[i-1][j]*j%mod)%mod;
        }
    }
}
ll Cb(ll i,ll j)
{
    if(i<0||j<0) return 0;
    if(i<j) return 0;
    // cerr<<i<<" "<<j<<endl;
    // cout<<i<<" "<<j<<endl;
    return C[i][j];
}


void solve(int cas) {
    cin>>n>>mod;
    init();
    ll sum=0;
    for(int i=0;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            for(int k=0;k<=n;++k)
            {
                   sum=(sum+C[n][i]%mod*C[n][k]%mod*p[2*n-i-k]%mod * T[i][j]%mod*(2*T[k][j]%mod+T[k][j-1]+T[k][j+1])%mod)%mod;
            }
        }
    }
    cout<<((sum)%mod+mod)%mod<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
