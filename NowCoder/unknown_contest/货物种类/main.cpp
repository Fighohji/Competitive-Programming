#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> L(n + 1), R(n + 1);
    vector<int> tmp;
    for (int i = 1; i <= m; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        L[l].push_back(d);
        R[r].push_back(d);
        tmp.push_back(d);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 1; i <= n; ++i) {
        for (auto &j : L[i]) j = lower_bound(all(tmp), j) - tmp.begin();
        for (auto &j : R[i]) j = lower_bound(all(tmp), j) - tmp.begin();
    }
    int Ans = 1, Max = 0;
    vector<int> cnt(tmp.size());
    int tot = 0;
    auto add = [&](int x) -> void {
        if (!cnt[x]) tot++;
        cnt[x]++;
    };
    auto del = [&](int x) -> void {
        cnt[x]--;
        if (!cnt[x]) tot--;
    };
    for (int i = 1; i <= n; ++i) {
        for (auto j : L[i]) add(j);
        if (tot > Max) {
            Ans = i;
            Max = tot;
        }
        for (auto j : R[i]) del(j);
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
