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

int vis[N],siz[N];
vector<int>to[N];
int dfs(int p,int f){
    siz[p]=1;
    vis[p]=1;
    for(auto it:to[p]){
        if(it==f)continue;
        siz[p]+=dfs(it,p);
    }
    return siz[p];
}
int ans,res;
void dfs2(int p,int f){
    int flag=0;
    for(auto it:to[p]){
        
        int sp=siz[p],si=siz[it];
        int f1,f2;
        if(si%2){
            f1=1;
            flag^=1;
        }
        else {
            f1=2;
            flag^=2;
        }
        if(it==f)continue;
        if((sp-si)%2)f2=1;
        else f2=2;
        if((ans^f1^f2)==0){
            res++;
        }
        siz[p]-=si;
        siz[it]=sp;
        dfs2(it,p);
        siz[p]=sp;
        siz[it]=si;
    }
    if(ans==flag)res++;
}
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<pair<int,int>>tr;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            int siz=dfs(i,i);
            if(siz%2){
                ans^=1;
            }
            else {
                ans^=2;
            }
            tr.push_back({i,2-siz%2});
        }
    }
    for(auto it:tr){
        auto [root,val]=it;
        ans^=val;
        dfs2(root,root);
        ans^=val;
    }
    cout<<res<<'\n';
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
