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


struct Hash {
    ull seed = 131, p;
    ull hash[maxn], power[maxn];
    void init(string &s) {
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = hash[i - 1] * seed + s[i - 1];
            power[i] = power[i - 1] * seed;
        }
    }
    ull get_hash(int l, int r) {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1];
        return a - b;
    }
} hs, ht;



void solve() {
    unordered_map<ull, bool> mp;
    string s; cin >> s;
    int n = s.length();
    string S = s + s;
    hs.init(S);
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = i; j < 2 * n; ++j) {
            mp[hs.get_hash(i, j)] = 1;
        }
    }
    reverse(all(s));
    ht.init(s);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (!mp.count(ht.get_hash(i, j))) {
                cout << 0 << '\n';
                return ;
            }
        }
    }
    cout << 1 << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
