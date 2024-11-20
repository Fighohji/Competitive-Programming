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

#define int long long

void solve(int cas) {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<int> > buc(2 * n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        buc[a[i]].pb(b[i]);
    }
    ll ans = 0;
    vector<int> cnt(2 * n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (buc[i].empty()) continue;
        for (auto k : buc[i])
            cnt[k]++;
        for (int j = i + 1; j * i <= 2 * n && j <= n; ++j) {
            if (buc[j].empty()) continue;
            int now = i * j;
            for (auto k : buc[j])
                if (now > k)
                    ans += cnt[now - k];
        }
        for (auto k : buc[i])
            cnt[k]--;
    }
    for (int i = 2; i * i <= 2 * n && i <= n; ++i) {
        if (buc[i].empty()) continue;
        ll res = 0;
        int now = i * i;
        for (auto j : buc[i])
            cnt[j]++;
        for (auto j : buc[i])
            if (j * 2 != now && now > j)
                res += cnt[now - j];
        res = res / 2;
        if (now % 2 == 0)
            res += cnt[now / 2] * (cnt[now / 2] - 1) / 2;
        ans += res;
        for (auto j : buc[i])
            cnt[j]--;
    }
    cout << ans << '\n';
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
