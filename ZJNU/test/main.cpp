#include <iostream>
#include <map>
#define int long long
using namespace std;
int t;
int quickPower(int a,int b) {
	int ans=1;
	int base=a;
	while(b>0) {
		if(b&1) {
			ans*=base;
		}
		base*=base;
		b>>=1;
	}
	return ans;
}
int caculate(int x,int k) {
	int a;
	int sum=1;
	while(x>0) {
		a=x%k;
		x=x/k;
		sum*=a;
	}
	return sum;
}
map<int ,bool>mp;
signed main() {
	cin>>t;
	int x;
	int y=1;
	for(int i=1; y*2<=1e18; i++) {
		y=quickPower(2,i);
		mp[y-1]=1;
	}
	while(t--) {
		cin>>x;
		if(mp[x]==1) {
			cout<<"Win"<<endl;
			continue;
		} else {
			int ok=0;
			for(int i=2; i<=16; i++) {
				if(mp[caculate(x,i)]==1) {
					ok=1;
					break;
				}
			}
			if(ok) {
				cout<<"Win"<<endl;
			} else {
				cout<<"Lose"<<endl;
			}
		}
	}
	return 0;
}
