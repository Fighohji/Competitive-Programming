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
#define db long double
#define il inline
#define fir first
#define sec second
#define eps (1e-12)
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
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

vector<tuple<int,int,int>> v;
bool vis[1010];
int cnt[1010];
int id[1010];
bool cmp(int a,int b)
{
    return cnt[a]>cnt[b];
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            for(int k = j + 1; k <= n; ++k)
            {
                // cout << i << ' ' << j << ' ' << k << '\n';
                if((a[i] ^ a[j] ^ a[k]) == 0)
                {
                    v.emplace_back(i, j, k);
                    cnt[i]++;cnt[j]++;cnt[k]++;
                }
            }
        }
    }
    // cout<<v.size()<<endl;
    for(int i=1;i<=n;++i) id[i]=i;
    sort(id+1,id+1+n,cmp);
    ll ans=1000;
    ll cn=0;
    for(int s=0;s<(1<<9);++s)
    {
        for(int i=1;i<=n;++i) vis[i]=0;
        for(int i=0;i<9;++i)
        {
            if((s>>i)&1) vis[id[i+1]]=1;
        }
        ll fl=1;
        for(auto [a,b,c]:v)
        {
            // cout<<a<<' '<<b<<' '<<c<<endl;
            if(vis[a]||vis[b]||vis[c]) continue;
            fl=0;
            break;
        }
        if(fl==0) continue;
        cn=__builtin_popcount(s);
        // cout<<cn<<endl;
        ans=min(ans,cn);
    }
    cout<<ans<<'\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
