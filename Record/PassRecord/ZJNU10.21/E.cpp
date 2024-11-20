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

ll n;
double a;
ll mas[N];
ll ans[N];
struct ty
{
    ll a,b;
}E[N];
ll gt_lcm(__int128 a,__int128 b)
{
    // return 1;
    return a*b/__gcd(a,b);
}
void check()
{
    ll s=0;
    for(int i=1;i<=n;++i) s+=ans[i]*ans[i];
        double det=sqrt(s*1.0);
    for(int i=1;i<=n;++i)
    {
        cout<<(double)(ans[i]*1.0)/det<<endl;
    }
}
ll dk=10000;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a;
        mas[i]=a*dk;
    }
    for(int i=1;i<=n;++i)
    {
        ll Gcd=__gcd(mas[i],dk);
        E[i].a=mas[i]/Gcd;
        E[i].b=dk/Gcd;
    }
    // for(int i=1;i<=n;++i)
    // {
    //     cout<<E[i].a<<' '<<E[i].b<<endl;
    // }
    ll Lcm=gt_lcm(E[1].b,E[2].b);
    for(int i=3;i<=n;++i) Lcm=gt_lcm(Lcm,E[i].b);
    ll Gcd=0;
    for(int i=1;i<=n;++i)
    {
        E[i].a*=Lcm/E[i].b;
        Gcd=__gcd(Gcd,E[i].a);
    }
    for(int i=1;i<=n;++i)
    {
        E[i].a/=Gcd;
        ans[i]=E[i].a;
        cout<<E[i].a<<endl;
    }
    // check();
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // check();
    return 0;
}
