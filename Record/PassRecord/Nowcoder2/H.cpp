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
constexpr int maxn = 4e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


int n, q;
string s;
int f[maxn << 2], sum[maxn << 2];

void push(int p) {
    f[p] = f[p << 1] * f[p << 1 | 1];
    sum[p] = f[p << 1 | 1] * sum[p << 1] + sum[p << 1 | 1];
}

void build(int p, int l, int r) {
    if (l == r) {
        if (s[l] == 'A') {
            f[p] = -1;
            sum[p] = -1;
        } else {
            sum[p] = 1;
            f[p] = 1;
        }
        return ;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push(p);
}

pii get(pii a, pii b) {
    return {a.fir * b.fir, b.fir * a.sec + b.sec};
}

pii query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return {f[p], sum[p]};
    }
    int mid = (l + r) >> 1;
    pii ans = {1, 0};
    if (ql <= mid) {
        pii res = query(p << 1, l, mid, ql, qr);
        ans = get(ans, res);
    }
    if (mid < qr) {
        pii res = query(p << 1 | 1, mid + 1, r, ql, qr);
        ans = get(ans, res);
    }
    return ans;
}
ll base[100];
string S;
int L, R;
int ans;
void solve(int cas) {
    base[0] = 1;
    for (int i = 1; i <= 60; ++i) {
        base[i] = base[i - 1] * 2;
    }
    cin >> n >> q;
    cin >> s;
    s = "~" + s;
    build(1, 1, n);

    while (q--) {
        int l, r; cin >> l >> r;
        cin >> S;

        L = min((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        R = max((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        pii mul = query(1, 1, n, L, R);
        ll now = 0;
        int p = SZ(S);
        for (int i = 0; i < p; ++i) {
            now = now * 2 + S[i] - '0';
        }
        now = now * mul.fir + mul.sec;
        now %= base[p];
        now = (now + base[p]) % base[p];
        ans = now;
        for (int i = p - 1; i >= 0; --i) {
            cout << ((now >> i) & 1);
        }
        cout << '\n';
    }
}

/*
3 1
BAA
1 1 0001

*/
bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
