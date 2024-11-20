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
#define eps 0
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

// #define endl '\n'

ll n,num;
ll pos;
ll gt_num;
bool check(ll x)
{
    cout<<x<<' '<<x<<endl;
    cin>>gt_num;
    if(gt_num==n) exit(0);
    if(gt_num<num)
    {
        //之前是亮的
        cout<<x<<' '<<x<<endl;
        cin>>gt_num;
        return 1;
    }
    cout<<x<<' '<<x<<endl;
    cin>>gt_num;
    return 0;
}
vector<int> vt[20];
ll fl=0,res,Fl;
bool update(ll l,ll r)
{
    cout<<l<<' '<<r<<endl;
    cin>>gt_num;
    if(gt_num==n) exit(0);
    fl=0;
    if(gt_num>num) fl=1;//成功更新所有相关线段
    num=gt_num;
    return fl;
}
ll find_pos(ll x)
{
    return n-x+1;
}
ll find(ll x,ll y)
{
    for(int i=1;i<=30;++i)
    {
        if(((x>>(i-1))&1)!=((y>>(i-1))&1)) return i;
    }
    return 0;
}
ll a[N];
void dfs(ll x)
{
    for(int i=1;i<(1<<x);++i)
    {
        ll dd=find(a[i],a[i-1]);
        res=update(pos,find_pos(dd));
        if(res)
        {
            if(check(pos)==0) continue;
            Fl=1;
            return;
        }
    }
}
void solve()
{
    cin>>n>>num;
    int base = (1 << n) - 1;
    for(int i = 1; i < (1 << n); ++i)
    {
        a[i] = (i ^ (i >> 1)) & base;
    }
    for(int i=1;i<=n;++i)
    {
        if(check(i)) continue;
        for(int j=0;j<=10;++j) vt[j].clear();
        pos=i;
        Fl=0;
        dfs(n-i+1);
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
