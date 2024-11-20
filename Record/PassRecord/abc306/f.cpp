#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <climits>
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
constexpr int maxn = 2e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int n, m;

struct BIT
{
	int MX;
	ll tr[maxn];
	void update(int x, int val)
	{
		while (x <= n * m) {
			tr[x] += val;
			x += lowbit(x);
		}
	}
	ll query(int x)
	{
		ll sum = 0;
		while (x) {
			sum += tr[x];
			x -= lowbit(x);
		}
		return sum;
	}
} bit;
void solve(int cas) {
    cin >> n >> m;
    vector<int> tmp;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            tmp.pb(a[i][j]);
        }
        sort(all(a[i]));
    }
    sort(all(tmp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = lower_bound(all(tmp), a[i][j]) - tmp.begin();
            bit.update(a[i][j] + 1, 1);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j)
            ans += bit.query(a[i][j]) + (j + 1) * (n - i - 1) - j;
        for (int j = 0; j < m; ++j)
            bit.update(a[i][j] + 1, -1);
    }
    cout << ans;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

