#include <climits>
#include <iostream>
#include <random>
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

void solve() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    int tot=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tot+=a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(10001,-INF));
    vector<vector<pair<int,int>>>pre(n+1,vector<pair<int,int>>(10001,make_pair(-1,-1)));
    vector<int>id(10001);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        pre[i]=pre[i-1];
        for(int j=10000;j>=a[i];j--){
            if(dp[i][j]<dp[i-1][j-a[i]]+a[i]){
                dp[i][j]=dp[i-1][j-a[i]]+a[i];
                pre[i][j]={i-1,j-a[i]};
                id[j]=i;
            }
        }
    }
    if(tot%2){
        cout<<"-1\n";
        return;
    }
    if(dp[n][tot/2]!=tot/2){
        cout<<"-1\n";
        return;
    }
    vector<int>vis(n+1);
    int now=tot/2,nowi=n;
    while(now){
        vis[id[now]]=1;
        pair<int,int>p=pre[nowi][now];
        nowi=p.first;
        now=p.second;
    }
    vector<int>v1,v2;
    for(int i=1;i<=n;i++){
        if(vis[i])v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }
    int a1=0,a2=0;
    for(int i=1;i<=n;i++){
        if(a1<=a2){
            a1+=v1.back();
            cout<<v1.back()<<' ';
            v1.pop_back();
        }else{
            a2+=v2.back();
            cout<<v2.back()<<' ';
            v2.pop_back();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
