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

struct SAM {
    vector<vector<int> >nxt;//转移
    vector<int>len;//长度
    vector<int>link;//后缀链接
    int last,cnt;//上一个状态和状态数总数
    void init(int strlen,int chrsize) {//字符串大小，字符集大小
        len.clear(); link.clear(); nxt.clear();
        last = cnt = 1;//初始状态空集
        len.resize(1 + strlen << 1, 0);
        link.resize(1 + strlen << 1 , 0);
        nxt.resize(1 + strlen << 1, vector<int>(chrsize + 1, 0));
    }
    void add(string s) {
        for (auto i : s)
            add(i - 'a');
    }
    void add(int c) {
        int p = last, cur = ++cnt;
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
} sam;


void solve() {
    int n; cin >> n;
    ll ans = 0;
    sam.init(2000000, 26);
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        if (i != 1) {
            int now = 1, mx = 0;
            int Max = 0;
            for (auto j : s) {
                while (now != 1 && !sam.nxt[now][j - 'a']) {
                    now = sam.link[now];
                    mx = sam.len[now];
                }
                if (sam.nxt[now][j - 'a']) {
                    now = sam.nxt[now][j - 'a'];
                    mx++;
                }
                Max = max(Max, mx);
            }
            ans += Max;
        }
        sam.add(s);
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
