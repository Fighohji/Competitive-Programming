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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

bool BEGIN;

int n, q;



bitset<1001> sum[maxn << 2], lazy[maxn << 2];


void push_down(int p) {
    if (lazy[p].any()) {
        sum[p << 1] |= lazy[p];
        sum[p << 1 | 1] |= lazy[p];
        lazy[p << 1] |= lazy[p];
        lazy[p << 1 | 1] |= lazy[p];
        lazy[p].reset();
    }
}



void update(int p, int l, int r, int ql, int qr, int pos) {
    if (ql <= l && r <= qr) {
        bitset<1001> bit;
        bit.set(pos);
        lazy[p] |= bit;
        sum[p] |= bit;
        return ;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(p << 1, l, mid, ql, qr, pos);
    if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, pos);
    sum[p] = sum[p << 1] | sum[p << 1 | 1];
}

bitset<1001> query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum[p];
    push_down(p);
    int mid = (l + r) >> 1;
    bitset<1001> ans;
    if (ql <= mid) ans |= query(p << 1, l, mid, ql, qr);
    if (mid < qr) ans |= query(p << 1 | 1, mid + 1, r, ql, qr);
    return ans;
}

/*
10 10
1 7 8 2
2 3 6 10
1 9 10 6
2 2 10 2
1 9 10 5
1 10 10 10
2 4 8 8
2 1 4 9
2 7 10 1
2 2 7 3
*/

bitset<1001> ans;
void solve(int cas) {
    cin >> n >> q;
    while (q--) {
        int op, l, r, x;
        cin >> op >> l >> r >> x;
        if (op == 1) {
            update(1, 1, n, l, r, x);
            // cout << query(1, 1, n, 1, n) << '\n';
        } else {
            ans = query(1, 1, n, l, r);
            // cout << ans << '\n';
            if (ans.count() < x) cout << "-1\n";
            else {
                int now = 0;
                while (x--) {
                    now = ans._Find_next(now);
                }
                cout << now << '\n';
            }
        }
    }
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
