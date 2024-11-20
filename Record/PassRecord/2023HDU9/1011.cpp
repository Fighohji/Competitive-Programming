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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
ll qpow(ll x,ll y)
{
    ll ans=1;
    while(y)
    {
        if(y&1) ans=ans*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ans;
}

namespace Poly
{
    #define mul(x, y) (1ll * x * y >= mod ? 1ll * x * y % mod : 1ll * x * y)
    #define minus(x, y) (1ll * x - y < 0 ? 1ll * x - y + mod : 1ll * x - y)
    #define plus(x, y) (1ll * x + y >= mod ? 1ll * x + y - mod : 1ll * x + y)//上面其实没用到
    #define ck(x) (x >= mod ? x - mod : x)//取模运算太慢了

    typedef vector<int> poly;
    const int G = 3;//根据具体的模数而定，原根可不一定不一样！！！
    //一般模数的原根为 2 3 5 7 10 6
    const int inv_G = qpow(G, mod - 2),tt = 22;
    int deer[2][tt][(1 << tt)];
    vector<int>RR(1 << (tt + 1), 0),inv(1 << tt, 0);

    void init(const int t) {//预处理出来NTT里需要的w和wn，砍掉了一个log的时间
        assert(t < tt);//一定要注意！！
        for(int p = 1; p <= t; ++ p) {
            int buf1 = qpow(G, (mod - 1) / (1 << p));
            int buf0 = qpow(inv_G, (mod - 1) / (1 << p));
            deer[0][p][0] = deer[1][p][0] = 1;
            for(int i = 1; i < (1 << p); ++ i) {
                deer[0][p][i] = 1ll * deer[0][p][i - 1] * buf0 % mod;//逆
                deer[1][p][i] = 1ll * deer[1][p][i - 1] * buf1 % mod;
            }
        }
        inv[1] = 1;
        for(int i = 2; i <= (1 << t); ++ i)
            inv[i] = 1ll * inv[mod % i] * (mod - mod / i) % mod;
    }

    int NTT_init(int n) {//快速数论变换预处理
        int limit = 1, L = 0;
        while(limit <= n) limit <<= 1, L ++ ;
        assert(L < tt);
        assert(limit < 1 << (tt + 1));
        for(int i = 0; i < limit; ++ i)
            RR[i] = (RR[i >> 1] >> 1) | ((i & 1) << (L - 1));
        return limit;
    }

    void NTT(poly &A, bool type, int limit) {//快速数论变换
        A.resize(limit);
        for(int i = 0; i < limit; ++ i)
            if(i < RR[i])
                swap(A[i], A[RR[i]]);
        for(int mid = 2, j = 1; mid <= limit; mid <<= 1, ++ j) {
            int len = mid >> 1;
            for(int pos = 0; pos < limit; pos += mid) {
//                auto wn = deer[type][j].begin();
                for(int i = pos, p = 0; i < pos + len; ++ i, ++ p) {
                    int tmp = 1ll * deer[type][j][p] * A[i + len] % mod;
                    A[i + len] = ck(A[i] - tmp + mod);
                    A[i] = ck(A[i] + tmp);
                }
            }
        }
        if(type == 0) {
            for(int i = 0; i < limit; ++ i)
                A[i] = 1ll * A[i] * inv[limit] % mod;
        }
    }

    poly poly_mul(poly A, poly B) {//多项式乘法
        int deg = A.size() + B.size() - 1;
        int limit = NTT_init(deg);
        poly C(limit);
        NTT(A, 1, limit);
        NTT(B, 1, limit);
        for(int i = 0; i < limit; ++ i)
            C[i] = 1ll * A[i] * B[i] % mod;
        NTT(C, 0, limit);
        C.resize(deg);
        return C;
    }

    poly poly_inv(poly &f, int deg) {//多项式求逆 deg<f.szie()
        if(deg == 1)
            return poly(1, qpow(f[0], mod - 2));

        poly A(f.begin(), f.begin() + deg);
        poly B = poly_inv(f, (deg + 1) >> 1);
        int limit = NTT_init(deg << 1);
        NTT(A, 1, limit), NTT(B, 1, limit);
        for(int i = 0; i < limit; ++ i)
            A[i] = B[i] * (2 - 1ll * A[i] * B[i] % mod + mod) % mod;
        NTT(A, 0, limit);
        A.resize(deg);
        return A;
    }

    poly poly_dev(poly f) {//多项式求导
        int n = f.size();
        for(int i = 1; i < n; ++ i) f[i - 1] = 1ll * f[i] * i % mod;
        if(n > 1)f.resize(n - 1);
        else f[0] = 0;
        return f.resize(n - 1), f;//求导整体左移，第0项不要
    }

    poly poly_idev(poly f) {//多项式求积分
        int n = f.size();
        for(int i = n - 1; i ; -- i) f[i] = 1ll * f[i - 1] * inv[i] % mod;
        return f[0] = 0, f;//积分整体右移，第0项默认为0
    }

    poly poly_ln(poly f, int deg) {//多项式求对数，第一项为1
        poly A = poly_idev(poly_mul(poly_dev(f), poly_inv(f, deg)));
        return A.resize(deg), A;
    }

    poly poly_exp(poly &f, int deg) {//多项式求指数，第一项为0
        if(deg == 1)
            return poly(1, 1);

        poly B = poly_exp(f, (deg + 1) >> 1);
        B.resize(deg);
        poly lnB = poly_ln(B, deg);
        for(int i = 0; i < deg; ++ i)
            lnB[i] = ck(f[i] - lnB[i] + mod);

        int limit = NTT_init(deg << 1);//n -> n^2
        NTT(B, 1, limit), NTT(lnB, 1, limit);
        for(int i = 0; i < limit; ++ i)
            B[i] = 1ll * B[i] * (1 + lnB[i]) % mod;
        NTT(B, 0, limit);
        B.resize(deg);
        return B;
    }

    poly poly_pow(poly f, int k) {//多项式快速幂,第一项得是1
        f = poly_ln(f, f.size());
        for(auto &x : f) x = 1ll * x * k % mod;
        return poly_exp(f, f.size());
    }
     poly poly_ksm(poly f, int k,int m) {//多项式快速幂,适用于初始只有几项，同时所有项都需要的情况,会比上面那个快一点
        poly res(1, 1);
        while(k){
            if(k & 1)
                {
                    res = poly_mul(res, f);
                    res.resize(m,0);
                }
            f = poly_mul(f, f);
            f.resize(m,0);
            k >>= 1;
        }
        return res;
    }




}

using Poly::poly;
using Poly::poly_pow;
using Poly::poly_ksm;
using Poly::poly_mul;
using Poly::poly_inv;

int  x, type;
char s[N];
ll p[N],pp[N],C[N];
void init(ll n,ll k)
{
    p[0]=1;
    for(ll i=1;i<=n;++i) p[i]=p[i-1]*i%mod;
        pp[n]=qpow(p[n],mod-2);
    for(ll i=n-1;i>=0;--i) pp[i]=pp[i+1]*(i+1)%mod;
        C[0]=1;
    // for(ll i=1;i<=n;++i) C[i]=C[i-1]*qpow(i,mod-2)%mod*(k-i+1)%mod;
    for(int i=1;i<=n;++i) C[i]=p[k]*pp[k-i]%mod;
}

ll dp[1010][1010];
ll n,m,k;
ll num1[N],num2[N];
void solve()
{
    cin>>n>>m>>k;
    init(max(max(n,m),k),k);
    // for(int i=0;i<=10;++i) cout<<C[i]<<' ';
    //     cout<<endl;
    for(int i=1;i<=n;++i)
    {
        ll a;cin>>a;
        num1[a]++;
    }
    for(int i=1;i<=m;++i)
    {
        num2[num1[i]]++;
    }

    Poly::init(20);
    poly f(m + 1);
    for(int i=0;i<=m;++i) f[i]=mod-num2[i];
        // cout<<"f "<<f[0]<<endl;
    poly _g = f;
    for(int i=0;i<=m;++i) {if(i==0)_g[i]=(1-f[i]+mod)%mod;else _g[i] = (-f[i]+mod)%mod;}
    _g = poly_inv(_g,_g.size());
    f = poly_ksm(f, m + 1,m+1);
    for(int i=0;i<=m;++i) {
        if(i==0)f[i]=(1-f[i]+mod)%mod;
        else f[i] = (-f[i]+mod)%mod;
    }
    f = poly_mul(f, _g);
    // for(int i=0;i<=m;++i) cout<<f[i]<<" ";
    //     cout<<endl;
    ll ans=0;
    for(int i=0;i<=m;++i)
    {
        ans=(ans+f[i]*C[i]%mod*qpow(n-i,k-i)%mod)%mod;
    }
    cout<<ans*qpow(qpow(n,k),mod-2)%mod<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
