#include <cstdlib>
#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <limits.h>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

#define int long long
constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
const int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define int long long
bool BEGIN;
int MOD[2];
int BASE=487;
string s;
int pre[maxn];
int power[maxn][2];
int hs1[maxn][2];
int hs2[maxn][2];
void init(int n){
    MOD[0]=mod;
    MOD[1]=rand()%1000000+1000000000;
    power[0][0]=1;
    power[0][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            power[i][j]=power[i-1][j]*BASE%MOD[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            hs1[i][j]=(hs1[i-1][j]*BASE+(s[i]-'0'))%MOD[j];
            hs2[i][j]=(hs2[i-1][j]*BASE+1)%MOD[j];
        }
    }
}
int n,m;
int gethas1(int l,int r){
    if(l>r)return 0;
    return (hs1[r][0]-hs1[l-1][0]*power[r-l+1][0]%MOD[0]+MOD[0])%MOD[0];
}
int gethas2(int l,int r){
    if(l>r)return 0;
    return (hs1[r][1]-hs1[l-1][1]*power[r-l+1][1]%MOD[1]+MOD[1])%MOD[1];
}
int newhas1(int l,int r){
    int x=pre[r]-pre[l-1];
    return (gethas1(1,l-1)*power[n-(l-1)][0]%MOD[0]+hs2[x][0]*power[n-r][0]%MOD[0]+gethas1(r+1,n))%MOD[0];
}
int newhas2(int l,int r){
    int x=pre[r]-pre[l-1];
    return (gethas2(1,l-1)*power[n-(l-1)][1]%MOD[1]+hs2[x][1]*power[n-r][1]%MOD[1]+gethas2(r+1,n))%MOD[1];
}
set<pii>st;
void solve(int cas) {
    st.clear();
    cin>>n>>m;
    cin >> s;
    s = "~" + s;
    init(n);
    for (int i = 1; i <= n; ++i) {
        pre[i] = 0;
    }
    for(int i=1;i<=n;i++){
        pre[i]=s[i]-'0';
        pre[i]+=pre[i-1];
    }
    // cout<<gethas1(3,4)<<' '<<hs2[2][0]<<'\n';
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        st.insert({newhas1(l,r),newhas2(l,r)});
    }
    cout<<st.size()<<'\n';
}

bool END;
signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // isprime(1e5);
    // cerr << cnt << '\n';
    int T; cin >> T; while (T--) {
        solve(1);
    }
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
