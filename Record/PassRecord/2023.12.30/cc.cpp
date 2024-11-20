
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


void print(__int128 t) {
    // if (!t) return ;
    // ++cnt;
    if(t > 9) print(t / 10);
    cout << (int)(t % 10);
}
void println(__int128 t)
{
    print(t);
    cout << '\n';
}
/*
4
12345678 0
12345678 5
12345678 18
990099 5

1
999999999999999999 0

1
123 1
*/

__int128 dp[40][20][2];
__int128 fw[40];
void solve() {
    string s; cin >> s;
    int k; cin >> k;

    if(!k)
    {
        int len = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; --i, len++)
        {
            // cout << len << ' ' << s[i] << '\n';
            if(s[i] != '9') break;
        }
        println(fw[len]);
        return ;
    }
    int top = 0;
    while(s.back() == '0')
    {
        s.pop_back(); top++;
    }
    int n = s.size();
    reverse(s.begin(), s.end());
    s = '~' + s;
    int maxlen = 30;
    for(int i = n + 1; i <= maxlen; ++i) s += '0';
    // cerr << s << '\n';
    // cout << s.size() << '\n';
        // cout << s << " is\n";
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 1; i <= maxlen; ++i)
    {
        for(int j = 0; j <= k; ++j)
        {
            dp[i][j][0] = dp[i - 1][j][0];
            if(s[i] != '9')
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
            }
            if(j >= 1)
            {
                int nd = '9' - s[i];
                dp[i][j][1] = min(dp[i][j][1], nd * fw[i - 1] + dp[i - 1][j - 1][1]);
                nd++;
                if(s[i] != '0') dp[i][j][1] = min(dp[i][j][1], nd * fw[i - 1] + dp[i - 1][j - 1][0]);
            }
            // cout << i << ' ' << j << ' ';
            // println(dp[i][j][0]);
        }
        // cout << i << ' ';
        // println(dp[i][1][0]);
    }
    __int128 ans = min(fw[maxlen] + dp[maxlen][k][1], dp[maxlen][k][0]);
    print(ans);
    while(top--) cout << 0;
    cout << '\n';
}

void init()
{
    fw[0] = 1;
    for(int i = 1; i <= 30; ++i) fw[i] = fw[i - 1] * 10;
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);

    init();
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
