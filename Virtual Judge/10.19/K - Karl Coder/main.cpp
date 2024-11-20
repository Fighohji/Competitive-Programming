#include <climits>
#include <iostream>
#include <random>
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
#define int long long
int query(int x){
    cout<<"buf["<<x<<"]"<<endl;
    int res;
    cin>>res;
    return res;
}

void solve() {
    int l=1,r=0;
    for(int i=4;;i*=2){
        int x=query(i-1);
        if(x==0){
            r=i-1;
            break;
        }
        l=i-1;
    }
    int res=0;
    while(l+1<r){
        int mid=l+r>>1;
        if(query(mid)){
            l=mid;
            res=mid;
        }else r=mid;
    }
    cout<<"strlen(buf) = "<<l+1<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
