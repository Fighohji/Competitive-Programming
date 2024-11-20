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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

struct Hash {
    ll seed = 13331, p;
    ll hash[maxn], power[maxn];
    void init(string &s, ll P = 10001587) {
        p = P;
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ll get_hash(int l, int r) {
        l++, r++;
        ll a = hash[r];
        ll b = hash[l - 1] * power[r - l + 1] % p;
        return ((a - b) % p + p) % p;
    }
} hs[2];
ll qpow(ll base, ll power, ll p) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % p;
        base = base * base % p;
        power >>= 1;
    }
    return res;
}


void solve(int cas) {
    int m; cin >> m;
    string s, t; cin >> s >> t;
    int x = SZ(s), y = SZ(t);
    hs[0].init(s), hs[1].init(t);
    for (int i = 1; i <= m; ++i) {
        if ((x + y) % 2) {
            cout << 0 << ' ';
            continue;
        }
        int mid = (2 * i + x + y) >> 1;
        int sl = i + 1, sr = i + x;
        int tl = 2 * i + x + 1, tr = 2 * i + x + y;
        int prel = i + 1, prer = mid;
        int sufl = mid + i + 1, sufr = 2 * i + x + y;
        if (x == y && hs[0].get_hash(0, x - 1) == hs[1].get_hash(0, y - 1)) {
            cout << qpow(26, i, mod) << '\n';
        } else {
            if (tl <= prer) {
                int M = i - (tl - sr - 1);
                int det = sufr - (sufl + x - 1);
                bool flag = (hs[0].get_hash(0, x - 1) == hs[1].get_hash(sufl - tl, sufl - tl + x - 1) && hs[1].get_hash(0, prer - tl) == hs[1].get_hash(y - 1 - (prer - tl), y - 1));
                cout << qpow(26, M, mod) * flag << ' ';
            } else if (tl < sufl && sr <= prer) {
                int M = i - prer + sr;
                int det = sufr - (sufl + x - 1);
                bool flag = hs[0].get_hash(0, x - 1) == hs[1].get_hash(y - 1 - det - (x - 1), y - 1 - det);
                cout << qpow(26, M, mod) * flag << ' ';
            } else if (tl < sufl && sr > prer) {
                int M = i;
                int det = prer - prel;
                bool flag = hs[0].get_hash(0, det) == hs[1].get_hash(y - 1 - det, y - 1);
                cout << qpow(26, M, mod) * flag << ' ';
            } else if (tl >= sufl && sr < sufl) {
                int M = i - (sufr -sufl + 1 - y);
                int det = prer - prel;
                bool flag = hs[1].get_hash(0, y - 1) == hs[0].get_hash(det - (y - 1), det);
                cout << qpow(26, M, mod) * flag << ' ';
            } else {
                int M = i - (tl - sr - 1);
                int det = prer - prel;
                bool flag = (hs[1].get_hash(0, y - 1) == hs[0].get_hash(det - (y - 1), det) && hs[0].get_hash(x - 1 - (sr - sufl), x - 1) == hs[0].get_hash(0, sr - sufl));
                cout << qpow(26, M, mod) * flag << ' ';
            }
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
