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
// constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

ll n,m,k;
string s;
ll dir[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
char mp[20][20];
ll fl=0,Dir;
bool inmap(ll x,ll y)
{
    return x>=1&&y>=1&&x<=n&&y<=m;
}
bool vis[12][12][102][10][100];
void dfs(ll x,ll y,ll idx,ll predir,ll num)
{
    if(vis[x][y][idx][predir][num]) return;
    vis[x][y][idx][predir][num]=1;
    if(fl) return;
    if(idx==s.size()-1)
    {
        if(num==k) fl=1;
        return;
    }
    //坐标，字符串位置，方向，转弯次数
    for(int i=0;i<8;++i)
    {
        ll xx=x+dir[i][0];
        ll yy=y+dir[i][1];
        if(!inmap(xx,yy)) continue;
        if(mp[xx][yy]!=s[idx+1]) continue;
        Dir=i;
        if(Dir!=predir&&predir!=8) dfs(xx,yy,idx+1,Dir,num+1);
        else dfs(xx,yy,idx+1,Dir,num);
    }
}
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>mp[i][j];
        }
    }
    cin>>k;
    cin>>s;
    for(int i=1;i<=n && !fl;++i)
    {
        for(int j=1;j<=m&&!fl;++j)
        {
            if(mp[i][j]==s[0])
            {
                dfs(i,j,0,8,0);
            }
        }
    }
    cout<<(fl?"YES":"NO")<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
