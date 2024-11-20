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

struct SAM {
    vector<vector<int>> nxt, e;
    vector<int> len, link, sz;
    int last, cnt;
    void init(int strlen, int chrsize) {
        last = cnt = 1;
        len.resize((1 + strlen) << 1, 0);
        link.resize((1 + strlen) << 1, 0);
        nxt.resize((1 + strlen) << 1, vector<int>(chrsize + 1, 0));
        sz.resize((1 + strlen) << 1, 0);
        e.resize((1 + strlen) << 1);
    }
    void add(const string &s) {
        for (auto i : s)
            add(i - 'a');
    }
    void add(int c) {
        int p = last, cur = ++cnt;
        sz[cur] = 1;
        len[cur] = len[p] + 1;
        while (p && !nxt[p][c]) {
            nxt[p][c] = cur;
            p = link[p];
        }
        last = cur;
        if (!p)
            link[cur] = 1;
        else {
            int q = nxt[p][c];
            if (len[q] == len[p] + 1)
                link[cur] = q;
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
    void build() {
        for (int i = 2; i <= cnt; ++i) {
            e[link[i]].push_back(i);
        }
    }
    void dfs(int u = 1) {
        for (auto v : e[u]) {
            dfs(v);
            sz[u] += sz[v];
        }
    }
};

void solve() {
    auto calc = [&](const string &s, const string &t) -> ll {
        auto ex_kmp = [&](const string &S) -> vector<int> {
            int n = (int)S.length();
            vector<int> z(n);
            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r && z[i - l] < r - i + 1) {
                    z[i] = z[i - l];
                } else {
                    z[i] = max(0, r - i + 1);
                    while (i + z[i] < n && S[z[i]] == S[i + z[i]])
                        ++z[i];
                }
                if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            }
            return z;
        };
        int n = s.length(), m = t.length();
        vector<vector<int>> pre(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            auto z = ex_kmp(s.substr(i));
            for (int j = i + 1, k = 1; j < n; ++j, ++k) {
                int len = z[k];
                len = min(j - 1 - i, len);
                pre[j - 1][i + 1]++, pre[j - 1][i + len + 1]--;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j)
                pre[i][j] += pre[i][j - 1];
        }
        SAM sam;
        sam.init(t.length(), 26);
        sam.add(t);
        sam.build();
        sam.dfs();
        ll Ans = 0;
        for (int i = 0; i < n; ++i) {
            int u = 1;
            for (int j = i; j < n; ++j) {
                if (!sam.nxt[u][s[j] - 'a']) break;
                u = sam.nxt[u][s[j] - 'a'];
                Ans += sam.sz[u] * pre[j][i];
            }
        }
        return Ans;
    };
    string s, t;
    cin >> s >> t;
    ll Ans = calc(s, t) + calc(t, s);
    int n = s.length(), m = t.length();
    SAM sam;
    sam.init(t.length(), 26);
    sam.add(t);
    sam.build();
    sam.dfs();
    for (int i = 0; i < n; ++i) {
        int u = 1;
        for (int j = i; j < n; ++j) {
            if (sam.nxt[u][s[j] - 'a']) {
                u = sam.nxt[u][s[j] - 'a'];
                Ans += sam.sz[u];
            } else break;
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
