#include <cinttypes>
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
constexpr int maxn = 5010;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
int vis[N][N];
int n;
int pos,posr;
ll p[N];
ll num=0;
int mas[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>mas[i];
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) vis[i][j]=0;
    for(int i=1;i<=n;++i)
    {
        num=0;
        for(int j=0;j<=n-i+2;++j) p[j]=n+1;
        p[0]=i;
        for(int j=i;j<=n;++j)
        {
            if(mas[j]<mas[i])
            {
                p[++num]=j;
            }
        }
        num=0;
        for(int j=i;j>=1;--j)
        {
            if(mas[j]>mas[i]) num++;
            vis[j][p[num]]++;
            vis[j][p[num+1]]--;
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            vis[i][j]+=vis[i][j-1];
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<vis[i][j]<<' ';
        }
        cout<<endl;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(vis[i][j]==0) cnt++;
        }
    }
    cout<<cnt<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
