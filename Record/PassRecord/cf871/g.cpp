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

ll pre[1000005];
int id[1000005];
int mx[2005], mn[2005];
void init() {
    vector<int> tmp(2005, 0);
    int now = 1;
    for (int i = 1; i <= 1000000; ++i) {
        pre[i] = pre[i - 1] + (ll) i * i;
        if (tmp[now] < now) {
            id[i] = now;
            tmp[now]++;
        }
        if (tmp[now] == now) {
            now++;
        }
    }
    for (int i = 1; i <= 2000; ++i) {
        mx[i] = (ll)i * (i + 1) / 2;
        mn[i] = mx[i - 1] + 1;
    }
}

void solve(int cas) {
    // for (int i = 1; i <= 10; ++i)
    //     cout << mn[i] << ' ' << mx[i] << '\n';
    int n; cin >> n;
    ll res = 0;
    int l = n, r = n;
    for (int i = id[n]; i >= 1; --i) {
        res += pre[r] - pre[l - 1];
        if (i == 1) break;
        l = max(mn[i - 1], l - i);
        r = min(mx[i - 1], r - i + 1); 
        // cout << l << ' ' << r << '\n';
    }
    cout << res << '\n';
}


bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    init();
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
