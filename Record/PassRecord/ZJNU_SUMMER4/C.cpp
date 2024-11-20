#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int INF=0x3f3f3f3f;
const int N=2e5+10;

int n,m,match[N],pre[N];
ll mp[N],cn=0;
bool vis[N];
int favor[70][70];
int val1[N],val2[N],slack[N];
ll vv[N];
ll a[N],b[N];
void bfs(int p)
{
    memset(pre,0,sizeof pre);
    memset(slack,INF,sizeof slack);
    
    match[0]=p;
    
    int x=0,nex=0;
    do{
        vis[x]=true;
        
        int y=match[x],d=INF;
        

        for(int i=1;i<=m;i++)
        {
            if(!vis[i])
            {
                if(slack[i]>val1[y]+val2[i]-favor[y][i])
                {
                    slack[i]=val1[y]+val2[i]-favor[y][i];
                    pre[i]=x;
                }
                if(slack[i]<d)
                {
                    d=slack[i];
                    nex=i;
                }
            }
        }
        
        for(int i=0;i<=m;i++)
        {
            if(vis[i])
                val1[match[i]]-=d,val2[i]+=d;
            else
                slack[i]-=d;
        }
        
        x=nex;
        
    }while(match[x]);


    while(x)
    {
        match[x]=match[pre[x]];
        x=pre[x];
    }
}
int v[N],bl[N];
int ans[N];
void KM()
{
    memset(match,0,sizeof match);
    memset(val1,0,sizeof val1);
    memset(val2,0,sizeof val2);
    for(int i=m;i;--i)
    {
        memset(vis,false,sizeof vis);
        bfs(bl[i]);
        // cout<<"?? "<<" #"<<i<<" ";
        // for(int i=1;i<=m;++i)
        // {
        //     cout<<match[i]<<" \n"[i==m];
        // }
    }
    int res=0;
    ll nm=0;
    ll pos=1;
    for(int i=1;i<=n;++i)
    {
        ans[match[i]]=i;
        // cout<<match[a[i]]<<' ';
        // if(match[a[i]]==b[i])
        // {
        //     cout<<match[a[i]]<<" ";
        //     vv[b[i]]=1;
        // }
        // else
        // {
        //     if(a[i]==a[i-1]) cout<<pos<<' ';
        //     else
        //     {
        //         while(vv[pos]) pos++;
        //         vv[pos]=1;
        //         cout<<pos<<" ";
        //     }

        // }

    }
    // for(int i=1;i<=m;++i)cout<<match[i]<<" \n"[i==m];
    for(int i=1;i<=n;++i)cout<<ans[a[i]]<<' ';
    cout<<endl;
    // for(int i=1;i<=m;i++)
    //     res+=favor[match[i]][i];
    // return res;
}

int main()
{
    // Input favor[i][j]!!!
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=1;i<=n;++i)
    {
        if(!v[a[i]])
        {
            bl[++cn]=a[i];
            v[a[i]]=1;
        }

    }
    for(int i=1;i<=m;++i)
    {
        if(!v[i])bl[++cn]=i;
    }
    // for(int i=1;i<=m;++i)cout<<bl[i]<<" \n"[i==m];
    // for(int i=1;i<=n;++i)
    // {
    //     if(mp[a[i]]==0) mp[a[i]]=++cn;
    //     a[i]=mp[a[i]];
    // }

    for(int i=1;i<=n;++i)
    {
        favor[a[i]][b[i]]++;
    }
    KM();
//      m=n;
//      for(int i=1;i<=n;++i){
//          for(int j=1;j<=m;++j)
//          {
//              scanf("%d",&favor[i][j]);
//          }
//      }
        // printf("%d\n",KM());
    
    return 0;
}
