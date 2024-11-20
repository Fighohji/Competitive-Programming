#include <iostream>
using namespace std;
int ss,n,m,mid,now,a[50005],s,ans;
int main()
{
	cin>>ss>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=ss;
	while(l<=r)
	{
	    mid=r+l>>1;
	    now=0;
		s=0;
		for(int i=1;i<=n;i++)
		    if(a[i]-a[now]<mid)
			    s++;
			else now=i;
	if(s<=m){ans=mid;
	l=mid+1;}
else r=mid-1;}
	cout<<ans;
	return 0;
}
