#include <climits>
#include <iostream>
#include <map>
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
    int n;
    cin >> n;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i)
        cin >> a[i];
    map<int, int> buc;
    for (int i = 0; i < n * n; ++i) {
        buc[a[i]]++;
    }
    vector<int> Ans;
    while (!buc.empty()) {
        auto [x, y] = *buc.rbegin();
        buc[x]--;
        if (!buc[x]) buc.erase(x);
        for (int i : Ans) {
            buc[gcd(i, x)] -= 2;
            if (!buc[gcd(i, x)]) buc.erase(gcd(i, x));
        }
        Ans.push_back(x);
    }
    for (auto i : Ans) {
        cout << i << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
