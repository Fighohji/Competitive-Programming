#include <array>
#include <cassert>
#include <climits>
#include <iostream>
#include <map>
#include <random>
#include <utility>
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

map<string, int> p {
    {"Shadow", 6},
    {"Gale", 5},
    {"Ranger", 4},
    {"Anvil", 7},
    {"Vexia", 3},
    {"Guardian", 8},
    {"Thunderheart", 6},
    {"Frostwhisper", 2},
    {"Voidclaw", 3},
    {"Ironwood", 3},
    {"Zenith", 4},
    {"Seraphina", 1},
};

void solve() {
    array<int, 2> tot{}, cnt{};
    vector loc(3, array<int, 2>{});
    vector hero(3, array<vector<string>, 2>());
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            int n;
            cin >> n;
            for (int k = 0; k < n; ++k) {
                string s;
                cin >> s;
                hero[i][j].push_back(s);
                assert(p.count(s) > 0);
                loc[i][j] += p[s];
            }
            int tmp = 0;
            for (int k = 0; k < n; ++k) {
                if (hero[i][j][k] == "Thunderheart") {
                    if (n == 4) {
                        loc[i][j] += 6;
                    }
                }
                if (hero[i][j][k] == "Zenith") {
                    if (i == 1) {
                        loc[i][j] += 5;
                    }
                }
                if (hero[i][j][k] == "Seraphina") {
                    loc[i][j] += n - 1;
                }
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (loc[i][0] < loc[i][1]) {
            cnt[1]++;
        }
        if (loc[i][0] > loc[i][1]) {
            cnt[0]++;
        }
        for (int j = 0; j < 2; ++j) {
            tot[j] += loc[i][j];
        }
    }
    auto x = make_pair(cnt[0], tot[0]);
    auto y = make_pair(cnt[1], tot[1]);
    if (x > y) {
        cout << "Player 1";
    } else if (x < y) {
        cout << "Player 2";
    } else {
        cout << "Tie";
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
