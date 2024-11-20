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
#include <type_traits>
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;



int n,m;
ll cnt[510][510];
ll a[510][510];
ll dis[510][510];
void solve(int cas) {
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            if(i==j)dis[i][j]=a[i][i]=0,cnt[i][i]=1;
            else
            {
                dis[i][j]=LINF;
                cnt[i][j]=0;
                a[i][j]=LINF;
            }
        }

    for(int i=1;i<=m;++i)
    {
        int x,y;
        ll w;
        cin>>x>>y>>w;
        dis[x][y]=w;
        cnt[x][y]=1;
        a[x][y]=w;
    }

    ll ansm=LINF,ansk=0;
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<k;++i)
        {
            for(int j=1;j<k;++j)
            {
                if(a[j][k]==LINF||a[k][i]==LINF||dis[i][j]==LINF)continue;
                ll tmp=dis[i][j]+a[j][k]+a[k][i];
                if(tmp<LINF&&tmp<ansm)
                {
                    ansm=tmp;
                    ansk=cnt[i][j];
                }
                else if(tmp==ansm)
                {
                    ansk=(ansk+cnt[i][j])%mod;
                }
            }
        }

        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(i==j||i==k||j==k)continue;
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    cnt[i][j]=cnt[i][k]*cnt[k][j]%mod;
                }
                else if(dis[i][j]==dis[i][k]+dis[k][j])
                {
                    cnt[i][j]=(cnt[i][j]+cnt[i][k]*cnt[k][j]%mod)%mod;
                }
            }
        }
    }
    if(ansm==LINF)
    {
        cout<<"-1 -1\n";
        return;
    }
    else {
        cout<<ansm<<" "<<ansk<<'\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    exit(0);
}
