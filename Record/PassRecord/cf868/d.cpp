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
    int n, k; cin >> n >> k;
    vector<int> x(k + 1), c(k + 1);
    x[0] = c[0] = 3;
    for (int i = 1; i <= k; ++i)
        cin >> x[i];
    for (int i = 1; i <= k; ++i)
        cin >> c[i];
    for (int i = 1; i <= k; ++i) {
        if (c[i] - c[i - 1] > x[i] - x[i - 1]) {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
    char cur = 'd';
    cout << "abc";
    int now = 0;
    for (int i = 1; i <= k; ++i) {
        int nd = c[i] - c[i - 1];
        for (int j = 1; j <= nd; ++j) {
            cout << cur;
        }
        if (nd) cur++;
        for (int j = 0; j < x[i] - x[i - 1] - nd; ++j) {
            cout << (char)(now  % 3 + 'a');
            now++;
        }
    }
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
