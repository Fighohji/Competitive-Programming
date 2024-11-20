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
vector<int>to[66];
int d[66],ans[66],fa[66];
void dfs(int p,int f){
    fa[p]=f;
    for(auto it:to[p]){
        if(it==f)continue;
        d[p]++;
        dfs(it,p);
    }
}
int vis[1005];
int fac[1005],tot;
void init(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            fac[tot++]=i;
            if(tot==66)return;
            for(int j=i+i;j<=n;j+=i){
                vis[j]=1;
            }
        }
    }
}
void solve() {
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    dfs(1,1);
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(!d[i])v.push_back(i);
    }
    
    ans[1]=1;
    init(1000);
    for(int i=0;i<v.size();i++){
        vector<int>dep(n+1);
        for(int j=i;j<v.size();j++){
            int p=v[j];
            while(!ans[fa[p]]){
                p=fa[p];
                dep[v[j]]++;
            }
        }
        sort(v.begin()+i,v.end(),[&](int x,int y){
            return dep[x]>dep[y];
        });
        int pos=v[i];
        stack<int>st;
        st.push(pos);
        while(!ans[fa[pos]]){
            pos=fa[pos];
            st.push(pos);
        }
        while(!st.empty()){
            int x=st.top();
            st.pop();
            ans[x]=ans[fa[x]]*fac[i];
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
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