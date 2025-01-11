#include <iostream>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
// #define DEBUG
#ifdef DEBUG
#define debug(...) [](auto...a){((cerr<<a<<' '),...)<<endl;}(#__VA_ARGS__,":",__VA_ARGS__)
#define debugv(v) do{cerr<<#v<<" : {";for(int izxc=0;izxc<v.size();++izxc){cerr<<v[izxc];if(izxc+1!=v.size())cerr <<", ";}cerr<<"}"<<endl;}while(0)
#define debugmp(mp) do{cerr<<#mp<<" : { ";for(auto p:mp){cerr<<'['<<p.first<<" -> "<<p.second<<"] ";}cerr<<"}"<<endl;}while(0)
#define debugset(s) do{cerr<<#s<<" : {";for(auto x:s)cerr<<x<<' ';cerr<<"}"<<endl;}while(0)
#else
#define debug(...)
#define debugv(v)
#define debugmp(mp)
#define debugset(s)
#endif
typedef long long i64;
typedef pair<int, int> pii;

i64 dp[5000012], ans;
int cnt[5000012], n, x, MAX;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n; 
    for(int i = 0; i < n; i++) {
        cin >> x; MAX = max(x, MAX);
        for(int j = 1; j * j <= x; j++) {
            if(x % j == 0) {
                cnt[j]++;
                if(j * j != x) cnt[x / j]++;
            }
        }
    }
    for(int i = MAX; i >= 1; i--) {
        dp[i] = (i64)cnt[i] * i;
    }
    for(int i = MAX; i >= 1; i--) {
        for(int j = i * 2; j <= MAX; j += i) {
            dp[i] = max(dp[i], dp[j] + i * (cnt[i] - cnt[j]));
        }
        if(cnt[i] == n) ans = max(ans, dp[i]); 
    }
    cout << ans << endl;
    return 0;
}
