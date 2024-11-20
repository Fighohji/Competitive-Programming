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

constexpr int N = 2e6 + 50;
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

bool vis[N];
int prime[N];
int cnt;
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

__int128 qpow(ll a, ll b)
{
    __int128 r = 1;
    __int128 a_ = a;
    while(b)
    {
        if(b & 1) r = r * a_;
        a_ = a_ * a_;
        b >>= 1;
    }
    return r;
}
#define int long long
void solve() {
    // cout << 9088ll * 9088 * 9088ll - 666ll * 666 * 666ll << '\n';
    // cout << 740ll * 740 * 740ll - 74ll * 74 * 74ll << '\n';
    int n, k;
    cin >> n >> k;
    int tmp = n;
    if(k >= 4)
    {
        int L = pow(n, 1.0 / k);
        int Ans = 0;
        for(int a = max(L - 1, 1ll), b = 1; ; a++)
        {
            if(qpow(a, k) - qpow(a - 1, k) > n) break;
            while(qpow(a, k) - qpow(b, k) > n) b++;
            if(qpow(a, k) - qpow(b, k) == n) Ans++;
        }
        cout << Ans << '\n';
        return ;
    }
    vector<pii> p;
    for (int i = 1; prime[i] <= n && i <= cnt; ++i) {
        int c = 0;
        while (n % prime[i] == 0) {
            c++;
            n /= prime[i];
        }
        if (c) p.push_back({prime[i], c});
    }
    // if(n != 1) p.push_back({n, 1});
    int m = p.size();
    int Ans = 0;
    n = tmp;
    // cout << " p ";
    // for(auto x : p) cout << x.first << ' ' << x.second << '\n';
    // cout << '\n';

    auto ck = [&](int det) -> int
    {
        __int128 d2 = (__int128)3 * det * (4 * n - (__int128)det * det * det);
        // if(det == 222) cout << "()()()()() " << (ll)d2 << '\n';
        if(d2 < 0) return 0;
        __int128 rd = sqrtl(d2);
        while(rd * rd <= d2) rd++;
        while(rd * rd > d2) rd--;
        if(rd * rd != d2) return 0;
        __int128 b_ = ((__int128)(-3) * det * det + rd) / (6 * det);
        __int128 a_ = b_ + det;
        int ans = 0;
        // cerr << "!! " << (ll)a_ << ' ' << (ll)b_ << '\n';
        if(a_ * a_ * a_ - b_ * b_ * b_ == n && b_ > 0) ans++;
        return ans;
    };
    // cout << m << '\n';
    auto dfs = [&](auto self, int x, int v) -> void
    {
        // cerr << x << ' ' << v << '\n';
        if(x == m)
        {
            // cout << v << '\n';
            Ans += ck(v);
            return ;
        }
        self(self, x + 1, v);
        for(int i = 1; i <= p[x].second; ++i)
        {
            if(v > 1000000 / p[x].first)
                break;
            v = v * p[x].first;
            self(self, x + 1, v);
        }
    };
    dfs(dfs, 0, 1);
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    isprime(2000000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}

