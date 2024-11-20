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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
ll n,k;
ll vis[50];
ll b[N];
ll num[N];
#define endl '\n'
ll cal(ll x)
{
    ll cnt=0;
    while(x)
    {
        x/=2;
        cnt++;
    }
    return cnt-1;
}
void solve(int cas) {
    cin>>n>>k;
    ll pre=0;
    for(int i=0;i<=30;++i) num[i]=0,vis[i]=0;
    for(int i=1;i<n;++i) cin>>b[i];
    for(int i=1;i<n;++i) {
        if(b[i]==0) continue;
        if((pre>>cal(b[i]))&1)
        {
            cout<<-1<<endl;
            return;
        }
        pre^=b[i];
        vis[cal(b[i])]=1;
    }

    ll cnt=0;
    for(int i=0;i<30;++i) {
        if(vis[i]) continue;
        num[i]=cnt;
        cnt++;
    }

    ll ans=0; k--;
    if(k) {
        for(int i=0;i<30;++i) {
            if(vis[i]) continue;
            if((1<<num[i])>k) continue;
            if(k&(1<<num[i])) ans+=(1<<i),k-=(1<<num[i]);
        }
    }

    if(k>0)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<" ";
    for(int i=1;i<n;++i)
    {
        ans^=b[i];
        cout<<ans<<' ';
    }
    cout<<'\n';
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
