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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


// int n,cnt; char s[maxn]; int len[maxn];//注意两倍空间
int vis[20][20][20];
int sg[20][20][20];
// int v[110];
void dfs(int x,int y,int k,int n)
{
    vector<int>v(10,0);
    if(x-1>0&&(!vis[x-1][y][k]))
    {
        vis[x-1][y][k]=1;
        dfs(x-1,y,k,n);
        v[sg[x-1][y][k]]=1;
        vis[x-1][y][k]=0;
    }
    if(x+1<=n&&(!vis[x+1][y][k]))
    {
        vis[x+1][y][k]=1;
        dfs(x+1,y,k,n);
        v[sg[x+1][y][k]]=1;
        vis[x+1][y][k]=0;
    }

    if(y-1>0&& !vis[x][y-1][k])
    {
        vis[x][y-1][k]=1;
        dfs(x,y-1,k,n);
        v[sg[x][y-1][k]]=1;
        vis[x][y-1][k]=0;
    }
    if(y+1<=n&&!vis[x][y+1][k])
    {
        vis[x][y+1][k]=1;
        dfs(x,y+1,k,n);
        v[sg[x][y+1][k]]=1;
        vis[x][y+1][k]=0;
    }

    if(k-1>0&&!vis[x][y][k-1])
    {
        vis[x][y][k-1]=1;
        dfs(x,y,k-1,n);
        v[sg[x][y][k-1]]=1;
        vis[x][y][k-1]=0;
    }
    if(k+1<=n&&!vis[x][y][k+1])
    {
        vis[x][y][k+1]=1;
        dfs(x,y,k+1,n);
        v[sg[x][y][k+1]]=1;
        vis[x][y][k+1]=0;
    }

    for(int i=0;i<10;++i)
    {
        if(!v[i])
        {
            sg[x][y][k]=i;
            break;
        }
    }
}

void solve(int cas) {
    int n=2;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
            {
                memset(vis,0,sizeof(vis));
                dfs(i,j,k,n);
            }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
            {
                cout<<i<<' '<<j<<' '<<k<<' '<<sg[i][j][k]<<"\n";
            }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
