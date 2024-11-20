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


void solve(int cas) {
    int n; cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    if (n == 1) {
        cout << a[1] << '\n';
        return ;
    }
    int pos1 = -1;
    int k = 0;
    for (int i = 2; i <= n; ++i)
        if (a[i] > k) {
            k = a[i];
            pos1 = i;
        }
    vector<vector<int> > arr;
    for (int i = pos1 - 1; i >= 1; --i) {
        int r = i - 1;
        vector<int> tmp;
        for (int j = pos1 - 1; j >= i; --j) {
            tmp.pb(a[j]);
        }
        for (int j = 1; j <= r; ++j) tmp.pb(a[j]);
        arr.pb(tmp);
    }
    if (pos1 == n) {
        vector<int> tmp;
        for (int i = 1; i < n; ++i)
            tmp.pb(a[i]);
        arr.pb(tmp);
    }
    sort(all(arr));
    for (int i = pos1; i <= n; ++i) cout << a[i] << ' ';
    for (auto i : arr.back()) cout << i << ' ';
    cout << '\n';
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
