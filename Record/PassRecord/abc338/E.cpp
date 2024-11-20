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

struct BIT {
    int MX;
    vector<ll> sum;
    BIT() {}
    BIT(int _MX) : MX(_MX) {
        sum = vector<ll>(_MX + 1);
    }
    void upd(int x, int val) {
        x++;
        while (x <= MX) {
            sum[x] += val;
            x += lowbit(x);
        }
    }
    ll qry(int x) {
        x++;
        ll res = 0;
        while (x) {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
};


void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    vector nxt(2 * n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
        if (A[i] > B[i]) swap(A[i], B[i]);
        nxt[A[i]].pb(B[i]);
    }
    BIT bit = BIT(4 * n + 10);
    for (int i = 0 ; i < 4 * n; ++i) {
        for (auto j : nxt[i % (2 * n)]) {
            if (bit.qry(j) - bit.qry(i)) {
                cout << "Yes\n";
                return ;
            }
            bit.upd(i, 1);
            bit.upd(j, -1);
        }
    }
    cout << "No\n";
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
