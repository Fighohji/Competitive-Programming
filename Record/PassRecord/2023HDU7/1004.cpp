#include <bits/stdc++.h>
using namespace std ;
const int N=100;
#define ll int
ll n=1;
ll mas[N];
ll ans=1e9;
string gs,ss;
ll f()
{
    // cout<<n<<" o ";
    // for(int i=1;i<=n;++i) cout<<mas[i]<<" ";
    //     cout<<endl;
    ll ma=0;
    ss="";
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            vector<ll> vt;vt.clear();
            vt.push_back(0);
            ll len=j-i+1;//lenth
            for(int s=i;s<=j;++s)
            {
                vt.push_back(mas[s]);
            }
            sort(vt.begin(),vt.end());
            ll cn[5];for(int s=0;s<=3;++s) cn[s]=0;
            for(int s=1;s<vt.size();++s)
            {
                // cout<<vt[s]<<' '<<cn[vt[s]]<<endl;
                cn[vt[s]]++;
            }
            // for(int s=1;s<=3;++s) cout<<cn[i]<<' ';
            ll p=0;
            if(len%2) p=vt[(len+1)/2];
            else
            {
                ll o1=vt[(len)/2];
                ll o2=vt[len/2+1];
                if(cn[o1]==cn[o2]) p=o1;
                else if(cn[o1]>cn[o2]) p=o1;
                else p=o2;
            }
            // cout<<p<<" "<<cn[p]<<endl;
            if(ma>ans) return 1e9;
            if(ma<cn[p])
            {
                ma=cn[p];
                ss="";
                for(int s=1;s<=n;++s) ss+=(char)(mas[s]+'0');
            }

        }
    }
    // cout<<ss<<endl;
    return ma;
}
void dfs(ll id)
{
    if(id==n+1)
    {
        // cout<<ans<<" "<<f()<<endl;
        ll det=f();
        if(ans>det)
        {
            ans=det;
            // cout<<ss<<endl;
            gs=ss;
        }
        return;
    }
    mas[id]=1;
    dfs(id+1);
    mas[id]=2;
    dfs(id+1);
    mas[id]=3;
    dfs(id+1);
}
void solve()
{
    ans=1e9;
    dfs(1);
    cout<<n<<' '<<ans<<" "<<gs<<endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;cin>>t;while(t--)
    solve(),n++;
    return 0;
}
