#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <cctype>
#include <cstdio>
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

void solve(int cas) {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (auto &i : a) cin >> i;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= cnt && prime[j] * prime[j] <= a[i]; ++j) {
            if (a[i] % prime[j] == 0) {
                while (a[i] % prime[j] == 0) {
                    mp[prime[j]]++;
                    a[i] /= prime[j];
                }
            }
        }
        if (a[i] != 1) mp[a[i]]++;
    }
    int ans = 0, res = 0;
    for (auto &[x, y] : mp) {
        ans += y / 2;
        y = y % 2;
        res += y;
    }
    ans += res / 3;
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    isprime(10000);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
