#include <climits>
#include <iostream>
#include <random>
#include <map>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n;
    cin>>n;
    // cout<<"**"<<n<<'\n';
    vector<map<int, int>>vec(3);
    vector<vector<int>>a(n+1,vector<int>(3));
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            vec[j][a[i][j]]++;
        }
    }
    vector<int>b;
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=0;j<3;j++){
            mx=max(mx,vec[j][a[i][j]]);
        }
        b.push_back(mx-1);
    }
    sort(all(b));
    int ans=0,p=0;
    for(int i=0;i<n;i++){
        while(p<n&&b[p]<i){
            p++;
            ans++;
        }
        cout<<ans<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
