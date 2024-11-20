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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
// #define db double
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
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const double pi = acos(-1.000);
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
#define int long long
int M = 32767;
struct cp {
    double r, i;
    cp(double _r = 0, double _i = 0) : r(_r), i(_i) {}
    cp operator * (const cp &a) {return cp(r * a.r - i * a.i, r * a.i + i * a.r);}
    cp operator + (const cp &a) {return cp(r + a.r, i + a.i);}
    cp operator - (const cp &a) {return cp(r - a.r, i - a.i);}
}w[N], nw[N], da[N], db[N];

cp conj(cp a) {return cp(a.r, -a.i);}

int L,a[N], b[N], c[N],R[N], P=1e18;

void Pre(int n, int m) {
    int x = 0; for(L = 1; (L <<= 1) <= n + m; ++x) ;
    for(int i = 1;i < L; ++i) R[i] = (R[i >> 1] >> 1) | (i & 1) << x;
    for(int i = 0;i < L; ++i) w[i] = cp(cos(2 * pi * i / L), sin(2 * pi * i / L));
}

void FFT(cp *F) {
    for(int i = 0;i < L; ++i) if(i < R[i]) std::swap(F[i], F[R[i]]);
    for(int i = 2, d = L >> 1;i <= L; i <<= 1, d >>= 1)
        for(int j = 0;j < L; j += i) {
            cp *l = F + j, *r = F + j + (i >> 1), *p = w, tp;
            for(int k = 0;k < (i >> 1); ++k, ++l, ++r, p += d)
                tp = *r * *p, *r = *l - tp, *l = *l + tp;
        }
}
void Mul(int *A, int *B, int *C) {
    for(int i = 0;i < L; ++i) (A[i] += P) %= P, (B[i] += P) %= P;
    static cp a[N], b[N], Da[N], Db[N], Dc[N], Dd[N];
    for(int i = 0;i < L; ++i) a[i] = cp(A[i] & M, A[i] >> 15);
    for(int i = 0;i < L; ++i) b[i] = cp(B[i] & M, B[i] >> 15);
    FFT(a); FFT(b);
    for(int i = 0;i < L; ++i) {
        int j = (L - i) & (L - 1); static cp da, db, dc, dd;
        da = (a[i] + conj(a[j])) * cp(0.5, 0);
        db = (a[i] - conj(a[j])) * cp(0, -0.5);
        dc = (b[i] + conj(b[j])) * cp(0.5, 0);
        dd = (b[i] - conj(b[j])) * cp(0, -0.5);
        Da[j] = da * dc; Db[j] = da * dd; Dc[j] = db * dc; Dd[j] = db * dd; //顺便区间反转，方便等会直接用DFT代替IDFT
    }
    for(int i = 0;i < L; ++i) a[i] = Da[i] + Db[i] * cp(0, 1);
    for(int i = 0;i < L; ++i) b[i] = Dc[i] + Dd[i] * cp(0, 1);
    FFT(a); FFT(b);
    for(int i = 0;i < L; ++i) {
        int da = (ll) (a[i].r / L + 0.5) % P; //直接取实部和虚部
        int db = (ll) (a[i].i / L + 0.5) % P;
        int dc = (ll) (b[i].r / L + 0.5) % P;
        int dd = (ll) (b[i].i / L + 0.5) % P;
        C[i] = (da + ((ll)(db + dc) << 15) + ((ll)dd << 30)) % P;
    }
}


mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
int n,cnt,q;
ll mas[N],vis[N];
vector<ll> vt[N];
int E[N];
void dfs(ll id)
{
    if(vis[id]) return;
    vt[cnt].push_back(id);
    vis[id]=1;
    dfs(E[id]);
}

unordered_map<int, vector<int>>mp;
vector<int> operator +(const vector<int> &a,const vector<int> &b)
{
    vector<int> c;
    for(int i=0;i<a.size();++i) c.push_back(a[i]+b[i]);
    return c;
}
#define endl '\n'
void solve()
{
    /*
    Poly::init(n + m);
    Poly::NTT(A), Poly::NTT(B);

    for (int i = 0; i < Poly::lim; ++i) A[i] = A[i] * B[i];

    Poly::NTT(A, 0);
    */
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>mas[i],E[mas[i]]=i;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]) continue;
        cnt++;
        dfs(i);
    }

    for(int i=1;i<=cnt;++i)
    {
        // vector<Int> a,b;
        int size=vt[i].size();
        int c1 = 0;
        for(auto s:vt[i]) a[c1++] = s;
        for(auto s:vt[i]) a[c1++] = s;
        c1 = size - 1;
        for(auto s:vt[i]) b[c1--] = s;
        // reverse(b.begin(),b.end());
            // cerr << 1 << '\n';
        Pre(size, 2 * size);
        // cerr << 2 << '\n';
        Mul(a, b, c);
        // cerr << 3 << '\n';

        vector<int> ans;
        for(int j = 0; j < L; ++j) ans.push_back(c[j]);
        for(int j = 0; j < L; ++j) a[j] = b[j] = 0;
        // cout<<i<<endl;
        // for(auto s:ans) cout<<s<<' ';
        //     cout<<endl;
        // cerr << "ook\n";
        if(mp.count(size)==0) mp[size]=ans;
        else mp[size]=mp[size]+ans;
        // cerr << "ok\n";
    }
    ll val;
    ll Ans=0;
    while(q--)
    {
        cin>>val;
        Ans=0;
        for(auto &[size,p]:mp)
        {
            ll k=val%size;
            Ans+=p[k+size-1];
        }
        cout<<Ans<<endl;
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
/*
4 3
2 1 4 3
1
2
3
*/
