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
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


struct ndoe
{
    int l,r,u,k;
}t[maxn<<2];
string s;
void push(int p)
{
    int pr=p<<1;
    t[p].u=t[pr].u*t[pr|1].u;
    t[p].k=t[pr|1].u*t[pr].k+t[pr|1].k;
}
void build(int p,int l,int r)
{
    t[p].l=l;t[p].r=r;
    if(l==r)
    {
        if(s[l-1]=='A')
        {
            t[p].u=-1;
            t[p].k=-1;
        }
        else
        {
            t[p].u=1;
            t[p].k=1;
        }
        return ;
    }
    int mid=(t[p].l+t[p].r)>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    push(p);
}
pii query(int p,int l,int r)
{
    // cerr<<p<<'\n';
    if(l<=t[p].l&&t[p].r<=r)
    {
        return {t[p].u,t[p].k};
    }
    int mid=(t[p].l+t[p].r)>>1;
    if(r<=mid)return query(p<<1,l,r);
    if(l>mid)return query(p<<1|1,l,r);
    pii ans=query(p<<1,l,r);
    pii mul=query(p<<1|1,l,r);
    return {ans.fir*mul.fir,mul.fir*ans.sec+mul.sec};
}
string tt;
ll base[maxn];
void solve(int cas) {
    int n,q;cin>>n>>q;
    base[0]=1;
    for(int i=1;i<=55;++i)base[i]=base[i-1]*2ll;
    cin>>s;
    // s='~'+s;
    int ans=0;
    build(1,1,n);
    while(q--)
    {
        int l,r;cin>>l>>r;
        int L=min((ans^l)%n+1,(ans^r)%n+1);
        int R=max((ans^l)%n+1,(ans^r)%n+1);
        cin>>tt;
        int m=tt.size();
        ll now=0;
        for(int i=0;i<m;++i)
        {
            now=now*2+(tt[i]=='1');
        }
        pii mul=query(1,L,R);
        now = mul.fir*now+mul.sec;
        now=(now%base[m]+base[m])%base[m];
        ans=now;
        for(int i=m;i;--i)
        {
            cout<<((ans>>(i-1))&1);
        }
        cout<<'\n';
    }
}

/*
3 1
BAA
1 1 0001

*/
bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
