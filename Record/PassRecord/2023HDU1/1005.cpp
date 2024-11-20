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



// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int minexpression(int len, string &s) {
    int minid = 0;
    for (int i = 1, k; i < len;) {
        for (k = 1; k <= len; ++k)
            if (s[(i+k-1) % len] != s[(minid + k - 1) % len])
                break;
        if (k > len) break;
        if (s[(i + k - 1) % len] < s[(minid + k - 1) % len]) {
            int tmp = i;
            i = max(minid + k, tmp + 1);
            minid = tmp;
        }
        else i += k;
    }
    return minid;
}

struct Hash {
    ull seed = 131, p;
    ull hash[maxn], power[maxn];
    void init(string &s, ull P = UINT64_MAX) {
        p = P;
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ull get_hash(int l, int r) {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1] % p;
        return (a - b + p) % p;
    }
};


void solve(int cas) {
    int n, m; cin >> n >> m;
    vector<string> s(n + 1);
    vector<string> t(n + 1);
    vector<ull> hs(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        int id = minexpression(m, s[i]);
        t[i] = s[i].substr(id) + s[i].substr(0, id);
        for (auto j : t[i]) {
            hs[i] = (hs[i] * 487 % 1000000871 + j) % 1000000871;
        }
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        cout << (hs[x] == hs[y] ? "Yes\n" : "No\n");
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
