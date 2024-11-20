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

void solve() {
    int n; cin >> n;
    vector<int> Q(n), A(n), B(n);
    int Ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> Q[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    int res = INF;
    for (int i = 0; i < n; ++i) {
        if (!A[i]) continue;
        res = min(res, Q[i] / A[i]);
    }
    Ans = max(Ans, res);
    int p = Ans;
    // cerr << Ans << '\n';
    for (int i = 0; i <= p; ++i) {
        vector<int> tmp = Q;
        for (int j = 0; j < n; ++j) {
            tmp[j] -= i * A[j];
        }
        int ex = INF;
        for (int j = 0; j < n; ++j) {
            if (!B[j]) continue;
            ex = min(ex, tmp[j] / B[j]);
        }
        Ans = max(Ans, i + ex);
    }
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
