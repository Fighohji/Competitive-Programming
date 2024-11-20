#include <climits>
#include <iostream>
#include <random>
#include <stack>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int>l(n),r(n);
    vector<int>ans(n);
    if(a[0]==0)ans[0]=0;
    else if(a[0]>0)ans[0]=1;
    else ans[0]=-1;
    l[0]=-1;
    r[0]=1;
    for(int i=1;i<n;i++){
        if(ans[i-1]==0){
            l[i]=-1;
            r[i]=1;
        }else{
            if(l[i-1]-a[i-1]>=0)l[i]=(l[i-1]-a[i-1])/2;
            else l[i]=(l[i-1]-a[i-1]-1)/2;
            if(r[i-1]-a[i-1]>=0)r[i]=(r[i-1]-a[i-1]+1)/2;
            else r[i]=(r[i-1]-a[i-1])/2;
        }
        // cout<<l[i]<<' '<<r[i]<<'\n';
        if(a[i]>l[i]&&a[i]<r[i])ans[i]=0;
        else if(a[i]<=l[i])ans[i]=-1;
        else ans[i]=1;
    }
    for(int i=0;i<n;i++){
        if(ans[i]==0)cout<<0;
        else if(ans[i]>0)cout<<'+';
        else cout<<'-';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
