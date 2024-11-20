#include <climits>
#include <iostream>
#include <random>
#include <algorithm>
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

struct node{
    int x,y;
    bool operator<(const node & a)const{
        if(x==a.x)return y<a.y;
        return x<a.x;
    }
};
void solve() {
    int n; cin >> n;
    int tot = 0;
    vector<int> dp(n + 1);
    vector<node>a(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].x;
        a[i].y = i - a[i].x;
        
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        // cout<<a[i].y<<'\n';
        if(a[i].y >= dp[tot])
        {
            dp[++tot] = a[i].y;
            // cout << "i " << tot << ' ' << i << '\n';
        }
        else 
        {
            int p = upper_bound(dp.begin() + 1, dp.begin() + tot + 1, a[i].y) - dp.begin();
            // cout << p << ' ' << i << '\n';
            dp[p] = a[i].y;
        }
    }
    cout << tot << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
