#include <map>
#include <numeric>
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

int dp[maxn];
int  n;
vector<int> a[maxn];
int x[maxn];
int bs[maxn];
void solve(int cas) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].clear();
        bs[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        a[x[i]].pb(i);
    }
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        int id = lower_bound(all(a[x[i]]), i) - a[x[i]].begin();
        // cout << id << ' ';
        dp[i] = dp[i - 1];
        if (id) {
            int nx = a[x[i]][id - 1] - 1;
            // cout << nx;
            if (dp[nx] + i - nx > dp[i]) {
                bs[i - 1] = nx;
                dp[i] = dp[nx] + i - nx;
            }
            if (bs[nx] != -1) {
                nx = bs[nx];
                // cout << nx << ' ';
                if (dp[nx] + i - nx > dp[i]) {
                    bs[i - 1] = nx;
                    dp[i] = dp[nx] + i - nx;
                }
            }
        }
        // cout << '\n';
        // cout << dp[i] << ' ';
        // cout << bs[i] << '\n';
    }
    // cout << '\n';
    cout << dp[n] << '\n';
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
