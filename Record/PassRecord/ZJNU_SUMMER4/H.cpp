#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const ll N=1e5+10;
ll n,m,cnt,ans,sig,top,a,b;
vector<ll> vt[N];
ll dfn[N];
ll vis[N];
ll low[N];
ll num[N];//该颜色的数目 
ll st[N];//栈 
ll color[N];
map<ll,ll> mp;
ll mi[N];
ll rd[N];
void init()
{
    memset(vis,0,sizeof vis);
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
}
void tarjan(int u)
{
    vis[u]=1;
    st[++top]=u;
    low[u]=dfn[u]=cnt++;
    for(int i=0;i<vt[u].size();i++)
    {
        ll v=vt[u][i];
        if(dfn[v]==0) tarjan(v),low[u]=min(low[u],low[v]);
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        sig++;
        while(1)
        {
            ll t=st[top--];
            num[sig]++; 
            vis[t]=0;
            color[t]=sig;//染色,缩点 
            mi[sig]=min(mi[sig],t);//统计环内部最小值
            if(t==u) break;
        }
    }
}
void solve()
{
    cnt=1;sig=0;
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
        {
            tarjan(i);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(ll j:vt[i])
        {
            if(color[i]!=color[j]) rd[color[j]]++;//入度++
        }
    }
    ll ans=0;
    for(int i=1;i<=sig;++i)
    {
        if(rd[i]==0)
        {
            cout<<mi[i]<<endl;
        }
    }
    // cout<<num[ans]<<endl;
}
int main()
{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) vt[i].clear();
        for(int i=1;i<=n;++i) mi[i]=1e9;
    init();
    for(int i=1;i<=m;++i)
    {
        cin>>a>>b;
        vt[a].push_back(b);
    }
    solve();
    return 0;
}
