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
constexpr int maxn = 3e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool BEGIN;

ll a[maxn];
int n, k;
bool check(ll x) {
    vector<int> pre(n + 2, 0), suf(n + 2, 0);
    priority_queue<ll> ql, qr;
    ll sum = 0;
    int sz = 0;
    for (int i = 1; i <= n; ++i) {
        if (sum + a[i] <= x) {
            ql.push(a[i]);
            sum += a[i];
            sz++;
        } else {
            if (!ql.empty() && ql.top() > a[i]) {
                sum += a[i] - ql.top();
                ql.pop();
                ql.push(a[i]);
            }
        }
        pre[i] = sz;
    }
    sum = 0;
    sz = 0;
    for (int i = n; i >= 1; --i) {
        if (sum + a[i] <= x) {
            qr.push(a[i]);
            sum += a[i];
            sz++;
        } else {
            if (!qr.empty() && qr.top() > a[i]) {
                sum += a[i] - qr.top();
                qr.pop();
                qr.push(a[i]);
            }
        }
        suf[i] = sz;
    }
    for (int i = 1; i <= n; ++i)
        if (pre[i] + suf[i + 1] >= k)
            return 1;
    return 0;
}

void solve(int cas) {
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    ll l = 0, r = sum;
    ll ans;
    while (l <= r) {
        ll mid = l + r >> 1;
        // cout << mid << '\n';
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
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
