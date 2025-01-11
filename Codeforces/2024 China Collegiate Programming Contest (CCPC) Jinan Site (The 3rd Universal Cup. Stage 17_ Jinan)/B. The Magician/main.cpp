#include <climits>
#include <cstring>
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

int mp[300];
int dp[5][5][5][5][3][1 << 6];

void solve() {
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    vector<string> s(n);
    array<int, 5> cnt{};
    int Ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        cnt[mp[s[i][1]]]++;
    }
    for (int i = 0; i < 4; ++i) {
        Ans += cnt[i] / 5;
        cnt[i] %= 5;
    }
    int S = 0;
    vector<int> sp(6);
    for (int i = 0; i < 6; ++i) {
        cin >> sp[i];
        S += (sp[i] << i);
    }
    int Max = 0;
    auto dfs = [&](auto self, array<int, 5> arr, int sta,
                   int tmp) -> void {
        auto &[a, b, c, d, e] = arr;
        if (a >= 5) {
            a -= 5;
            tmp++;
        }
        if (b >= 5) {
            b -= 5;
            tmp++;
        }
        if (c >= 5) {
            c -= 5;
            tmp++;
        }
        if (d >= 5) {
            d -= 5;
            tmp++;
        }
        if (e >= 5) {
            e -= 5;
            tmp++;
        }
        if (tmp <= dp[a][b][c][d][e][sta]) return;
        dp[a][b][c][d][e][sta] = tmp;
        Max = max(Max, tmp);
        for (int j = 0; j < 4; ++j) {
            if (!(sta >> j & 1)) continue;
            vector<int> num{0, 1, 2, 3};
            num.erase(num.begin() + j);
            for (int x = 0; x <= arr[num[0]]; ++x) {
                for (int y = 0; y <= arr[num[1]]; ++y) {
                    for (int z = 0; z <= arr[num[2]]; ++z) {
                        if (x + y + z > 3) continue;
                        auto nxt = arr;
                        nxt[num[0]] -= x;
                        nxt[num[1]] -= y;
                        nxt[num[2]] -= z;
                        nxt[j] += x + y + z;
                        self(self, nxt, sta ^ (1 << j), tmp);
                    }
                }
            }
        }
        if (sta >> 4 & 1) {
            for (int i = 0; i < 4; ++i) {
                if (!arr[i]) continue;
                auto nxt = arr;
                nxt[i]--, nxt[4]++;
                self(self, nxt, sta ^ (1 << 4), tmp);
            }
        }
        if (sta >> 5 & 1) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (i == j) continue;
                    if (!arr[i] || !arr[j]) continue;
                    auto nxt = arr;
                    nxt[i]--, nxt[j]++;
                    self(self, nxt, sta ^ (1 << 5), tmp);
                }
            }
        }
        if (arr[4]) {
            for (int i = 0; i < 4; ++i) {
                auto nxt = arr;
                nxt[4]--, nxt[i]++;
                self(self, nxt, sta, tmp);
            }
        }
    };
    dfs(dfs, cnt, S, 0);
    cout << Ans + Max << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mp['D'] = 0, mp['C'] = 1, mp['H'] = 2, mp['S'] = 3;
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
