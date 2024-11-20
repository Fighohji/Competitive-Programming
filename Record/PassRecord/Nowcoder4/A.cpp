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
    ll seed = 487, p;
    ll hash[maxn], power[maxn];
    void init(string &s, ll P = 998244353) {
        p = P;
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed % p + s[i - 1]) % p;
            power[i] = power[i - 1] * seed % p;
        }
    }
    ll get_hash(int l, int r) {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1] % p;
        return ((a - b) % p + p) % p;
    }
} hs, hs2;
void solve(int cas) {
    int n; cin >> n;
    string t; cin >> t;
    bool f0 = 0, f1 = 0;
    for (auto i : t) {
        if (i == '0') f0 = 1;
        else f1 = 1;
    }
    if (!f1) {
        for (int i = 1; i <= n; ++i) {
            cout << 1;
        }
    } else if (!f0) {
        for (int i = 1; i <= n; ++i) {
            cout << 0;
        }
    } else {
        if (t[0] == t.back()) {
            if (t[0] == '1') {
                for (int i = 1; i <= n; ++i) {
                    cout << 1;
                }
            } else {
                for (int i = 1; i <= n; ++i) {
                    cout << 0;
                }
            }
        } else {
            string s = t;
            for (int i = 1; i <= n; ++i) {
                s += '0';
            }
            s += t;
            hs.init(s);
            hs2.init(s, 998244853);
            bool f = 0;
            ull h1 = hs.get_hash(0, SZ(t) - 1), h2 = hs2.get_hash(0, SZ(t) - 1);
            for (int i = 1; i + SZ(t) - 1 < SZ(s) - 1; ++i) {
                if (hs.get_hash(i, i + SZ(t) - 1) == h1 && hs2.get_hash(i, i + SZ(t) - 1) == h2) {
                    f = 1;
                    break;
                }
            }
            for (int i = 1; i <= n; ++i) {
                cout << f;
            }
        }
    }
    cout << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
