#include <cinttypes>
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
constexpr int maxn = 5e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 1e9 + 7; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

constexpr int len = 500000;
// #define int long long
struct SegTree {
    int sum[maxn << 2], lazy[maxn << 2]; bool cnt[maxn << 2];

    inline void build(int p, int l, int r, int val) {
        lazy[p]=1;
        cnt[p] = 1;
        if (l == r) {
            sum[p] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, val);
        build(p << 1 | 1, mid + 1, r, val);
        sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
    }

    inline void push(int p) {
        if (lazy[p] != 1) {
            lazy[p << 1] = 1ll * lazy[p << 1] * lazy[p] % mod;
            lazy[p << 1 | 1] = 1ll * lazy[p << 1 | 1] * lazy[p] % mod;
            sum[p << 1] = 1ll * sum[p << 1] * lazy[p] % mod;
            sum[p << 1 | 1] = 1ll * sum[p << 1 | 1] * lazy[p] % mod;
            lazy[p] = 1;
        }
    }

    inline void update(int p, int l, int r, int ql, int qr, int val, bool flag) {
        if (!cnt[p]) return ;
        if (ql > qr) return ;
        if (ql <= l && r <= qr) {
            sum[p] = 1ll * sum[p] * val % mod;
            lazy[p] = 1ll * lazy[p] * val % mod;
            if (!val) cnt[p] &= flag;
            return ;
        }
        push(p);
        int mid = (l + r) >> 1;
        if (ql <= mid) update(p << 1, l, mid, ql, qr, val, flag);
        if (mid < qr) update(p << 1 | 1, mid + 1, r, ql, qr, val, flag);
        sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
    }

    inline void add(int p, int l, int r, int pos, int val)
    {
        if(l == r) {
            sum[p] += val;
            sum[p] %= mod;
            return ;
        }
        push(p);
        int mid = (l + r) >> 1;
        if (pos <= mid) add(p << 1, l, mid, pos, val);
        else add(p << 1 | 1, mid + 1, r, pos, val);
        sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
    }
    inline int query(int p, int l, int r, int pos) {
        if (!cnt[p]) return 0;
        if (l == r) return sum[p];
        int mid = (l + r) >> 1;
        push(p);
        if (pos <= mid) return query(p << 1, l, mid, pos);
        else return query(p << 1 | 1, mid + 1, r, pos);
    }
} tr[2];

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


int l1, r1, l2, r2, n;
void solve() {
    read(n);

    tr[0].build(1, 1, len, 1);
    tr[1].build(1, 1, len, 0);
    // for (int i = 1; i <= 4 * len; ++i) tr[1].lazy[i] = 1;
    int L = 1, R = len;
    int L2 = 1, R2 = len;
    for (int i = 1; i <= n; ++i) {

        read(l1); read(r1);
        read(l2); read(r2);

        if (l1 > l2 || l1 == l2 && r1 > r2) {
            swap(l1, l2);
            swap(r1, r2);
        }
        if (r1 < l2) {

            int pre0 = tr[0].query(1,1,len,l1);
            int pre1 = tr[0].query(1,1,len,l2);

            tr[0].update(1, 1, len, L, l1, 0, 0);
            tr[0].update(1, 1, len, r2 + 1, R, 0, 0);

            L = max(L, l1);
            R = min(R, r2 + 1);

            tr[1].update(1, 1, len, L2, l1 - 1, 0, 1);
            tr[1].update(1, 1, len, r2 + 1, R2, 0, 1);

            L2 = max(L2, l1 - 1);
            R2 = min(R2, r2 + 1);

            tr[0].update(1, 1, len, r1 + 1, l2 - 1, 0, 0);
            tr[1].update(1, 1, len, r1 + 1, l2 - 1, 0, 1);


            tr[1].add(1, 1, len, l1, pre0);
            tr[1].add(1, 1, len, l2, pre1);

        } else if(r2 >= r1){

            int pre0 = tr[0].query(1,1,len,l1);
            int pre1 = tr[0].query(1,1,len,l2);

            tr[0].update(1, 1, len, L, l1, 0, 0);
            tr[0].update(1, 1, len, r2 + 1, R, 0, 0);

            L = max(L, l1);
            R = min(R, r2 + 1);

            tr[1].update(1, 1, len, L2, l1 - 1, 0, 1);
            tr[1].update(1, 1, len, r2 + 1, R2, 0, 1);

            L2 = max(L2, l1 - 1);
            R2 = min(R2, r2 + 1);

            tr[0].update(1, 1, len, l2 + 1, r1, 2, 0);

            tr[1].update(1, 1, len, l2, r1, 2, 1);

            tr[1].add(1, 1, len, l1, pre0);
            tr[1].add(1, 1, len, l2, pre1);
        } else {
            int pre0 = tr[0].query(1,1,len,l1);
            int pre1 = tr[0].query(1,1,len,l2);

            tr[0].update(1, 1, len, 1, l1, 0, 0);
            tr[0].update(1, 1, len, r1 + 1, len, 0, 0);

            tr[1].update(1, 1, len, 1, l1 - 1, 0, 1);
            tr[1].update(1, 1, len, r1 + 1, len, 0, 1);


            tr[0].update(1, 1, len, l2 + 1, r2, 2, 0);


            tr[1].update(1, 1, len, l2, r2, 2, 1);

            tr[1].add(1, 1, len, l1, pre0);
            tr[1].add(1, 1, len, l2, pre1);

        }
    }
    printf("%d\n", tr[1].sum[1]);
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
