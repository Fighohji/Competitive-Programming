#include <bits/stdc++.h>
#define db double
#define il inline
#define fir first
#define sec second
#define eps (1e-10)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define pid pair<int, double>
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define GG { cout << "NO\n"; return; }
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)
using namespace std;


static const int ON = 0;
static const int CW = -1;
static const int CCW = 1;
static const int BACK = 2;
static const int FRONT = -2;
static const int maxn = 1e6 + 100;
static const db pi = acos(-1.000);
static const int INF = 0x3f3f3f3f;
static const ll LINF =  0x3f3f3f3f3f3f3f3f;
static const int mod = 998244353; /* 1e9 + 7 */
static const int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool vis[maxn * 3];
int prime[maxn * 3];
int cnt;
il void isprime(int n)
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
il int minexpression(int len,ull *s)
{
    int minid=0;
    for(int i=1,k;i<len;)
    {
        for(k=1;k<=len;++k)if(s[(i+k-1)%len]!=s[(minid+k-1)%len])break;
        if(k>len)break;
        if(s[(i+k-1)%len]<s[(minid+k-1)%len])
        {
            int tmp=i;
            i=max(minid+k,tmp+1);
            minid=tmp;
        }
        else i+=k;
    }
    return minid;
}

int n;
vector<int> e1[maxn], e2[maxn];
ull hs1[maxn], hs2[maxn];
bool oncir1[maxn], oncir2[maxn];
vector<int> cir1, cir2;
int deg1[maxn], deg2[maxn];

void topu1()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg1[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        deg1[u]--;
        for (auto v : e1[u]) {
            if (deg1[v]) deg1[v]--;
            if (deg1[v] == 1) q.push(v);
        }
    }

    int pos;
    for (int i = 1; i <= n; ++i) if (deg1[i]) {
        pos = i;
        break;
    }

    int k = pos;
    cir1.pb(k); oncir1[k] = 1;
    while (1) {
        bool flag = 0;
        for (auto v : e1[k]) {
            if (deg1[v] && !oncir1[v]) {
                k = v;
                flag = 1;
                break;
            }
        }
        if (!flag) break;
        cir1.pb(k); oncir1[k] = 1;
    }
}

void topu2()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (deg2[i] == 1) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        deg2[u]--;
        for (auto v : e2[u]) {
            if (deg2[v]) deg2[v]--;
            if (deg2[v] == 1) q.push(v);
        }
    }

    int pos;
    for (int i = 1; i <= n; ++i) if (deg2[i]) {
        pos = i;
        break;
    }

    int k = pos;
    cir2.pb(k); oncir2[k] = 1;
    while (1) {
        bool flag = 0;
        for (auto v : e2[k]) {
            if (deg2[v] && !oncir2[v]) {
                k = v;
                flag = 1;
                break;
            }
        }
        if (!flag) break;
        cir2.pb(k); oncir2[k] = 1;
    }
}
int sz1[maxn], sz2[maxn];
void dfs1(int u, int p) 
{
    sz1[u] = 1;
    for (auto v : e1[u]) if (v != p && !oncir1[v]) {
        dfs1(v, u);
        sz1[u] += sz1[v];
        hs1[u] += hs1[v] * (ull)prime[sz1[v]] * 131ull;
    }
}
void dfs2(int u, int p) 
{
    sz2[u] = 1;
    for (auto v : e2[u]) if (v != p && !oncir2[v]) {
        dfs2(v, u);
        sz2[u] += sz2[v];
        hs2[u] += hs2[v] * (ull)prime[sz2[v]] * 131ull;
    }
}
ull tmp1[maxn], tmp2[maxn], tmp3[maxn];

struct Hash
{
    ull seed = 131, p;
    ull hash[maxn], power[maxn];
    void init(ull *s, int len, ull P = UINT64_MAX)
    {
        p = P;
        power[0] = 1;
        for (int i = 1; i <= len; ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ull get_hash(int l, int r)
    {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1] % p;
        return (a - b + p) % p;
    }
};

void solve(int cas)
{
    isprime(2.8e6);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        e1[u].pb(v); e1[v].pb(u);
        deg1[u]++, deg1[v]++;
        hs1[i] = hs2[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        int u, v; cin >> u >> v;
        e2[u].pb(v); e2[v].pb(u);
        deg2[u]++, deg2[v]++;
    }
    topu1(); topu2();
    int cnt1 = 0, cnt2 = 0;
    for (auto u : cir1) {
        dfs1(u, 0);
        tmp1[cnt1++] = hs1[u];
    }
    for (auto u : cir2) {
        dfs2(u, 0);
        tmp2[cnt2++] = hs2[u];
    }
    if (cnt1 != cnt2) {
        cout << "No\n";
        return ;
    }
    for (int i = 0; i < cnt1; ++i) tmp3[i] = tmp2[cnt1 - i - 1];
    int id1 = minexpression(cnt1, tmp1);
    int id2 = minexpression(cnt2, tmp2);
    int id3 = minexpression(cnt1, tmp3);
    bool f1 = 1, f2 = 1;
    for (int i = 0; i < cnt1; ++i) {
        if (tmp1[(id1 + i) % cnt1] != tmp2[(id2 + i) % cnt2]) {
            f1 = 0;
        }
        if (tmp1[(id1 + i) % cnt1] != tmp3[(id3 + i) % cnt1]) {
            f2 = 0;
        }
    }
    if (f1 || f2) cout << "Yes\n";
    else cout << "No\n";
}   



int main(int argc, char *argv[])
{
    // cout << fixed << setprecision(10);
    // srand(time(0));
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // init();
    // int T; cin>>T; while (T--) solve(1);
    // for (int i = 1; i <= T; ++i) solve(i);
    solve(1);
    return 0;
}
