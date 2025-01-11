#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <random>
#include <string>
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

bool isprime(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    vector<int> prime;
    int cnt = 0;
    auto dfs = [&](auto self, int p, int w, int val) -> void {
        if (p == 9) return;
        cnt++;
        if (isprime(val)) prime.push_back(val);
        for (int i = w + 1; i <= 9; ++i) {
            self(self, p + 1, i, val * 10 + i);
        }
    };
    for (int i = 1; i <= 9; ++i) {
        dfs(dfs, 0, i, i);
    }
    vector<string> data;
    for (auto i : prime) {
        data.push_back(to_string(i));
    }
    sort(all(data), [&](string &a, string &b) {
        return a.length() < b.length();
    });
    
    for (int i = (int)data.size() - 1, j = 0; i >= data.size() - 20; --i, ++j) {
        freopen((to_string(j) + ".in").c_str(), "w", stdout);
        cout << data[i] << '\n';
        fclose(stdout);
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

