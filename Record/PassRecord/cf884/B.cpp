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


void solve(int cas) {
    int n; cin >> n;
    // vector<int> ans(n + 1);

    // ans[(n + 1) / 2] = 1;
    // int l = 1, r = n;
    // for (int i = 0; i < SZ(tmp); ++i) {
    //     if (i % 2 == 0) {
    //         if (l == (n + 1) / 2) l++;
    //         ans[l++] = tmp[i];
    //     }
    //     else {
    //         if (r == (n + 1) / 2)
    //         ans[r--] = tmp[i];
    //     }
    // }
    // for (int i = 2; i <= n; ++i) {
    //     if (l == (n + 1) / 2) l++;
    //     if (vis[i]) {
    //         ans[l++] = i;
    //     }
    // }
    if (n == 1) {
        cout << "1\n";
    } else if (n == 2) {
        cout << "2 1\n";
    } else {
        vector<int> ans(n + 1);
        ans[1] = 2; ans[n] = 3;
        ans[(n + 1) / 2] = 1;
        int now = 4;
        for (int i = 1; i <= n; ++i) {
            if (i == 1 || i == n || i == (n + 1) / 2) {
                continue;
            }
            ans[i] = now++;
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " \n"[i == n];
        }
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    isprime(200000);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
