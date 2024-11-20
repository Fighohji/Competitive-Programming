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

struct SAIS {
    // 后缀类型
    #define L_TYPE 0
    #define S_TYPE 1

    int ss[maxn];
    int rl[maxn],rk[maxn],lcp[maxn];
    int n;
    // int st[30][maxn];

    void init(const string &s) {
        n = s.size();
        for (int i=1; i <= n; ++i) ss[i] = s[i-1];
        // st中的字符必须调成正数!!!!!!!!!!!!!!
    }

    // 判断一个字符是否为LMS字符
    inline bool is_lms_char(int *type, int x) {
        return x > 1 && type[x] == S_TYPE && type[x - 1] == L_TYPE;
    }

    // 判断两个LMS子串是否相同
    inline bool equal_substring(int *S, int x, int y, int *type) {
        do {
            if (S[x] != S[y])
                return false;
            x++, y++;
        } while (!is_lms_char(type, x) && !is_lms_char(type, y));

        return S[x] == S[y] && type[x] == type[y];
    }

    // 诱导排序(从*型诱导到L型、从L型诱导到S型)
    // 调用之前应将*型按要求放入SA中
    inline void induced_sort(int *S, int *SA, int *type, int *bucket, int *lbucket,
                            int *sbucket, int n, int SIGMA) {
        for (int i = 1; i <= n; i++)
            if (SA[i] > 1 && type[SA[i] - 1] == L_TYPE)
                SA[lbucket[S[SA[i] - 1]]++] = SA[i] - 1;
        for (int i = 0; i <= SIGMA; i++)  // Reset S-type bucket
            sbucket[i] = bucket[i];
        for (int i = n; i >= 1; i--)
            if (SA[i] > 1 && type[SA[i] - 1] == S_TYPE)
                SA[sbucket[S[SA[i] - 1]]--] = SA[i] - 1;
    }

    // SA-IS主体
    // S是输入字符串，length是字符串的长度, SIGMA是字符集的大小
    int *sais(int *S, int length, int SIGMA) {
        int n = length;
        assert(S[n]==0);
        int *type = new int[n + 5];  // 后缀类型
        int *position = new int[n + 5];  // 记录LMS子串的起始位置
        int *name = new int[n + 5];  // 记录每个LMS子串的新名称
        int *SA = new int[n + 5];  // SA数组
        int *bucket = new int[SIGMA + 5];  // 每个字符的桶
        int *lbucket = new int[SIGMA + 5];  // 每个字符的L型桶的起始位置
        int *sbucket = new int[SIGMA + 5];  // 每个字符的S型桶的起始位置

        // 初始化每个桶
        memset(bucket, 0, sizeof(int) * (SIGMA + 5));
        for (int i = 1; i <= n; i++)
            bucket[S[i]]++;
        for (int i = 0; i <= SIGMA; i++) {
            if (i==0) {
                bucket[i] = bucket[i];
                lbucket[i] = 1;
            } else {
                bucket[i] += bucket[i - 1];
                lbucket[i] = bucket[i - 1] + 1;
            }
            sbucket[i] = bucket[i];
        }

        // 确定后缀类型(利用引理2.1)
        type[n] = S_TYPE;
        for (int i = n - 1; i >= 1; i--) {
            if (S[i] < S[i + 1])
                type[i] = S_TYPE;
            else if (S[i] > S[i + 1])
                type[i] = L_TYPE;
            else
                type[i] = type[i + 1];
        }
        // 寻找每个LMS子串
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (is_lms_char(type,i))
                position[++cnt] = i;
        // 对LMS子串进行排序
        fill(SA, SA + n + 3, -1);
        for (int i = 1; i <= cnt; i++)
            SA[sbucket[S[position[i]]]--] = position[i];
        induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

        // 为每个LMS子串命名
        fill(name, name + n + 3, -1);
        int lastx = -1, namecnt = 1;  // 上一次处理的LMS子串与名称的计数
        bool flag = false;  // 这里顺便记录是否有重复的字符
        for (int i = 2; i <= n; i++) {
            int x = SA[i];

            if (is_lms_char(type, x)) {
                if (lastx >= 0 && !equal_substring(S, x, lastx, type))
                    namecnt++;
                // 因为只有相同的LMS子串才会有同样的名称
                if (lastx >= 0 && namecnt == name[lastx])
                    flag = true;

                name[x] = namecnt;
                lastx = x;
            }
        }  // for
        name[n] = 0;

        // 生成S1
        int *S1 = new int[cnt+5];
        int pos = 0;
        for (int i = 1; i <= n; i++)
            if (name[i] >= 0)
                S1[++pos] = name[i];
        int *SA1;
        if (!flag) {
            // 直接计算SA1
            SA1 = new int[cnt + 5];

            for (int i = 1; i <= cnt; i++)
                SA1[S1[i]+1] = i;
        } else
            SA1 = sais(S1, cnt, namecnt);  // 递归计算SA1

        // 从SA1诱导到SA
        for (int i = 0; i <= SIGMA; i++) {
            if (i==0)
                lbucket[i] = 1;
            else
                lbucket[i] = bucket[i - 1] + 1;
            sbucket[i] = bucket[i];
        }
        fill(SA, SA + n + 3, -1);
        for (int i = cnt; i >= 1; i--)  // 这里是逆序扫描SA1，因为SA中S型桶是倒序的
            SA[sbucket[S[position[SA1[i]]]]--] = position[SA1[i]];
        induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

        delete[] S1;
        delete[] SA1;
        delete[] bucket;
        delete[] lbucket;
        delete[] sbucket;
        delete[] position;
        delete[] type;
        delete[] name;
        return SA;
    }

