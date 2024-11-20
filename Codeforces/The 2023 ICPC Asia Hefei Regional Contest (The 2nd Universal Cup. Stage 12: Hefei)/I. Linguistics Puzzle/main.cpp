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

map<pii, vector<int>> cnt[53];
int y[53][53 * 53];
void brute() {
    for (int n = 2; n <= 52; ++n) {
        vector<vector<int>> d(n, vector<int>(2));
        auto getDigit = [&](int x) -> void {
            if (x == 0) {
                d[0][0]++;
                return ;
            }
            int tot = 0;
            while (x) {
                d[x % n][tot]++;
                x /= n;
                tot++;
            }
        };
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int val = i * j;
                y[n][val]++;
                getDigit(val);
            }
        for (int i = 0; i < n; ++i) {
            cnt[n][{d[i][0], d[i][1]}].push_back(i);
        }
    }
}

int trans(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}
char back(int c) {
    if (c < 26) return c + 'a';
    return c - 26 + 'A';
}
void solve() {
    int n;
    cin >> n;
    vector<string> s(n * n);
    for (int i = 0; i < n * n; ++i)
        cin >> s[i];
    map<pii, vector<char>> x;
    vector<vector<int>> d(n, vector<int>(2));
    for (int i = 0; i < n * n; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            d[trans(s[i][j])][(int)s[i].length() - j - 1]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        x[{d[i][0], d[i][1]}].push_back(back(i));
    }
    vector<char> Ans(n);
    vector<int> res(n);
    auto check = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            res[trans(Ans[i])] = i;
        }
        vector<int> ch(n * n);
        for (int i = 0; i < n * n; ++i) {
            int w = 0;
            for (int j = 0, k = (s[i].length() > 1 ? n : 1); j < s[i].length(); ++j, k /= n) {
                w += k * res[trans(s[i][j])];
            }
            ch[w]++;
        }
        for (int i = 0; i < n * n; ++i) {
            if (ch[i] != y[n][i]) return 0;
        }
        return 1;
    };
    auto dfs = [&](auto self, map<pii, vector<int>>::iterator it) -> bool {
        if (it == cnt[n].end()) {
            if (check()) return 1;
            return 0;
        }
        auto [pir, vec] = *it;
        if (vec.size() == 1) {
            Ans[vec[0]] = x[pir][0];
            if (self(self, next(it))) return 1;
        } else if (vec.size() == 2) {
            Ans[vec[0]] = x[pir][0];
            Ans[vec[1]] = x[pir][1];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][1];
            Ans[vec[1]] = x[pir][0];
            if (self(self, next(it))) return 1;
        } else if (vec.size() == 3) {
            Ans[vec[0]] = x[pir][0];
            Ans[vec[1]] = x[pir][1];
            Ans[vec[2]] = x[pir][2];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][0];
            Ans[vec[1]] = x[pir][2];
            Ans[vec[2]] = x[pir][1];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][1];
            Ans[vec[1]] = x[pir][0];
            Ans[vec[2]] = x[pir][2];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][1];
            Ans[vec[1]] = x[pir][2];
            Ans[vec[2]] = x[pir][0];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][2];
            Ans[vec[1]] = x[pir][0];
            Ans[vec[2]] = x[pir][1];
            if (self(self, next(it))) return 1;
            Ans[vec[0]] = x[pir][2];
            Ans[vec[1]] = x[pir][1];
            Ans[vec[2]] = x[pir][0];
            if (self(self, next(it))) return 1;
        }
        return 0;
    };
    dfs(dfs, cnt[n].begin());
    for (int i = 0; i < n; ++i) {
        cout << Ans[i];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    brute();
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
