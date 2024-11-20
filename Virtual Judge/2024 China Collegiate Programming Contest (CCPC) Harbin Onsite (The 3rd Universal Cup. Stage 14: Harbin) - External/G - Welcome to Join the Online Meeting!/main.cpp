#include <climits>
#include <iostream>
#include <random>
#include <queue>
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
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> sp(n + 1);
    vector<int> a(k), vis(n + 1);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        sp[a[i]] = 1;
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (sp[i]) continue;

        q.push(i);
        vis[i]=1;

        break;
    }
    int cnt=0;
    vector<vector<int>>Ans;
    vector<int>id;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;
        if(sp[u])continue;
        vector<int>vec;
        for(auto v:G[u]){
            if(vis[v])continue;
            vec.push_back(v);
            q.push(v);
            vis[v]=1;
        }
        if(vec.size()){
            id.push_back(u);
            Ans.push_back(vec);
        }
    }
    if(cnt!=n){
        cout<<"No\n";
        return;
    }
    cout << "Yes\n";
    cout << Ans.size() << '\n';
    for(int i=0;i<Ans.size();i++){
        cout<<id[i]<<' '<<Ans[i].size();
        for(auto x:Ans[i]){
            cout<<" "<<x;
        }
        cout<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
