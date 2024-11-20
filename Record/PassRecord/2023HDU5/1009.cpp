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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

namespace FastIOT
{
    const int bsz=1<<18;
    char bf[bsz],*head,*tail;
    inline char gc(){if(head==tail)tail=(head=bf)+fread(bf,1,bsz,stdin);if(head==tail)return 0;return *head++;}
    template<typename T>inline void read(T &x){T f=1;x=0;char c=gc();for(;c>'9'||c<'0';c=gc())if(c=='-')f=-1;
    for(;c<='9'&&c>='0';c=gc())x=(x<<3)+(x<<1)+(c^48);x*=f;}
    template<typename T>inline void print(T &x){if(x<0)putchar(45),x=-x;if(x>9)print(x/10);puchar(x%10+48);}
    template<typename T>inline void println(T &x){print(x);putchar('\n');}
}
using namespace FastIOT;


bool BEGIN;
vector<int> e[maxn], G[maxn];
int son[maxn];
int f[maxn], dep[maxn];
bool vis[maxn], VIS[maxn];
int sz[maxn];
void DFS(int u, int p) {
    if (son[u]) {
        vis[p] = 1;
        VIS[son[u]] = VIS[u] = 1;
        sz[p]++;
        G[p].eb(son[u]);
        DFS(son[u], p);
    }
    for (auto v : e[u]) {
        if (v == son[u]) continue;
        G[u].eb(v);
        DFS(v, u);
    }
}
int redfs(int u) {
    dep[u] = 1;
    int tmp = 0;
    for (int v : G[u]) {
        if (VIS[v]) {
            dep[u] = max(dep[u], redfs(v));
        } else {
           tmp = max(tmp, redfs(v) + 1);
        }
    }
    // printf("%d %d %d %d\n", u, dep[u], tmp, max(tmp, dep[u] + f[sz[u]]));
    return dep[u] = max(tmp, dep[u] + f[sz[u]]);
}
void solve(int cas) {
    int n; read(n);
    for (int i = 0; i <= n; ++i) {
        e[i].clear();
        VIS[i] = vis[i] = dep[i] = sz[i] = 0;
        G[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        int p; read(p);
        if (!p) son[p] = i;
        e[p].eb(i);
    }
    for (int i = 1; i <= n; ++i) {
        read(son[i]);
    }
    DFS(0, 0);
    for (int i = 1; i <= n; ++i) {
        if (sz[i]) sz[i]++;
        // printf("%d %d\n", i, VIS[i]);
    }
    printf("%d\n", redfs(0) - 1);
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    freopen("1009.in", "r", stdin);
    freopen("ans.out", "w", stdout);
     int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i <= 1000000; ++i) f[i] = f[(i + 1) / 2] + 1;
    // for (int i = 1; i <= 18; ++i) {
    //     cout << i << ' ' << f[i] << '\n';
    // }
    int T; read(T); while (T--)
    solve(1);
    fclose(stdin);
    fclose(stdout);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    exit(0);
}
