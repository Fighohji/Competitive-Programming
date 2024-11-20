#include <climits>
#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <queue>
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
vector<int>to[N];
int d[N],tmp[N];
multiset<int>st;
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v;
        cin>>u>>v;
        to[u].push_back(v);
        to[v].push_back(u);
        d[u]++;
        d[v]++;
    }
    queue<int>q;
    int cnt[2] = {0, 0};
    for(int i=1;i<=n;i++){
        tmp[i]=d[i];
        st.insert(d[i]);
        if(d[i]==1){
            q.push(i);
        }
        cnt[d[i]<=3]++;
    }
    vector<int>vis(n+1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        vis[x]=1;
        for(auto it:to[x]){
            tmp[it]--;
            tmp[x]--;
            if(tmp[it]==1){
                q.push(it);
            }
        }
    }
    int Ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            for(auto it:to[i]){
                if(!vis[it]){
                    st.erase(st.lower_bound(d[i]));
                    st.erase(st.lower_bound(d[it]));
                    st.insert(d[i]-1);
                    st.insert(d[it]-1);
                    if(d[i]-1==3){
                        cnt[1]++;
                        cnt[0]--;
                    }
                    if(d[it]-1==3){
                        cnt[1]++;
                        cnt[0]--;
                    }
                    if(*st.begin()<=3&&*st.rbegin()<=4){
                        Ans+=cnt[1];
                    }
                    st.erase(st.lower_bound(d[i]-1));
                    st.erase(st.lower_bound(d[it]-1));
                    st.insert(d[i]);
                    st.insert(d[it]);
                    if(d[i]-1==3){
                        cnt[0]++;
                        cnt[1]--;
                    }
                    if(d[it]-1==3){
                        cnt[0]++;
                        cnt[1]--;
                    }
                }
            }
        }
    }
    cout<<Ans/2<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}

