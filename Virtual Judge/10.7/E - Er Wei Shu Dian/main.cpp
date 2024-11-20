#include <algorithm>
#include <array>
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

struct Fenwick {
    int MX;
    vector<ll> sum;
    Fenwick() {}
    Fenwick(int _MX) : MX(_MX) { sum = vector<ll>(_MX + 1); }
    void upd(int x, int val) {
        while (x <= MX) {
            sum[x] += val;
            x += lowbit(x);
        }
    }
    ll qry(int x) {
        ll res = 0;
        while (x) {
            res += sum[x];
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> p(n);
    vector<int> tmp;
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
        tmp.push_back(p[i][0]);
        tmp.push_back(p[i][1]);
    }
    sort(all(tmp));
    tmp.erase(unique(all(tmp)), tmp.end());
    for (int i = 0; i < n; ++i) {
        p[i][0] = lower_bound(all(tmp), p[i][0]) - tmp.begin() + 1;
        p[i][1] = lower_bound(all(tmp), p[i][1]) - tmp.begin() + 1;
    }
    ll Ans = 0;
    Fenwick f(tmp.size());
    vector y(tmp.size() + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        y[p[i][0]].push_back(p[i][1]);
    }
    for (int i = 1; i <= tmp.size(); ++i) {
        for (auto j : y[i]) {
            Ans += f.qry(j - 1);
        }
        for (auto j : y[i]) {
            f.upd(j, 1);
        }
    }
    f = Fenwick(tmp.size());
    for (int i = 1; i <= tmp.size(); ++i) {
        reverse(all(y[i]));
        for (auto j : y[i]) {
            Ans += f.qry(tmp.size()) - f.qry(j);
        }
        for (auto j : y[i]) {
            f.upd(j, 1);
        }
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
