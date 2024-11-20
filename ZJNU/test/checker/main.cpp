#include <iostream>
using namespace std;
#define ll long long


void solve(){
	int n;
	cin>>n;
	vector<int> A(n+1);
	for (int i=1; i<=n; ++i) cin>>A[i];
	int q;
	cin>>q;
	while (q--){
		int l,r;
		cin>>l>>r;
		for (int i=l; i<=r; ++i) A[i]++;
	}
	for (int i=1; i<=n; ++i) cout<<A[i]<<" ";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int _=1;
	while (_--) solve();
	return 0;
} 
