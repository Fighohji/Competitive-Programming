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
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
// constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
// #define int long long
ll mod = 1e18;
ll qpow(ll base, ll p, ll mod){
    int res;
    for (res = 1; p; p >>= 1, base = static_cast<long long> (base) * base % mod) if (p & 1) res = static_cast<long long> (res) * base % mod;
    return res;
}
ll inv(int x, const int mod) { return qpow(x, mod - 2, mod); }


const ll mod1 = 998244353, mod2 = 1004535809, mod3 = 469762049, G = 3;

const long long mod_1_2 = 1ll * mod1 * mod2;

const ll inv_1 = inv(mod1, mod2), inv_2 = inv(mod_1_2 % mod3, mod3);

struct Int {
    ll A, B, C;
    Int() { }
    Int(ll __num) : A(__num), B(__num), C(__num) { }
    Int(ll __A, ll __B, ll __C) : A(__A), B(__B), C(__C) { }

    static inline Int reduce(const Int &x) {
        return Int(x.A + (x.A >> 31 & mod1), x.B + (x.B >> 31 & mod2), x.C + (x.C >> 31 & mod3));
    }
    inline friend Int operator + (const Int &lhs, const Int &rhs) {
        return reduce(Int(lhs.A + rhs.A - mod1, lhs.B + rhs.B - mod2, lhs.C + rhs.C - mod3));
    }
    inline friend Int operator - (const Int &lhs, const Int &rhs) {
        return reduce(Int(lhs.A - rhs.A, lhs.B - rhs.B, lhs.C - rhs.C));
    }
    inline friend Int operator * (const Int &lhs, const Int &rhs) {
        return Int(static_cast<long long> (lhs.A) * rhs.A % mod1, static_cast<long long> (lhs.B) * rhs.B % mod2, static_cast<long long> (lhs.C) * rhs.C % mod3);
    }

    inline ll get() {
        long long x = 1ll * (B - A + mod2) % mod2 * inv_1 % mod2 * mod1 + A;
        return (1ll * (C - x % mod3 + mod3) % mod3 * inv_2 % mod3 * (mod_1_2 % mod) % mod + x) % mod;
    }
} ;


namespace Poly {
    int lim, s, rev[N];
    Int Wn[N | 1];
    inline void init(int n) {
        s = -1, lim = 1; while (lim < n) lim <<= 1, ++s;
        for (int i = 1; i < lim; ++i) rev[i] = rev[i >> 1] >> 1 | (i & 1) << s;
        const Int t(qpow(G, (mod1 - 1) / lim, mod1), qpow(G, (mod2 - 1) / lim, mod2), qpow(G, (mod3 - 1) / lim, mod3));
        *Wn = Int(1); for (Int *i = Wn; i != Wn + lim; ++i) *(i + 1) = *i * t;
    }
    inline void NTT(Int *A, const int op = 1) {
        for (int i = 1; i < lim; ++i) if (i < rev[i]) std::swap(A[i], A[rev[i]]);
        for (int mid = 1; mid < lim; mid <<= 1) {
            const int t = lim / mid >> 1;
            for (int i = 0; i < lim; i += mid << 1) {
                for (int j = 0; j < mid; ++j) {
                    const Int W = op ? Wn[t * j] : Wn[lim - t * j];
                    const Int X = A[i + j], Y = A[i + j + mid] * W;
                    A[i + j] = X + Y, A[i + j + mid] = X - Y;
                }
            }
        }
        if (!op) {
            const Int ilim(inv(lim, mod1), inv(lim, mod2), inv(lim, mod3));
            for (Int *i = A; i != A + lim; ++i) *i = (*i) * ilim;
        }
    }
}

int n,cnt,q;
int mas[N];
bool vis[N];
vector<int> vt[N];
int E[N];
void dfs(int id)
{
    if(vis[id]) return;
    vt[cnt].push_back(id);
    vis[id]=1;
    dfs(E[id]);
}
Int a[N], b[N];
unordered_map<ll, vector<ll>>mp;
void add(vector<ll> &a,const vector<ll> &b)
{
    for(int i=0;i<a.size();++i) a[i]+=b[i];
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
    Poly::init(3 * n);
    // if(n>=5e4)return ;
    for(int i=1;i<=cnt;++i)
    {
        // vector<Int> a,b;
        int size=vt[i].size();
        int c1 = 0;
        for(auto s:vt[i]) a[c1++] = Int(s);
        for(auto s:vt[i]) a[c1++] = Int(s);
        c1 = size - 1;
        for(auto s:vt[i]) b[c1--] = Int(s);
        // reverse(b.begin(),b.end());
            // cerr << 1 << '\n';

        // cerr << 2 << '\n';
        Poly::NTT(a); Poly::NTT(b);
        // cerr << 3 << '\n';
        for(int j = 0; j < Poly::lim; ++j) a[j] = a[j] * b[j];
        Poly::NTT(a, 0);
        vector<ll> ans;
        for(int j = 0; j < Poly::lim; ++j) ans.push_back(a[j].get());
        for(int j = 0; j < Poly::lim; ++j) a[j] = b[j] = 0;
        // cout<<i<<endl;
        // for(auto s:ans) cout<<s<<' ';
        //     cout<<endl;
        // cerr << "ook\n";
        if(mp.count(size)==0) mp[size]=ans;
        else add(mp[size],ans);
        // cerr << "ok\n";
    }

    int val;
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
