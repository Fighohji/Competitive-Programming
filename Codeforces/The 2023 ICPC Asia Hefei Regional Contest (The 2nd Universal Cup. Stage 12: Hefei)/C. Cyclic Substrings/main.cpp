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

constexpr int N = 6e6 + 50;
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

int n;
struct PAM {
    int sz, tot, last, len[N], link[N], nxt[N][10];
    ll siz[N];
    char s[N];
    int newNode(int l) {
        len[++sz] = l;
        return sz;
    }
    void init() {
        sz = -1, last = 0;
        s[tot = 0] = '$';
        newNode(0);
        newNode(-1);
        link[0] = 1;
    }
    int getPrev(int x) {
        while (s[tot - len[x] - 1] != s[tot])
            x = link[x];
        return x;
    }
    void insert(char c) {
        s[++tot] = c;
        int now = getPrev(last);
        if (!nxt[now][c - '0']) {
            int x = newNode(len[now] + 2);
            link[x] = nxt[getPrev(link[now])][c - '0'];
            nxt[now][c - '0'] = x;
        }
        last = nxt[now][c - '0'];
        if (tot > n) siz[last]++;
    }
} pam;
void solve() {
    cin >> n;
    string s;
    cin >> s;
    s = s + s;
    pam.init();
    for (auto i : s) {
        pam.insert(i);
    }
    for (int i = pam.sz; i >= 2; --i) {
        pam.siz[pam.link[i]] += pam.siz[i];
        pam.siz[pam.link[i]] %= mod;
    }
    ll Ans = 0;
    for (int i = 2; i <= pam.sz; ++i) {
        if (pam.len[i] <= n) Ans += pam.siz[i] * pam.siz[i] % mod * pam.len[i] % mod;
        Ans %= mod;
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
