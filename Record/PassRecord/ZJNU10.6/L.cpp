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
#define endl '\n'
ll a,b;
ll sum=0;
void cg(ll a,ll b,ll fl)
{
    // cout<<a<<' '<<b<<' '<<fl<<' '<<sum<<endl;
    if(a==0) return;
    if(fl==1)
    {
        sum++;
        sum%=mod;
        cg(b,a,0);
        return;
    }
    //0 <0 1 >0
    if(b==1)
    {
        sum+=a;
        sum%=mod;
        return;
    }
    ll det=a/b+(a%b!=0);
    sum=(sum+det)%mod;
    cg(b-a%b,b,1);
}
void solve()
{
    sum=0;
    cin>>a>>b;
    if(a==0)
    {
        cout<<0<<endl;
        return;
    }
    ll F=1;
    if(a<0) a = -a, F=0;
    ll Gcd=__gcd(a,b);
    a/=Gcd,b/=Gcd;

    cg(abs(a),b,F);
    cout<<sum<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
