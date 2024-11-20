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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

int a[maxn], pre[maxn];
int b[maxn];

int trie[maxn * 30][2], idx = 1;
void ins(int x) {
    int now = 1;
    for (int i = 30; i >= 0; --i) {
        int c = (x >> i) & 1;
        if (!trie[now][c]) trie[now][c] = ++idx;
        now = trie[now][c];
    }
}
int Max(int x) {
    int ans = 0, now = 1;
    for (int i = 30; i >= 0; --i) {
        int c = (x >> i) & 1;
        if (trie[now][c ^ 1]) {
            ans += (1 << i);
            c ^= 1;
        }
        now = trie[now][c];
    }
    return ans;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        // cout << pre[i] << ' ';
        ins(pre[i]);
    }
    int Ans = -1;
    for (int i = 0; i < n; ++i) {
        if (Max(i) < n) {
            Ans = i;
            break;
        }
    }
    cout << Ans << ' ';
    for (int i = 1; i < n; ++i) {
        cout << (Ans ^ pre[i]) << ' ';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
