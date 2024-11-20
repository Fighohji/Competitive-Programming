#include <cstdlib>
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
#include <limits.h>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

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

#define int long long
constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
const int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
bool vis[maxn];
int prime[maxn];
int cnt;
void isprime(int n) {
    for (int i = 2; i <= n; ++i) {
        if(!vis[i]) prime[++cnt] = i;
        for (int j = 1;j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

#define ull ll
struct Hash
{
    ull seed, p;
    ull hash[maxn], power[maxn], pre[maxn];
    void init(string &s, ull P = UINT64_MAX) {
        p = P;
        power[0] = 1;
        for (int i = 1; i < s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i] - '0') % p;
            power[i] = power[i - 1] * seed % p;
            pre[i] = (pre[i - 1] * seed % p + 1) % p;
        }
    }
    ull get_hash(int l, int r) {
        if (l > r) return 0ull;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1] % p;
        return ((p + a - b) % p + p) % p;
    }
};

Hash hs1, hs2;
void solve(int cas) {
    int n, m; cin >> n >> m;
    set<pair<ull, ull>> st;
    string s; cin >> s;
    s = "~" + s;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + s[i] - '0';
    }
    hs1.seed = prime[rand() % (cnt - 15) + 10];
    hs2.seed = prime[rand() % (cnt - 15) + 10];
    ull Mod = rand() % 1000000000 + 1000000000;
    hs1.init(s, mod); hs2.init(s, Mod);
    for (int i = 1; i <= m; ++i) {
        int l, r; cin >> l >> r;
        int res = pre[r] - pre[l - 1];
        ull x = hs1.get_hash(1, l - 1);
        x = x * hs1.power[r - l + 1] % hs1.p;
        x = (x + hs1.pre[res]) % hs1.p;
        x = x * hs1.power[n - r] % hs1.p;
        x = (x + hs1.get_hash(r + 1, n)) % hs1.p;

        ull y = hs2.get_hash(1, l - 1);
        y = y * hs2.power[r - l + 1] % hs2.p;
        y = (y + hs2.pre[res]) % hs2.p;
        y = y * hs2.power[n - r] % hs2.p;
        y = (y + hs2.get_hash(r + 1, n)) % hs2.p;
        st.insert({x, y});
    }
    cout << SZ(st) << '\n';
}

bool END;
signed main() {
    srand(time(nullptr));
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    isprime(5e3);
    // cerr << cnt << '\n';
    int T; cin >> T; while (T--) {
        solve(1);
    }
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
