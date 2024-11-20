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

string s, t;

struct SAM {
    vector<vector<int> >nxt;//转移
    vector<int>len;//长度
    vector<int>link;//后缀链接
    int last,cnt;//上一个状态和状态数总数
    vector<vector<ll>> cnt1;
    vector<ll> cnt2, id;
    void init(int strlen,int chrsize) {//字符串大小，字符集大小
        len.clear(); link.clear(); nxt.clear();
        last = cnt = 1;//初始状态空集
        len.resize(1 + strlen << 1, 0);
        link.resize(1 + strlen << 1 , 0);
        nxt.resize(1 + strlen << 1, vector<int>(chrsize + 1, 0));
        cnt1.resize(strlen, vector<ll>(26));
        cnt2.resize(strlen);
        id.resize(strlen);
    }
    void add(int c, int pos) {
        int p = last, cur = ++cnt;
        id[pos] = cur;
        len[cur] = len[p] + 1;
        //情况1 直接扩展
        while(p&&!nxt[p][c]) {
            nxt[p][c] = cur;
            p = link[p];
        }
        last = cur;
        if (!p) link[cur] = 1;
        else {
            int q = nxt[p][c];
            //情况2-A 建立新的后缀链接
            if (len[q] == len[p] + 1) link[cur] = q;
            //情况2-B 拆点建立
            else {
                int cl = ++cnt;
                len[cl] = len[p] + 1;
                nxt[cl] = nxt[q], link[cl] = link[q];
                link[cur] = link[q] = cl;
                while (p && nxt[p][c] == q) {
                    nxt[p][c] = cl;
                    p = link[p];
                }
            }
        }
    }
    void count(int n) {
        vector<bool> vis(cnt + 1);
        vis[1] = 1;
        for (int i = 0; i < n; ++i) {
            if (i) cnt2[i] = cnt2[i - 1];
            if (i) cnt1[i] = cnt1[i - 1];
            int now = id[i];
            do {
                vis[now] = 1;
                cnt1[i][s[i] - 'a'] += len[now] - len[link[now]];
                cnt2[i] += len[now] - len[link[now]];
                now = link[now];
            } while(!vis[now]);
        }
    }
} sam;
/*
3 2
aab
bc
*/

void solve() {
    int n, m; cin >> n >> m;
    cin >> s >> t;
    sam.init(n, 26);
    for (int i = 0; i < n; ++i)
        sam.add(s[i] - 'a', i);
    sam.count(n);
    ll ans = 0;
    // for (int i = 0; i < n; ++i)
    //     cout << sam.cnt2[i] << ' ';
    // cout << '\n';
    // for (int j = 0; j < n; ++j) {
    //     for (int i = 0; i < 3; ++i) {
    //         cout << sam.cnt1[j][i] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    for (int k = 0; k < m; ++k) {
        if (m - k > n) continue;
        int j = n - (m - k);
        ans += sam.cnt2[j];
        if (k) ans -= sam.cnt1[j][t[k - 1] - 'a'];
    }
    vector<int> early(26, n);
    for (int i = 0; i < n; ++i) {
        early[s[i] - 'a'] = min(early[s[i] - 'a'], i);
    }
    // cout << ans << '\n';
    for (int i = 1; i < m; ++i) {
        if (n - early[t[i - 1] - 'a'] >= m - i)
            ans++;
    }
    cout << ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
