#include <climits>
#include <iostream>
#include <random>
#include <deque>
#include <vector>
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
constexpr int dir[2][6][2] = {
    {
        {-1,0},
        {-1,1},
        {0,-1},
        {0,1},
        {1,0},
        {1,1}
    },
    {
        {-1,0},
        {-1,-1},
        {0,-1},
        {0,1},
        {1,0},
        {1,-1}
    }
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>dp(n+1,vector<int>(m+2));
    vector<string>s(n+1);
    for(int i=1;i<=n;i++){
        cin>>s[i];
        s[i]=" "+s[i];
    }
    int tot=1;
    vector<vector<int>>dis(n+1,vector<int>(m+1,INF));
    deque<pair<int,int>>q;
    for(int i=1;i<=m;i++){
        if(s[1][i]=='#'){
            dis[1][i]=0;
            q.push_front({1,i});
        }else{
            dis[1][i]=1;
            q.push_back({1,i});
        }
    }

    while (q.size()){
        pair<int,int> u = q.front();
        q.pop_front();
        auto [x,y]=u;
        if(x==n){
            cout<<dis[x][y]<<'\n';
            return;
        }
        for(int k=0;k<6;k++){
            int nx=dir[x%2][k][0]+x;
            int ny=dir[x%2][k][1]+y;
            if(nx<1||ny<1||nx>n||ny>m)continue;
            if(s[nx][ny]=='#'){
                if(dis[nx][ny]>dis[x][y]){
                    dis[nx][ny]=dis[x][y];
                    q.push_front({nx,ny});
                }
            }else {
                if(dis[nx][ny]>dis[x][y]+1){
                    dis[nx][ny]=dis[x][y]+1;
                    q.push_back({nx,ny});
                }
            }
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
