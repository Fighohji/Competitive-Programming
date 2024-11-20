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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
ll n,a,sum=0;
ll mas[N];
bool judge(ll x)
{
    if(x==0||x==1) return 0;
    for(ll i=2;i*i<=x;++i)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
void solve(int cas) {
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>mas[i];
        sum+=mas[i];
    }
    if(n==2)
    {
        if(sum%2==0)
        {
            cout<<"Yes"<<endl;
            return;
        }
        if(sum==1)
        {
            cout<<"No"<<endl;
            return;
        }
        if(judge(sum-2))
        {
            cout<<"Yes"<<endl;
            return;
        }
        cout<<"No"<<endl;
        return;
    }
    if(n==3)
    {
        if(sum>5)
        {
            cout<<"Yes"<<endl;
            return;
        }
        cout<<"No"<<endl;
        return;
    }
    ll det=n;
    while(det>3)
    {
        sum-=2;
        det--;
    }
    if(det>5)
    {
        cout<<"Yes"<<endl;
        return;
    }
    cout<<"No"<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