    void build() {
        ss[0] = ss[n + 2] = -1;
        ss[n + 1] = 0;
        int SIGMA = 0;
        for (int i = 1; i <= n; ++i) SIGMA = max(SIGMA, ss[i]);
        int * sa = sais(ss, n+1, SIGMA);
        for (int i = 2; i <= n + 1; ++i) rk[sa[i]] = i - 1;
        delete[] sa;
        for (int i = 1; i <= n; ++i) rl[rk[i]] = i;
        for (int i = 1,len = 0; i <= n; ++i) {
            if (len) --len;
            while (i + len <= n && rl[rk[i] - 1] + len <= n && ss[i + len] == ss[rl[rk[i] - 1] + len]) ++len;
            lcp[rk[i]] = len;
        }
    }


    #undef L_TYPE
    #undef R_TYPE
}sa;

struct SegTree {
    int sum[maxn << 2];

    void build(int p, int l, int r) {
        if (l == r) {
            sum[p] = INF;
            return ;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
    }

    void update(int p, int l, int r, int pos, ll val) {
        if (l == r) {
            sum[p] = val;
            return ;
        }
        int mid = l + r >> 1;
        if (pos <= mid) update(p << 1, l, mid, pos, val);
        else update(p << 1 | 1, mid + 1, r, pos, val);
        sum[p] = min(sum[p << 1], sum[p << 1 | 1]);
    }

    ll query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return sum[p];
        int mid = (l + r) >> 1;
        ll ans = INF;
        if (ql <= mid) ans = min(ans, query(p << 1, l, mid, ql, qr)) ;
        if (mid < qr) ans = min(ans, query(p << 1 | 1, mid + 1, r, ql, qr));
        return ans;
    }
} seg;

void solve() {
    int n; cin >> n; string s; cin >> s;
    sa.init(s); sa.build();
    vector<int> ans(n + 1);
    seg.build(1, 0, n);
    seg.update(1, 0, n, 0, n + 1);
    for (int i = n; i >= 1; --i) {
        ans[i] = seg.query(1, 0, n, 0, sa.rk[i] - 1) - i;
        seg.update(1, 0, n, sa.rk[i], i);
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
