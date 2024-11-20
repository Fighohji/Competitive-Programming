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
constexpr int mod = 1e9 + 7;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

#define int long long

constexpr array<int, 4> prime{2, 3, 5, 7};
vector<pair<int, array<int, 4>>> buc;

void init() {
    for (int i = 1; i <= 100000; ++i) {
        int tmp = i;
        array<int, 4> cnt{};
        for (int j = 0; j < 4; ++j) {
            while (tmp % prime[j] == 0) {
                tmp /= prime[j];
                cnt[j]++;
            }
        }
        if (tmp == 1) buc.emplace_back(i, cnt);
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> val(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    vector<array<int, 4>> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        int tmp = s[i - 1] - '0';
        for (int j = 0; j < 4; ++j) {
            while (tmp % prime[j] == 0) {
                tmp /= prime[j];
                pre[i][j] += val[i];
            }
            pre[i][j] += pre[i - 1][j];
        }
    }
    int Ans = 0;
    for (const auto &[len, val] : buc) {
        for (int i = 0; i + len <= n; ++i) {
            array<int, 4> check;
            for (int j = 0; j < 4; ++j)
                check[j] = pre[i + len][j] - pre[i][j];
            Ans += val == check;
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
