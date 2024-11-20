#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define eps 1e-9
const int N=1e6+10;
const ll mod=998244353;
int n,m;
vector<int> vt[N];
int nex[N];
string s;
bool vis[N];
int phi[N];
int p[N];
int cnt=0;
void init(ll n)
{
    phi[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!vis[i])
        {
            p[++cnt]=i;
            phi[i]=i-1;
        }
        for(int j=1;j<=cnt&&i*p[j]<=n;++j)
        {
            vis[i*p[j]]=1;
            if(i%p[j]==0)
            {
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }
            phi[i*p[j]]=phi[i]*(p[j]-1);
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;j+=i)
        {
            vt[j].push_back(i);
        }
    }
}
void kmp()
{
    nex[1]=nex[0]=0;
    ll k=0;
    for(int i=2;i<=n;++i)
    {
        while(k&&s[i]!=s[k+1]) k=nex[k];
        if(s[i]==s[k+1]) ++k;
        nex[i]=k;
    }
}
struct ty
{
    int t,next;
}edge[N<<1];
int cn=0;
int head[N];
int num[N];
ll ans=0;
void add(ll a,ll b)
{
    edge[++cn].t=b;
    edge[cn].next=head[a];
    head[a]=cn;
}
void dfs(ll id)
{
    ll sum=1;
    for(auto s:vt[id])
    {
        sum=(sum+1ll*num[s]*phi[s]%mod)%mod;
        num[s]++;
    }
    ans=ans*1ll*sum%mod;
    for(int i=head[id];i!=-1;i=edge[i].next)
    {
        ll y=edge[i].t;
        dfs(y);
    }
    for(auto s:vt[id]) num[s]--;
}
void solve()
{
    cin>>s;n=s.size();s=" "+s;
    for(int i=0;i<=n+2;++i) head[i]=-1;
    kmp();
    for(int i=1;i<=n;++i)
    {
        add(nex[i],i);
    }
    ans=1;
    dfs(0);
    cout<<ans<<endl;
    cn=0;
    for(int i=0;i<=n+5;++i) nex[i]=0;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init(1000000);
    ll t;cin>>t;while(t--)
    solve();
    return 0;
}
