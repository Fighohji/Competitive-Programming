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
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

double S[10][10];
double x[10];
int guass(int n, int m)//方程数，未知数个数 
{
    int c=0,r,maxr; 
    for(r=0;r<n&&c<m;r++,c++)
    {
        maxr=r;
        for(int i=r+1;i<n;i++)
        {
            if(abs(S[i][c])>abs(S[maxr][c]))
                maxr=i;
        }
        if(maxr!=r) swap(S[r], S[maxr]);
        if(fabs(S[r][c])<eps)
        {
            r--;
            continue;
        }
        for(int i=r+1;i<n;i++)
        {
            if(fabs(S[i][c])>eps)
            {
                double k=S[i][c]/S[r][c];
                for(int j=c;j<m+1;j++) S[i][j]-=S[r][j]*k;
                S[i][c]=0;
            }
        }
    } 
    for(int i=r;i<m;i++)
    {
        if(fabs(S[i][c])>eps) return -1;//无解
    }    
    if(r<m) return m-r;//返回自由元个数
    for(int i=m-1;i>=0;i--)
    {
        for(int j=i+1;j<m;j++) S[i][m]-=S[i][j]*x[j];
        x[i]=S[i][m]/S[i][i];
    }
    return 0;//有唯一解
}
void solve(int cas) {
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            cin>>S[i][j];
        }
    }
    for(int i=0;i<3;++i)cin>>S[i][3];
    int tmp=guass(3,3);
    if(tmp==-1)
    {
        cout<<"NO\n";
    }
    else if(tmp==0)
    {
        bool f=1;
        for(int i=0;i<3;++i)if(x[i]<-eps)f=0;
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }
    else if(tmp==2)
    {
        cout<<"YES\n";
    }
    else
    {
        if(fabs(S[0][0])<eps)
        {
            x[1]=S[1][3]/S[0][1];
            x[2]=S[2][3]/S[1][2];
            if(x[1]>-eps&&x[2]>-eps)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
        else
        {
            x[0]=S[0][4]/S[0][1];
            if(fabs(S[1][1])<eps)
            {
                x[1]=S[2][4]/S[1][2];
            }
            else
            {
                x[1]=S[1][4]/S[1][1];
            }
            if(x[0]>-eps&&x[1]>-eps)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
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
