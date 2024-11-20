#include <cstdlib>
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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 9; /* 998244353 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

int a[maxn];

struct SegTree {
	int Max[maxn << 2], sum[maxn << 2];
	void pull(int p) {
		Max[p] = max(Max[p << 1], Max[p << 1 | 1]);
	}
	void push(int p) {
		if (sum[p]) {
			sum[p << 1] += sum[p];
			sum[p << 1 | 1] += sum[p];
			sum[p] = 0;
		}
	}
	void update(int p, int l, int r, int pos, int val) {
		Max[p] = max(Max[p], val);
		if (l == r) return ;
		int mid = l + r >> 1;
		if (pos <= mid) update(p << 1, l, mid, pos, val);
		else update(p << 1 | 1, mid + 1, r, pos, val);
	}
	void update(int p, int l, int r, int ql, int qr, int val) {
		if (ql > qr) return ;
		if (ql <= l && r <= qr) {
			sum[p] += val;
			return ;
		}
		push(p);
		int mid = l + r >> 1;
		if (ql <= mid) update(p << 1, l, mid, ql, qr, val);
		if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val);
	}
	int query(int p, int l, int r, int ql, int qr) {
		if (ql > qr) return 0;
		if (ql <= l && r <= qr) {
			return Max[p];
		}
		push(p);
		int mid = l + r >> 1, res = 0;
		if (ql <= mid) res = max(res, query(p << 1, l, mid, ql, qr));
		if (mid < qr) res = max(res, query(p << 1 | 1, mid + 1, r, ql, qr));
		return res;
	}
	int query(int p, int l, int r, int pos) {
		if (l == r) return sum[p];
		push(p);
		int mid = l + r >> 1;
		if (pos <= mid) return query(p << 1, l, mid, pos);
		else return query(p << 1 | 1, mid + 1, r, pos);
	}
} tr[2];

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int len = unique(a + 1, a + 1 + n) - a - 1;
	vector<vector<int>> pos(n + 1);
	for (int i = 1; i <= len; ++i) {
		pos[a[i]].pb(i);
	}
	vector<vector<pii>> qr(n + 1);
	for (int i = 1; i <= q; ++i) {
		int l, r; cin >> l >> r;
		qr[r].eb(l, i);
	}
	vector<int> Ans(q + 1, 0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < SZ(pos[i]); ++j) {
			if (j == 0) tr[1].update(1, 1, n, 1, i, 1);
			else {
				int Max = tr[0].query(1, 1, len, pos[i][j - 1] + 1, pos[i][j] - 1);
				tr[1].update(1, 1, n, 1, Max, 1);
			}
		}
		for (auto j : pos[i]) tr[0].update(1, 1, len, j, a[j]);
		for (auto j : qr[i]) {
			auto [l, id] = j;
			Ans[id] = tr[1].query(1, 1, n, l);
		}
	}
	for (int i = 1; i <= q; ++i) {
		cout << Ans[i] << '\n';
	}
}
bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // srand(time(nullptr));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

