#include <climits>
#include <cmath>
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

vector<int> prime;
bool vis[1000005];
#define int long long
map<int, vector<pii>> rec;
void solve() {
    ll x;
    cin >> x;
    ll _ = x;
    if (rec.count(x)) {
        const auto &tmp = rec[x];
        cout << tmp.size() << '\n';
        for (auto &[x, y] : tmp) {
            cout << x << ' ' << y << '\n';
        }
        return ;
    }
    vector<pii> Ans;
    for (int i = 2; i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) Ans.push_back({i, cnt});
    }
    if (x != 1) {
        Ans.push_back({x, 1});
    }
    cout << Ans.size() << '\n';
    for (auto &[x, y] : Ans) {
        cout << x << ' ' << y << '\n';
    }
    rec[_] = Ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // vis[1] = 1;
    // for (int i = 2; i <= 1000000; ++i) {
    //     if (!vis[i]) prime.push_back(i);
    //     else continue;
    //     for (int j = i + i; j <= 1000000; j += i) {
    //         vis[j] = 1; 
    //     }
    // }
    // cerr << prime.size() << '\n';
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
