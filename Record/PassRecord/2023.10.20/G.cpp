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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


bool V[maxn];
int prime[maxn];//素数数量要>n
int cnt;
void isprime(int n)
{
    for(int i=2;i<=n;++i)
    {
        if(!V[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;++j)
        {
            V[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

struct Hash1 {
    ll seed = 131, p = 998244853;
    ll hash[maxn], power[maxn];
    void init(vector<ull> &s) {
        power[0] = 1;
        for (int i = 1; i <= SZ(s); ++i) {
            hash[i] = (hash[i - 1] * seed % p + (ll)(s[i - 1]) % p) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ll get_hash(int l, int r) {
        l++, r++;
        ll a = hash[r];
        ll b = hash[l - 1] * power[r - l + 1] % p;
        return (a - b + p) % p;
    }
} hs1, hs11;

struct Hash2 {
    ull seed = 487;
    ull hash[maxn], power[maxn];
    void init(vector<ull> &s) {
        power[0] = 1;
        for (int i = 1; i <= SZ(s); ++i) {
            hash[i] = hash[i - 1] * seed + s[i - 1];
            power[i] = power[i - 1] * seed;
        }
    }
    ull get_hash(int l, int r) {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1];
        return a - b;
    }
} hs2, hs22;
void solve() {
    int n, m; cin >> n >> m;
    vector G(n + 1, vector<int>());
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        G[u].pb(v); G[v].pb(u);
        deg[u]++; deg[v]++;
    }
    if (n <= 3 || m == n - 1) {
        cout << "YES\n";
        return ;
    }
    if (m > n) {
        cout << "NO\n";
        return ;
    }
    //找环
    vector<bool> onCir(n + 1, 1);
    vector<int> cir;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        onCir[p] = 0;
        deg[p]--;
        for (auto v : G[p]) {
            deg[v]--;
            if (deg[v] == 1)
                q.push(v);
        }
    }

    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (onCir[i]) {
            int now = i;
            while (!vis[now]) {
                cir.pb(now);
                vis[now] = 1;
                for (auto v: G[now]) {
                    if (onCir[v] && !vis[v]) {
                        now = v;
                        break;
                    }
                }
            }
            break;
        }
    }

    vector<int> sz(n + 1, 1);
    vector<ull> hs(n + 1, 1);
    auto treeHash = [&](auto &&treeHash, int u, int p) -> void {
        for (auto v : G[u]) {
            if (v == p || onCir[v]) continue;
            treeHash(treeHash, v, u);
            sz[u] += sz[v];
            hs[u] += hs[v] * (ull)prime[sz[v]] * 233ull;
        }
    };
    vector<ull> cirHs;
    set<ull> num;
    for (auto i : cir) {
        treeHash(treeHash, i, 0);
        cirHs.pb(hs[i]);
        num.insert(hs[i]);
    }
    if (SZ(cir) % 2 == 1) {
        if (SZ(num) >= 2) cout << "NO\n";
        else cout << "YES\n";
    } else {
        if (SZ(num) > 2) {
            cout << "NO\n";
        } else if (SZ(num) == 1) {
            cout << "YES\n";
        } else {
            for (int i = 0; i < SZ(cirHs); ++i) {
                if (cirHs[i] == cirHs[(i + 1) % SZ(cirHs)]) {
                    cout << "NO\n";
                    return ;
                }
            }
            cout << "YES\n";
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    isprime(1.5e6);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
