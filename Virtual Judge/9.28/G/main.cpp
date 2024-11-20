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

int n;
int dp[305][305];
int pre[305][305];
char ans[305];
void dfs(int l,int r){
    // cout<<l<<' '<<r<<'\n';
    if(l+1==r){
        ans[l]='[';
        ans[r]=']';
        return;
    }
    if(pre[l][r]==-1){
        ans[l]='[';
        ans[r]=']';
        dfs(l+1,r-1);
    }else{
        dfs(l,pre[l][r]);
        dfs(pre[l][r]+1,r);
    }
}
void solve() {
    string s;
    cin>>s;
    vector<int>a;
    a.push_back(0);
    for(int i=0;i<s.size();i+=2){
        if(s[i]=='<'&&s[i+1]=='<')a.push_back(1);
        else if(s[i]=='>'&&s[i+1]=='>')a.push_back(-1);
        else {
            cout<<"Keine Loesung";
            return;
        }
    }
    n=a.size()-1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1])dp[i][i+1]=1;
    }
    for(int len=3;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r=l+len-1;
            for(int mid=l;mid<r;mid++){
                dp[l][r]|=(dp[l][mid]&dp[mid+1][r]);
                if(dp[l][r]){
                    pre[l][r]=mid;
                    break;
                }
            }
            if(a[l]!=a[r]){
                dp[l][r]|=dp[l+1][r-1];
                if(dp[l][r]){
                    pre[l][r]=-1;
                }
            }
        }
    }
    if(dp[1][n]!=0){
        dfs(1,n);
        for(int i=1;i<=n;i++){
            cout<<ans[i];
        }

    }else cout<<"Keine Loesung";
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

