#include <cassert>
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

map<string, bool> vis;

bool check(const string &s) {
    if (vis.count(s)) return 0;
    return 1;
}

int ask(const string &s) {
    if (!check(s)) return 0;
    cout << "? " << s << endl;
    int x;
    cin >> x;
    if (!x) vis[s] = 1;
    return x;
}

void solve() {
    vis.clear();
    int n;
    cin >> n;
    int f = ask("1");
    string Ans = (f ? "1" : "0");
    if (!f) vis["1"] = 0;
    while (Ans.length() < n) {
        if (ask(Ans + char(48 + f))) {
            Ans += char(48 + f);
        } else {
            break;
        }
    }
    // padding left
    while (Ans.length() < n) {
        if (ask("0" + Ans)) {
            Ans = "0" + Ans;
        } else if (ask("1" + Ans)) {
            Ans = "1" + Ans;
        } else {
            break;
        }
    }
    // padding right
    while (Ans.length() < n) {
        if (ask(Ans + "0")) {
            Ans = Ans + "0";
        } else if (ask(Ans + "1")) {
            Ans = Ans + "1";
        } else {
            break;
        }
    }
    assert(Ans.length() == n);
    cout << "! " << Ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
