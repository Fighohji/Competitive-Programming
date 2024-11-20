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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct SAM {
    vector<vector<int> >nxt;//转移
    vector<int>len;//长度
    vector<int>link;//后缀链接
    vector<vector<int> >e;//后缀树
    vector<int>sz;//endpos集大小
    int last,cnt;//上一个状态和状态数总数
    void init(int strlen,int chrsize) {//字符串大小，字符集大小
        len.clear(); link.clear(); nxt.clear(); sz.clear(); e.clear();
        last = cnt = 1;//初始状态空集
        len.resize(1 + strlen << 1, 0);
        link.resize(1 + strlen << 1 , 0);
        nxt.resize(1 + strlen << 1, vector<int>(chrsize + 1, 0));
        // sz.resize(1 + strlen << 1, 0);
    }
    void add(string &s) {
        for (auto i : s)
            add(i - 'a');
    }
    void add(int c) {
        int p = last, cur = ++cnt;
        // sz[cur] = 1;
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
}sam;

struct SequenceAutoMachine {
    vector<vector<int> > nxt;
    // string s;
    void init(int n, int char_size, string &s) {
        nxt.resize(n + 5, vector<int>(char_size, INF));
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
    }
    bool find(string t) {// 子序列
        int p = -1, len_t = SZ(t);
        for (int i = 0; i < len_t; ++i) {
            p = nxt[p + 1][t[i] - 'a'];
            if (p == -1) return 0;
        }
        return 1;
    }
} sq;

string Ans;
vector<pii> seg;

void solve(int cas) {
    string s; cin >> s;
    Ans = "";
    seg.clear();
    int cnt = 0, n = s.length();
    int l = 0, r = 0;
    while (l < n && r < n) {
        while (r < n && s[r] == s[l]) r++;
        seg.eb(s[l] - 'a', r - l);
        cnt++;
        l = r;
    }
    cnt--;
    if (cnt < 2) {
        cout << "-1\n";
        return ;
    }
    sam.init(n, 26); sam.add(s);
    sq.init(n, 26, s);
    int p = 1;
    n--;
    for (int i = 0; i < 26; ++i) {
        if (sq.nxt[0][i] == INF || n - sq.nxt[0][i] < 2) continue;
        int pos = sq.nxt[0][i];
        p = sam.nxt[p][i];
        Ans += (char)(i + 'a');
        while (1) {
            bool flag = 0;
            if (n == pos + 2) {
                Ans += s[n];
                break;
            }
            for (int j = 0; j < 26; ++j) {
                if (sq.nxt[pos + 2][j] != INF && !sam.nxt[p][j]) {
                    Ans += (char)(j + 'a');
                    flag = 1;
                    break;
                } else if (sq.nxt[pos + 2][j] != INF) {
                    Ans += (char)(j + 'a');
                    p = sam.nxt[p][j];
                    pos++;
                    break;
                }
            }
            if (flag) break;
        }

        break;
    }
    cout << Ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

