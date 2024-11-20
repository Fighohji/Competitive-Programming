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

#define db double
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

constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

struct Hash
{
    ull seed = 131, p;
    ull hash[30], power[30];
    void init(vector<ll> &s)
    {
        power[0] = 1;
        hash[0] = 0;
        for (int i = 1; i <= SZ(s); ++i) {
            hash[i] = hash[i - 1] * seed + s[i - 1];
            power[i] = power[i - 1] * seed;
        }
    }
    ull get_hash(int l, int r)
    {
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1];
        return a - b;
    }
};

void solve() {
    int n; cin >> n;
    ll c; cin >> c;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    Hash hb;
    hb.init(b);
    for (int sta = 0; sta < (1 << (n - 1)); ++sta) {
        vector<vector<ll>> blo;
        vector<ll> now;
        for (int j = 0; j < n; ++j) {
            now.pb(a[j]);
            if ((1 << j) & sta) {
                blo.pb(now);
                now.clear();
            }
        }
        blo.pb(now);
        vector<Hash> ha(SZ(blo));
        for (int j = 0; j < SZ(blo); ++j) {
            ha[j].init(blo[j]);
        }
        ll vis = 0;
        for (int j = 0; j < n; ++j) {

        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
