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


string s;
struct Sequence {
    vector<vector<int>> nxt;
    void init(int n, int char_size) {
        nxt.resize(n + 2, vector<int>(char_size, INF));
        for (int i = n - 1; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }
    }
    bool find(string &t) {// 子序列
        int p = -1, len_t = SZ(t);
        for (int i = 0; i < len_t; ++i) {
            p = nxt[p + 1][t[i] - 'a'];
            if (p == INF) return 0;
        }
        return 1;
    }
};




Sequence S;
void solve() {
    string alp; cin >> alp;
    vector<bool> Alp(200);
    for (auto i : alp) Alp[i] = 1;
    cin >> s;
    int n = s.length();

    S.init(n, 26);

    int len = 0;
    int st = -1;
    while (st < n) {
        int mx = st;
        // cout << st << '\n';
        for (int i = 0; i < 26; ++i) {
            if (!Alp[i + 'a']) continue;
            mx = max(mx, S.nxt[st + 1][i]);
        }
        st = mx;
        len++;
    }
    // cout << len << '\n';
    int q; cin >> q;
    while (q--) {
        string t; cin >> t;
        if (t.length() != len) {
            puts("0");
        } else if (S.find(t)) {
            puts("0");
        } else {
            puts("1");
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
