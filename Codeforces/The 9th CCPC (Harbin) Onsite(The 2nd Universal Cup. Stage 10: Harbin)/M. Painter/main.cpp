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
struct op{
    string tp;
    int a[4];
    char col;
};
void solve() {
    int n;
    cin>>n;
    vector<op>vec;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(s=="Render"){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            for(int i=y2;i>=y1;i--){
                for(int j=x1;j<=x2;j++){
                    char ch='.';
                    for(auto it:vec){
                        if(it.tp=="Circle"){
                            if((i-it.a[1])*(i-it.a[1])+(j-it.a[0])*(j-it.a[0])<=it.a[2]*it.a[2]){
                                ch=it.col;
                            } 
                        }else{
                            if(i>=it.a[1]&&j>=it.a[0]&&i<=it.a[3]&&j<=it.a[2]){
                                ch=it.col;
                            }
                        }
                    }
                    cout<<ch;
                }
                cout<<'\n';
            }
            
        }else if(s=="Circle"){
            op d;
            d.tp=s;
            for(int i=0;i<3;i++)cin>>d.a[i];
            cin>>d.col;
            vec.push_back(d);
        }else{
            op d;
            d.tp=s;
            for(int i=0;i<4;i++)cin>>d.a[i];
            cin>>d.col;
            vec.push_back(d);
        }
    }
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
