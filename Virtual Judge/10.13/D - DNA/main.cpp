#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

char tr[500];
struct SAM {
    vector<vector<int>> nxt;           // 转移
    vector<int> len;                   // 长度
    vector<int> link;                  // 后缀链接
    int last, cnt;                     // 上一个状态和状态数总数
    void init(int strlen, int chrsize) // 字符串大小，字符集大小
    {
        last = cnt = 1; // 初始状态空集
        len.resize((1 + strlen) << 1, 0);
        link.resize((1 + strlen) << 1, 0);
        nxt.resize((1 + strlen) << 1, vector<int>(chrsize, 0));
    }
    void add(const string &s) {
        for (auto i : s)
            add(i - 'A');
    }
    void add(int c) {
        int p = last, cur = ++cnt;
        len[cur] = len[p] + 1;
        // 情况2 直接扩展
        while (p && !nxt[p][c]) {
            nxt[p][c] = cur;
            p = link[p];
        }
        last = cur;
        if (!p)
            link[cur] = 1;
        else {
            int q = nxt[p][c];
            // 情况3-A 建立新的后缀链接
            if (len[q] == len[p] + 1) link[cur] = q;
            // 情况3-B 拆点建立
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
    tr['A'] = 'T';
    tr['C'] = 'G';
    tr['T'] = 'A';
    tr['G'] = 'C';
    string s;
    cin >> s;
    int n = s.length();
    string t = s;
    for (int i = 0; i < n; ++i) {
        t[i] = tr[s[i]];
    }
    reverse(all(t));
    string Ans;
    int len = 0, res = 0;
    sam.init(n, 26);
    sam.add(t);
    int p = 1, k = 0;
    for (int j = 0; j < n; ++j) {
        char i = s[j];
        while (p && !sam.nxt[p][i - 'A']) {
            p = sam.link[p];
            res = sam.len[p];
        }
        if (sam.nxt[p][i - 'A']) {
            res++;
            p = sam.nxt[p][i - 'A'];
        }
        if (res > len) {
            len = res;
            k = j; 
        }
    }
    cout << len << '\n';
    if (len) {
        cout << s.substr(k - len + 1, len);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
