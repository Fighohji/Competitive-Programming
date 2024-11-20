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
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;
struct BIT {
	int MX;
	ll tr[maxn];
    void init(int n) {
        MX = n;
        for (int i = 1; i <= MX; ++i) {
            tr[i] = 0;
        } 
    }
	void update(int x, int val) {
		while (x <= MX) {
			tr[x] += val;
			x += lowbit(x);
		}
	}
	ll query(int x) {
		ll sum = 0;
		while (x) {
			sum += tr[x];
			x -= lowbit(x);
		}
		return sum;
	}
} bit;
ll cnt[maxn], sum[maxn], les[maxn];
struct node {
    int l, r;
    int id;
} qr[maxn];
int n, block;
ll Ans;
int a[maxn];
void addr(int p) {
    Ans += cnt[a[p]] * les[p] - sum[a[p]];
    cnt[a[p]]++;
    sum[a[p]] += les[p];
}
void delr(int p) {
    cnt[a[p]]--;
    sum[a[p]] -= les[p];
    Ans -= cnt[a[p]] * les[p] - sum[a[p]];
}
void addl(int p) {
    Ans += sum[a[p]] - cnt[a[p]] * les[p];
    cnt[a[p]]++;
    sum[a[p]] += les[p];
}
void dell(int p) {
    cnt[a[p]]--;
    sum[a[p]] -= les[p];
    Ans -= sum[a[p]] - cnt[a[p]] * les[p];
}
bool cmp(node a, node b) {
	int x = a.l / block, y = b.l / block;
	if (x != y) return x < y;
	if(x & 1) return a.r > b.r;
	return a.r < b.r;
}
ll ans[maxn];
void solve(int cas) {
    int q; cin >> n >> q;
    block = sqrt(n + 1);
    bit.init(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        les[i] = bit.query(a[i] - 1);
        bit.update(a[i], 1);
    }
    for (int i = 1; i <= q; ++i) {
        cin >> qr[i].l >> qr[i].r;
        qr[i].id = i;
    }
    sort(qr + 1, qr + 1 + q, cmp);
    int L = 1, R = 0;
    for (int i = 1; i <= q; ++i) {
        auto [l, r, id] = qr[i];
        while (R < r) addr(++R);
        while (R > r) delr(R--);
        while (L > l) addl(--L);
        while (L < l) dell(L++);
        ans[id] = Ans;
    }
    for (int i = 1; i <= q; ++i)
        cout << ans[i] << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}

