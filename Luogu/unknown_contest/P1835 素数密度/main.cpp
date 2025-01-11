#include <cstdio>
#include <iostream>
#define int long long
using namespace std;
int l,r,sum,ans[1000010];
int cnt=0;
bool is[1000010];
void check()
{
	memset(is,1,sizeof(is));
	is[1]=is[0]=0;
	for(int i=2;i<=50000;i++)
	{
		if(is[i]) ans[++cnt]=i;
		for(int j=1;j*j<=50000&&i*ans[j]<=50000;i++)
		{
			is[i*ans[j]]=0;
			if(i%ans[j]==0) break;
		}
	}
}
signed main()
{
	scanf("%lld%lld",&l,&r);
	check();
	memset(is,1,sizeof(is));
    for(int i=1;i<=cnt;++i)
    {
        int p=ans[i],st=0;
		if((l+p-1)/p*p>2*p) st=(l+p-1)/p*p;
		else st=2*p;
        for(int j=st;j<=r;j+=p) is[j-l+1]=0;
    }
    is[1]=0;
    for(int i=1;i<=r-l+1;++i) if(is[i]) sum++;
    cout<<sum;
	return 0;
} 
