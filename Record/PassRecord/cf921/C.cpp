#include <map>
#include <set>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <tuple>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define db double
#define fir first
#define sec second
#define eps (1e-8)
#define pb push_back
#define ll long long
#define mkp make_pair
#define eb emplace_back
#define pii pair<int, int>
#define lowbit(a) (a & (-a))
#define SZ(a) ((int)a.size())
#define ull unsigned long long
#define all(a) a.begin(), a.end()
#define split cout << "=========\n";
#define pll pair<long long, long long>
#define equals(a, b) (fabs((a) - (b)) < eps)

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

void solve() {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    vector<pii> seg;
    int l = 0, r = 0;
    while (l < m && r < m) {
        vector<int> buc(k);
        int cnt = 0;
        while (r < m && cnt < k) {
            if (!buc[s[r] - 'a']) cnt++;
            buc[s[r] - 'a'] = 1;
            ++r;
        }
        if (cnt == k) seg.pb({l, r});
        l = r;
    }
    if (SZ(seg) < n) {
        if (seg.empty() || seg.back().sec != m) {
            if (seg.empty()) {
                seg.pb({0, m});
            } else
                seg.pb({seg.back().sec, m});
        }
        cout << "No\n";
        vector<char> Ans(n, 'a');
        for (int i = 0; i < n; ++i) {
            vector<int> las(k, -1);
            if (SZ(seg) > i) {
                for (int j = seg[i].fir; j < seg[i].sec; ++j) {
                    las[s[j] - 'a'] = j;
                }
            }
            int mx = 0;
            for (int j = 0; j < k; ++j) {
                if (las[j] == -1) {
                    Ans[i] = (char)(j + 'a');
                    break;
                }
                if (mx < las[j]) {
                    mx = las[j];
                    Ans[i] = (char)(j + 'a');
                }
            }
        }
        for (auto i : Ans) cout << i;
        cout << '\n';
    } else {
        cout << "Yes\n";
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
