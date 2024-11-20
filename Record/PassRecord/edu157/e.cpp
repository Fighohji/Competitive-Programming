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

struct Card {
    int a, d;
    bool operator<(const Card &t)const {
        return a < t.a;
    }
};

/*

b[0] ^ b[i] = pre[i]
pre distinct
b is a permutation

b[i] = b[0] ^ pre[i]
所以保证max(b) = n - 1即可
*/

/*
B中def >= A 中Max(atk) B可以胜利
数量是 A中防御力小于所有B中防御力大于等于MaxAtkA中的最大atk的数量
*/


/*
A要不输
则必须要出 A中防御力大于等于所有B中防御力大于等于MaxAtkA中的card
A要赢就要打出 防御力大于等于MaxAtkB的card
一种是第一轮打出
另一种是第一轮打出 防御力在上述两个值之间的card
此时就要去看 atk大于当前这张card的防御力的B的card中 防御力最大的牌，
如果小于atkMaxA那这张牌也是胜利
*/

void solve() {
    int n; cin >> n;
    vector<Card> a(n + 1);
    int MaxAtkA = 0, MaxAtkB = 0, MaxDefA = 0, MaxDefB = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].a;
        MaxAtkA = max(MaxAtkA, a[i].a);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].d;
        MaxDefA = max(MaxDefA, a[i].d);
    }
    int m; cin >> m;
    vector<Card> b(m + 1);
    int Max = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].a;
        MaxAtkB = max(MaxAtkB, b[i].a);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].d;
        MaxDefB = max(MaxDefB, b[i].d);
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<int> c(m + 1), d(n + 1);
    for (int i = 1; i <= m; ++i) {
        c[i] = b[i].a;
    }
    for (int i = 1; i <= n; ++i) {
        d[i] = a[i].a;
    }
    vector<int> sufb(m + 2, 0), sufa(n + 2, 0);
    for (int i = m; i >= 1; --i) {
        sufb[i] = max(sufb[i + 1], b[i].d);
    }
    for (int i = n; i >= 1; --i) {
        sufa[i] = max(sufa[i + 1], a[i].d);
    }
    int winb = 0, wina = 0;

    map<int, int> GA, GB;
    for (int i = 1; i <= n; ++i) {
        auto pos = upper_bound(c.begin() + 1, c.end(), a[i].d);
        if (pos == c.end()) continue;
        GA[a[i].d] = sufb[pos - c.begin()];
    }
    for (int i = 1; i <= m; ++i) {
        auto pos = upper_bound(d.begin() + 1, d.end(), b[i].d);
        if (pos == d.end()) continue;
        GB[b[i].d] = sufa[pos - d.begin()];
    }
    map<int, int> AnsA, AnsB;
    for (int i = 1; i <= n; ++i) {
        if (AnsA.count(a[i].d)) continue;
        map<int, bool> visA, visB;
        vector<int> vecA, vecB;
        int now = a[i].d, flag = 0;
        int Ans;
        while (1) {
            if (!flag && visA[now] || flag && visB[now]) {
                Ans = 0;
                break;
            }
            if (!flag) {
                visA[now] = 1;
                vecA.pb(now);
            }
            if (flag) {
                visB[now] = 1;
                vecB.pb(now);
            }
            if (!flag && AnsA.count(now)) {
                Ans = AnsA[now];
                break;
            }
            if (flag && AnsB.count(now)) {
                Ans = AnsB[now];
                break;
            }
            if (!flag && !GA.count(now)) {
                Ans = 1;
                break;
            }
            if (flag && !GB.count(now)) {
                Ans = -1;
                break;
            }

            if (!flag) now = GA[now];
            if (flag) now = GB[now];
            flag ^=  1;
        }
        for (auto j : vecA) AnsA[j] = Ans;
        for (auto j : vecB) AnsB[j] = Ans;
    }
    for (int i = 1; i <= n; ++i) {
        if (AnsA[a[i].d] == 1) wina++;
        else if (AnsA[a[i].d] == -1) winb++;
    }
    cout << wina << ' ' << n - wina - winb << ' ' << winb << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
