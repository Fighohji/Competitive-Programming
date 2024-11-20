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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

ll dis[2010][2010];
int sz[2010], old[2010];
pii a[2010];
bool cmp(pll a, pll b) // a < b
{
    return (__int128)a.fir * b.sec < (__int128)b.fir * a.sec;
}
void solve() {
    int n; cin >> n;
    vector<int> id(n);
    for(int i = 1; i <= n; ++i) id[i - 1] = i, old[i] = n - i + 1;
    for(int i = 1; i <= n; ++i) sz[i] = 1;
    for(int i = 1; i <= n; ++i) cin >> a[i].fir >> a[i].sec;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            dis[i][j] = (a[i].fir - a[j].fir) * (a[i].fir - a[j].fir) + (a[i].sec - a[j].sec) * (a[i].sec - a[j].sec);
        }
    }
    for(int i = 1; i < n; ++i)
    {
        int ansi = -1, ansj = -1;
        int p;
        pll anstmp;
        pii tmp;
        for(int j = 0; j < id.size(); ++j)
        {
            for(int k = j + 1; k < id.size(); ++k)
            {
                if(ansi == -1)
                {
                    ansi = id[j], ansj = id[k];
                    p = j;
                    tmp = mkp(max(old[ansi], old[ansj]), min(old[ansi], old[ansj]));
                    anstmp = mkp(dis[ansi][ansj], 1);
                }
                else
                {
                    int ti = id[j], tj = id[k];
                    pii rtmp =  mkp(max(old[ti], old[tj]), min(old[ti], old[tj]));
                    pll t = mkp(dis[ti][tj], 1ll * sz[ti] * sz[tj]);
                    if(cmp(t, anstmp) || (!cmp(anstmp, t) && rtmp > tmp))
                    {
                        p = j;
                        ansi = ti, ansj = tj;
                        tmp = rtmp;
                        anstmp = t;
                    }
                }
            }

        }
        //ansi ansj'
        sz[ansi] += sz[ansj];
        old[ansi] = n + i;
        cout << sz[ansi] << '\n';
        // cout << ansi << ' ' << ansj << '\n';
        for(int j = 0; j < id.size(); ++j)
        {
            if(id[j] != ansi && id[j] != ansj)
            {
                dis[id[j]][ansi] += dis[id[j]][ansj];
                dis[ansi][id[j]] += dis[ansj][id[j]];
            }
        }
        for(int j = 0; j < id.size(); ++j)
        {
            if(id[j] == ansj)
            {
                for(int k = j; k + 1 < id.size(); ++k)
                {
                    id[k] = id[k + 1];
                }
                id.resize(n - i);
                break;
            }
        }
        // cout << "id ";
        // for(auto x:id) cout << x << ' ';
        // cout << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
