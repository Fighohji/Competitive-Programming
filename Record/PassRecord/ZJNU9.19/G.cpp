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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

bitset<maxn>bg[1010];
int S = 300;
vector<pair<int,int>>v[maxn];
vector<int>bbg;
bitset<maxn>ans;
int idx[maxn];
int tot = 0;
bool vis[maxn], ck[maxn];
void solve() {
   int n, m; cin >> n >> m;
   for(int i = 1; i <= m; ++i)
   {
        int x, y;
        cin >> x >> y;
        v[x].push_back({y, i});
        v[y].push_back({x, i});
   }
   for(int i = 1; i <= n; ++i)
   {
        if(SZ(v[i]) > S)
        {
            idx[i] = ++tot;
            ck[i] = 1;
            bbg.push_back(i);
            for(auto [x, id]:v[i])
            {
                bg[tot].set(id);
            }
        }
   }
   int q;
   cin >> q;
   while(q--)
   {
        string s;
        cin >> s;
        if(s[0] != '?')
        {
            int x; cin >> x;
            if(ck[x])
            {
                ans ^= bg[idx[x]];
            }
            else
            {
                for(auto [y, id]:v[x])
                {
                    if(!vis[id]) ans.flip(id);
                }
            }
        }
        else
        {
            int x = ans._Find_first();
            if(x == ans.size())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << x << '\n';
            vis[x] = 1;
            ans[x] = 0;
            for(auto p:bbg)
            {
                bg[idx[p]].reset(x);
            }
        }
   }

}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
