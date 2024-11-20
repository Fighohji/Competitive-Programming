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

vector<int> e1[maxn], e2[maxn];
int sz1[maxn], sz2[maxn];
ull hs1[maxn], hs2[maxn];

bool vis[3000010];
int prime[3000010];//素数数量要>n
int cnt;
void isprime(int n)
{
    for(int i=2;i<=n;++i)
    {
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;++j)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int n;
bool oncir1[maxn], oncir2[maxn];
void dfs1(int u, int p)
{
    sz1[u] = 1;
    hs1[u] = 1;
    for (auto v : e1[u]) if (v != p && !oncir1[v]) {
        dfs1(v, u);
        sz1[u] += sz1[v];
        hs1[u] += hs1[v] * (ull)prime[sz1[v]] * 131ull;
    }
}

void dfs2(int u, int p)
{
    sz2[u] = 1;
    hs2[u] = 1;
    for (auto v : e2[u]) if (v != p && !oncir2[v]) {
        dfs2(v, u);
        sz2[u] += sz2[v];
        hs2[u] += hs2[v] * (ull)prime[sz2[v]] * 131ull;
    }
}

int deg1[maxn], deg2[maxn];
void topu1() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg1[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        oncir1[p] = 0;
        for (auto v : e1[p]) {
            deg1[p]--;
            deg1[v]--;
            if (deg1[v] == 1) {
                q.push(v);
            }
        }
    }
}
void topu2() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg2[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int p = q.front(); q.pop();
        oncir2[p] = 0;
        for (auto v : e2[p]) {
            deg2[p]--;
            deg2[v]--;
            if (deg2[v] == 1) {
                q.push(v);
            }
        }
    }
}

int minexpression(int len, vector<ull> s) {
    int minid = 0;
    for (int i = 1, k; i < len;) {
        for (k = 1; k <= len; ++k)
            if (s[(i+k-1) % len] != s[(minid + k - 1) % len])
                break;
        if (k > len) break;
        if (s[(i + k - 1) % len] < s[(minid + k - 1) % len]) {
            int tmp = i;
            i = max(minid + k, tmp + 1);
            minid = tmp;
        }
        else i += k;
    }
    return minid;
}

void solve(int cas) {
    isprime(3000000);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        oncir1[i] = 1;
        e1[u].eb(v); e1[v].eb(u);
        deg1[u]++; deg1[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        oncir2[i] = 1;
        e2[u].eb(v); e2[v].eb(u);
        deg2[u]++; deg2[v]++;
    }
    topu1(); topu2();
    vector<ull> tmp1, tmp2;
    for (int i = 1; i <= n; ++i) {
        if (oncir1[i]) {
            dfs1(i, 0);
            tmp1.eb(hs1[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (oncir2[i]) {
            dfs2(i, 0);
            tmp2.eb(hs2[i]);
        }
    }
    if (SZ(tmp1) != SZ(tmp2)) {
        cout << "No\n";
        return;
    }
    int len = SZ(tmp1);
    int id1 = minexpression(len, tmp1);
    int id2 = minexpression(len, tmp2);
    bool f1 = 1;
    for (int i = 0; i < len; ++i) {
        if (tmp1[(i + id1) % len] != tmp2[(i + id2) % len]) {
            f1 = 0;
            break;
        }
    }
    reverse(all(tmp1));
    id1 = minexpression(len, tmp1);
    bool f2 = 1;
    for (int i = 0; i < len; ++i) {
        if (tmp1[(i + id1) % len] != tmp2[(i + id2) % len]) {
            f2 = 0;
            break;
        }
    }
    if (f1 || f2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
