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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


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

void solve() {
    int n, q; cin >> n >> q;
    int tot = 0;
    map<int, int> N, nown;
    ll nowd = 1, dN;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            nown[i]++;
            n /= i;
        }
    }
    if (n > 1) nown[n]++;
    for (auto [x, y] : nown) {
        nowd *= (y + 1);
    }
    dN = nowd;
    N = nown;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            for (int i = 2; i * i <= x; ++i) {
                int c = 0;
                while (x % i == 0) {
                    c++;
                    x /= i;
                }
                nowd /= (nown[i] + 1);
                nown[i] += c;
                nowd *= (nown[i] + 1);
            }
            if (x > 1) {
                nowd /= (nown[x] + 1);
                nown[x]++;
                nowd *= (nown[x] + 1);
            }
            ll tmp = nowd;
            for (auto [x, y] : nown) {
                int c = 0;
                while (tmp % x == 0 && c < y)
                    tmp /= x, c++;
            }
            cout << (tmp > 1 ? "NO\n" : "YES\n");
        } else {
            nown = N;
            nowd = dN;
        }
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    isprime(1000000);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}

