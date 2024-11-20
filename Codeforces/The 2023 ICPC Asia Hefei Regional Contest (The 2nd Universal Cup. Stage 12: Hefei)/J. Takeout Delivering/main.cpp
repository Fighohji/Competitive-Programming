#include <climits>
#include <iostream>
#include <random>
#include <queue>
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

constexpr int N = 3e5 + 50;
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

vector<pii>to[N];
struct  node
{
    int len,id;
    bool operator<(const node & a)const{
        return len>a.len;
    }
};
void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        to[u].emplace_back(v,w);
        to[v].emplace_back(u,w);
    }
    priority_queue<node>q;
    q.push({0,1});
    vector<int>vis(n+1);
    vector<int>dis1(n+1,(int)2e9+1),dis2(n+1,(int)2e9+1);
    dis1[1]=0;
    while(!q.empty()){
        auto [d,u]=q.top();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto &[v,w]:to[u]){
            int now=max(w,dis1[u]);
            if(now<dis1[v]){
                dis1[v]=now;
                q.push({now,v});
            }
        }
    }
    dis2[n]=0;
    q.push({0,n});
    fill(all(vis),0);
    while(!q.empty()){
        auto [d,u]=q.top();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto &[v,w]:to[u]){
            int now=max(w,dis2[u]);
            if(now<dis2[v]){
                dis2[v]=now;
                q.push({now,v});
            }
        }
    }
    int ans=2e9;
    for(int u=1;u<=n;u++){
        for(auto &[v,w]:to[u]){
            if(dis1[u]<=w&&dis2[v]<=w){
                ans=min(ans,max(dis1[u],dis2[v])+w);
            }
            if(dis2[u]<=w&&dis1[v]<=w){
                ans=min(ans,max(dis2[u],dis1[v])+w);
            }
        }
    }
    cout<<ans<<'\n';
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
