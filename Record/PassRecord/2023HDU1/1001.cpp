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
constexpr int maxn = 3e3 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};



// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
vector<int> e[maxn];
int fa[maxn][15], dep[maxn];
void dfs(int u, int p) {
    fa[u][0] = p;
    dep[u] = dep[p] + 1;
    for (auto v : e[u])
        if (v != p)
            dfs(v, u);
}
void init_lca(int n) {
    for (int j = 1; j < 15; ++j)
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
}
int get_lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 14; i >= 0; --i)
        if (dep[v] - dep[u] >= (1 << i))
            v = fa[v][i];
    if (u == v) return u;
    for (int i = 14; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int pre[maxn];
void DFS(int u, int p) {
    for (auto v : e[u]) {
        if (v == p) continue;
        DFS(v, u);
        pre[u] += pre[v];
    }
}

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll g = ex_gcd(b, a%b, x, y);
    int tmp = x; x = y; y = tmp - a / b * y;
    return g;
}

bool gt(ll len1,ll len2,ll val)
{
        ll x,y;
        ll Gcd=ex_gcd(len1*2,len2*2,x,y);
        if((val)%Gcd)
        {
            return 0;
        }
        return 1;
        Gcd=val/Gcd;
        ll mo1=2*len2,mo2=2*len1;
        x=(x*Gcd%(mo1)+mo1)%mo1;
        y=(y*Gcd%mo2+mo2)%mo2;
        if(x>=0&&y>=0)
        {
            // ->;
            return 1;            // break;
        }
        return 0;
}

void solve(int cas) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        e[u].eb(v); e[v].eb(u);
    }
    dfs(1, 0); init_lca(n);
    while (m--) {
        int sa, ta, sb, tb; cin >> sa >> ta >> sb >> tb;
        int lcaa = get_lca(sa, ta);
        int lcab = get_lca(sb, tb);
        memset(pre, 0, sizeof pre);
        pre[sa]++; pre[ta]++; pre[lcaa]--; pre[fa[lcaa][0]]--;
        pre[sb]++; pre[tb]++; pre[lcab]--; pre[fa[lcab][0]]--;
        vector<int> linkapre, linkasuf, linkbpre, linkbsuf, linkpre, linksuf;
        auto get_link = [&](int now, vector<int> &link, int lim) {
            while (now != lim) {
                link.pb(now);
                now = fa[now][0];
            }
        };
        get_link(sa, linkapre, lcaa);
        get_link(ta, linkasuf, lcaa);
        get_link(tb, linkbsuf, lcab);
        get_link(sb, linkbpre, lcab);
        vector<int> linka, linkb, linktot, linkrev;
        for (int i = 0; i < SZ(linkapre); ++i) {
            linka.pb(linkapre[i]);
        }
        linka.pb(lcaa);
        for (int i = SZ(linkasuf) - 1; i >= 0; --i) {
            linka.pb(linkasuf[i]);
        }
        for (int i = 0; i < SZ(linkbpre); ++i) {
            linkb.pb(linkbpre[i]);
        }
        linkb.pb(lcaa);
        for (int i = SZ(linkbsuf) - 1; i >= 0; --i) {
            linkb.pb(linkbsuf[i]);
        }
        for (auto i : linka) {
            if (pre[i] == 2) {
                linktot.pb(i);
            }
        }
        for (auto i : linkb) {
            if (pre[i] == 2) {
                linkrev.pb(i);
            }
        }
        if (SZ(linktot) == 0) {
            cout << "-1\n";
            continue;
        }
        int a1=0,a2=linka.size(),b1=0,b2=linkb.size();
        ll cn=0;
        ll len1=a2,len2=b2;
        ll fl=0;
        for(auto pos:linktot)
        {
            a1++;a2++;b1++;b2++;
            if(gt(len1,len2,b1-a1))
            {
                cout<<pos<<endl;
                fl=1;
                break;
            }
            if(gt(len1,len2,b1-a1))
            {
                cout<<pos<<endl;
                fl=1;
                break;
            }
            if(gt(len1,len2,b1-2*len2+a1))
            {
                cout<<pos<<endl;
                fl=1;
                break;
            }
            if(gt(len1,len2,2*len2-b1-2*len1+a1))
            {
                cout<<pos<<endl;
                fl=1;
                break;
            }
            cn++;
        }
        if(fl==0)
            {
                cout<<-1<<endl;
                continue;
            }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
