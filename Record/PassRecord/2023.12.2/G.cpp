
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
constexpr int mod = 1e9 + 7; /*  */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


ll n;
ll vis[N];
string s;
ll gt(char x)
{
    return (ll)(x-'0');
}
ll gt(string s)
{
    ll hour=gt(s[0])*10+gt(s[1]);
    ll mint=gt(s[3])*10+gt(s[4]);
    ll sec=gt(s[6])*10+gt(s[7]);
    // cout<<s<<' '<<hour<<' '<<mint<<' '<<sec<<endl;
    return sec+mint*60+hour*60*60;
}
void solve() {
    cin>>n;
    ll up=60*60*24;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        ll a1=gt(s);
        cin>>s;
        ll a2=gt(s);
        if(a1<=a2)
        {
            vis[a1]++;
            vis[a2]--;
        }
        else
        {
            vis[a1]++;
            vis[up]--;
            vis[0]++;
            vis[a2]--;
        }
    }
    for(int i=0;i<up;++i) vis[i]+=vis[i-1];
    ll ans=0;
    for(int i=0;i<up;++i)
    {
        if(vis[i]==0) ans++;
    }
    cout<<ans<<endl;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
