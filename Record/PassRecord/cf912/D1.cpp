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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)



void solve() {
    int n, q; cin >> n >> q;
    vector<ll> b(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum += b[i];
    }
    while (q--) {
        ll K; cin >> K;
        if (K > 1e12) {
            cout << (sum + K) / n << '\n';
            continue;
        }
        vector<ll> a = b;
        ll Ans = 0;
        for (int i = 40; i >= 0; --i) {
            ll nd = 0;
            for (int j = 0; j < n; ++j) {
                if (1ll << i & a[j]) continue;
                ll val = a[j];
                for (int k = 40; k > i; --k) {
                    val -= (1ll << k & a[j]);
                }
                nd += (1ll << i) - val;
            }
            if (nd <= K) {
                K -= nd;
                for (int j = 0; j < n; ++j) {
                    if (1ll << i & a[j]) continue;
                    for (int k = i - 1; k >= 0; --k) {
                        a[j] -= (1ll << k & a[j]);
                    }
                    a[j] |= (1ll << i);
                }
              Ans |= (1ll << i);  
            }
        }
        cout << Ans << '\n';
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


