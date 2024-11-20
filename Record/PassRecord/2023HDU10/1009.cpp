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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

ll x[maxn];

int id[maxn];
struct SegTree {
    ll sum[maxn << 2], base[maxn << 2], lazy_add[maxn << 2], lazy_mul[maxn << 2];

    void build(int p, int l, int r) {
        sum[p] = 0, lazy_add[p] = 0, base[p] = 0, lazy_mul[p] = 0;
        if (l == r) {
            base[p] = x[id[l]];
            return ;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }

    void push(int p) {
        if (lazy_add[p]) {
            lazy_add[p << 1] += lazy_add[p];
            lazy_add[p << 1 | 1] += lazy_add[p];
            lazy_add[p] = 0;
        }
        if (lazy_mul[p]) {
            lazy_mul[p << 1] += lazy_mul[p];
            lazy_mul[p << 1 | 1] += lazy_mul[p];
            lazy_mul[p] = 0;
        }
    }

    void update(int p, int l, int r, int ql, int qr, ll val, ll mul) {
        if (ql > qr) return ;
        if (ql <= l && r <= qr) {
            lazy_add[p] += val;
            lazy_mul[p] += mul;
            return ;
        }
        push(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, val, mul);
        if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val, mul);
    }

    ll query(int p, int l, int r, int ql, int qr) {
        if(l == r) return base[p] * lazy_mul[p] + lazy_add[p];
        int mid = (l + r) >> 1;
        push(p);
        ll ans = LINF;
        if (ql <= mid) ans = min(ans, query(p << 1, l, mid, ql, qr));
        if (mid < qr) ans = min(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
} tr;

namespace FastIOT
{
    const int bsz=1<<18;
    char bf[bsz],*head,*tail;
    inline char gc(){if(head==tail)tail=(head=bf)+fread(bf,1,bsz,stdin);if(head==tail)return 0;return *head++;}
    template<typename T>inline void read(T &x){T f=1;x=0;char c=gc();for(;c>'9'||c<'0';c=gc())if(c=='-')f=-1;
    for(;c<='9'&&c>='0';c=gc())x=(x<<3)+(x<<1)+(c^48);x*=f;}
    template<typename T>inline void print(T &x){if(x<0)putchar(45),x=-x;if(x>9)print(x/10);puchar(x%10+48);}
    template<typename T>inline void println(T &x){print(x);putchar('\n');}
}
using namespace FastIOT;


void solve() {
    int n, c; read(n); read(c);
    vector<vector<int>> a(n + 1);
    vector<vector<int>> pos(c + 1);
    vector<int> cnt(c + 1, 0);
    vector<int> T(n + 1);
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
        read(x[i]); read(T[i]);
        a[i].resize(T[i] + 1);
        for (int j = 1; j <= T[i]; ++j) {
            read(a[i][j]);
            cnt[a[i][j]]++;
        }
    }
    sort(id + 1, id + 1 + n, [&](const int &l, const int &r) {
        return x[l] < x[r];
    });
    vector<int> tot(c + 1, 0);
    for (int j = 1; j <= c; ++j)
        pos[j].resize(cnt[j] + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= T[id[i]]; ++j) {
            int col = a[id[i]][j];
            pos[col][++tot[col]] = i;
        }
    }
    tr.build(1, 1, n);
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j < tot[i]; ++j) {
            int pre = pos[i][j], suf = pos[i][j + 1];
            int l = pre, r = suf;
            int p = l;
            while (l <= r) {
                int mid = l + r >> 1;
                if (x[id[mid]] - x[id[pre]] <= x[id[suf]] - x[id[mid]]) {
                    p = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }
            tr.update(1, 1, n, pre, p, -x[id[pre]], 1);
            tr.update(1, 1, n, p + 1, suf, x[id[suf]], -1);
        }
        if (pos[i][1] != 1) tr.update(1, 1, n, 1, pos[i][1] - 1, x[id[pos[i][1]]], -1);
        if (pos[i][tot[i]] != n) tr.update(1, 1, n, pos[i][tot[i]] + 1, n, -x[id[pos[i][tot[i]]]], 1);
    }
    printf("%lld\n", tr.query(1,1,n,1,n));
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; read(T); while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
