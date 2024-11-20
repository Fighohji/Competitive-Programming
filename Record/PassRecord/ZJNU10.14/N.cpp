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
constexpr int maxn = 1e3 + 10;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

#define endl '\n'
ll n,k;
char ans[N][N];
bool Solve1()
{
    vector<pair<ll,ll>> vt1,vt3,vt4;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((i+j)%2) continue;
            if((i==1||i==n)&&(j==1||j==n)) vt1.push_back(make_pair(i,j));
            else if(i==1||i==n||j==1||j==n) vt3.push_back(make_pair(i,j));
            else vt4.push_back(make_pair(i,j));
        }
    }
    ll num1=vt1.size(),num3=vt3.size(),num4=vt4.size();
    for(int i=0;i<=num1;++i)
    {
        for(int j=0;j<=num3;++j)
        {
            ll det=k-i*2-j*3;
            if(det<0) continue;
            if(det%4) continue;
            if(det/4>num4) continue;
            for(int a=0;a<=i-1;++a) ans[vt1[a].first][vt1[a].second]='R';
            for(int a=0;a<=j-1;++a) ans[vt3[a].first][vt3[a].second]='R';
            for(int a=0;a<=det/4-1;++a) ans[vt4[a].first][vt4[a].second]='R';
                return 1;
        }
    }
    return 0;
}

bool Solve2()
{
    vector<pair<ll,ll>> vt1,vt3,vt4;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if((i+j)%2==0) continue;
            if((i==1||i==n)&&(j==1||j==n)) vt1.push_back(make_pair(i,j));
            else if(i==1||i==n||j==1||j==n) vt3.push_back(make_pair(i,j));
            else vt4.push_back(make_pair(i,j));
        }
    }
    ll num1=vt1.size(),num3=vt3.size(),num4=vt4.size();
    // cout<<num1<<" "<<num3<<' '<<num4<<endl;
    for(int i=0;i<=num1;++i)
    {
        for(int j=0;j<=num3;++j)
        {
            ll det=k-i*2-j*3;
            if(det<0) continue;
            if(det%4) continue;
            if(det/4>num4) continue;
            for(int a=0;a<=i-1;++a) ans[vt1[a].first][vt1[a].second]='R';
            for(int a=0;a<=j-1;++a) ans[vt3[a].first][vt3[a].second]='R';
            for(int a=0;a<=det/4-1;++a) ans[vt4[a].first][vt4[a].second]='R';
                return 1;
        }
    }
    return 0;
}


void print()
{
    cout<<"Possible"<<endl;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ans[i][j]='B';
        }
    }
    if(n==1)
    {
        if(k==0)
        {
                print();
                return;
        }
    cout<<"Impossible"<<endl;
    return;
    }
    if(Solve1())
    {
        print();
        return;
    }
    // cerr<<"1"<<endl;
    if(Solve2())
    {
        print();
        return;
    }
    cout<<"Impossible"<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
