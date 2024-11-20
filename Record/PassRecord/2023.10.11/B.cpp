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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int sg[N];

void dfs(int x)
{
    if(sg[x] != -1) return ;
    int p = sqrtl(x);
    if(p * p == x)
    {
        vector<int> vis(p + 2);
        for(int k = 1; k <= p; ++k)
        {
            dfs(p * p - k * p);
            int y = sg[p * p - k * p];
            if(y > p) continue;
            vis[y] = 1;
        }
        for(int i = 0; i <= p + 1; ++i)
        {
            if(!vis[i])
            {
                sg[x] = i;
                return ;
            }
        }
        return ;
    }
    if(sg[p * p + 1] != -1)
    {
        sg[x] = sg[p * p + 1];
        return ;
    }
    vector<int> vis(p + 3);
    for(int k = 0; k <= p; ++k)
    {
        dfs(p * p - k * p);
        int y = sg[p * p - k * p];
        if(y > p) continue;
        vis[y] = 1;
    }
    for(int i = 0; i <= p + 2; ++i)
    {
        if(!vis[i])
        {
            sg[x] = i;
            sg[p * p + 1] = i;
            return ;
        }
    }

}
void solve() {
    int n; cin >> n;
    memset(sg, -1, sizeof(sg));
    sg[0] = 0;
    sg[1] = 1;
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x; dfs(x);
        ans ^= sg[x];
    }
    if(ans) cout << "First\n";
    else cout << "Second\n";
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
