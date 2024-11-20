#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=3e5+10;
ll n;
ll mas[N];
ll low[N];
ll ans1,ans2;
ll inf=1e18;
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i) cin>>mas[i];
    memset(low,0x3f,sizeof low);
    for(int i=1;i<=n;++i){
        low[lower_bound(low+1,low+1+n,mas[i])-low]=mas[i];
    }
    for(int i=n;i;--i){
        if(low[i]!=0x3f3f3f3f3f3f3f3f){
            ans2=i;
            break;
        }
    }
    reverse(mas+1,mas+1+n);
    fill(low+1, low+n+1, inf);//重新初始化不要忘了！！！
    for(int i=1;i<=n;++i){
        low[upper_bound(low+1,low+1+n,mas[i])-low]=mas[i];
    }
    for(int i=1;i<=n;++i){
        if(low[i]!=inf) ans1=i;
    }
    cout<<ans2<<endl;
    return 0;
}
