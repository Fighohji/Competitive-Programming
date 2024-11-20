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
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)


bool BEGIN;

int val[maxn], idx;
int fa[maxn][21];
vector<int> e[maxn];
void build(int x, int p) {
    fa[x][0] = p;
    for (int i = 1; i <= 20; ++i)
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
}
int jump(int x, int k) {
    for (int i = 20; i >= 0; --i) {
        if (k >= (1 << i)) {
            x = fa[x][i];
            k -= (1 << i);
        }
    }
    return x;
}

struct BIT
{
	int tr[maxn];
	void update(int x, int val)
	{
        if (!val) return ;
		while (x <= 1000000) {
			tr[x] += val;
			x += lowbit(x);
		}
	}
	int query(int x)
	{
        if (!x) return 0;
		int sum = 0;
		while (x) {
			sum += tr[x];
			x -= lowbit(x);
		}
		return sum;
	}
} bit;

vector<int> stk;
vector<int> qr[maxn];
void solve() {
    int q; cin >> q;
    string op; int x;
    stk.pb(0);
    vector<int> Ans(q + 1, -1);
    for (int i = 1;i <= q; ++i) {
        cin >> op;
        idx++;
        if (op[0] == '+') {
            cin >> x;
            val[idx] = x;
            build(idx, stk.back());
            e[stk.back()].pb(idx);
            stk.pb(idx);
        } else if (op[0] == '-') {
            cin >> x;
            int p = jump(stk.back(), x);
            stk.pb(p);
        } else if (op[0] == '!') {
            idx--;
            stk.pop_back();
        } else {
            idx--;
            qr[stk.back()].pb(i);
        }
    }
    auto dfs = [&](auto self, int u) -> void {
        int add = 0;
        if (u != 0) {
            add = bit.query(val[u]) - bit.query(val[u] - 1); add ^= 1;
            bit.update(val[u], add);
        }
        if (!qr[u].empty()) {
            int sum = bit.query(1000000);
            for (auto i : qr[u]) {
                Ans[i] = sum;
            }
        }
        for (auto v : e[u]) {
            self(self, v);
        }
        bit.update(val[u], -add);
    };
    dfs(dfs, 0);
    for (int i = 1; i <= q; ++i) {
        if (Ans[i] != -1)
            cout << Ans[i] << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
