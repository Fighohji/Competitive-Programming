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
    int n; cin >> n;
    string s; cin >> s;
    vector<int> sta(n + 1);
    for (int i = 0; i < n; ++i) {
        sta[i + 1] = s[i] - '0';
    }
    vector<int> G(n + 1), deg(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> G[i];
        deg[G[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!deg[i])
            q.push(i);
    }
    vector<int> Ans;
    while (!q.empty()) {
        int p = q.front(); q.pop();
        if (sta[p]) {
            Ans.pb(p);
        }
        sta[G[p]] ^= sta[p];
        sta[p] &= 0;
        deg[G[p]]--;
        if (!deg[G[p]])
            q.push(G[p]);
    }

    vector<bool> vis(n + 1);
    // circle
    for (int i = 1; i <= n; ++i) {
        if (deg[i] && !vis[i]) {
            vector<int> Circle;
            int now = i;
            while (!vis[now]) {
                Circle.pb(now);
                vis[now] = 1;
                now = G[now];
            }
            vector<int> flag;
            for (int j = 0; j < SZ(Circle); ++j) {
                if (sta[Circle[j]])
                    flag.pb(j);
            }
            auto p = Circle;
            for (auto k : p) Circle.pb(k);
            if (SZ(flag) == 0) continue;
            if (SZ(flag) % 2 == 1) {
                cout << "-1\n";
                return ;
            }
            vector<int> b[2];
            int res = 0;
            int tmp = 0;
            for (int j = 0; j < SZ(flag); j += 2) {
                res += flag[j + 1] - flag[j];
                for (int k = flag[j]; k < flag[j + 1]; ++k)
                    b[0].pb(Circle[k]);
            }
            flag.pb(flag[0] + SZ(p));
            tmp = 0;
            for (int j = 1; j < SZ(flag); j += 2) {
                tmp += flag[j + 1] - flag[j];
                for (int k = flag[j]; k < flag[j + 1]; ++k)
                    b[1].pb(Circle[k]);
            }
            if (tmp > res) {
                for (auto j : b[0]) {
                    Ans.pb(j);
                }
            } else {
                for (auto j : b[1]) {
                    Ans.pb(j);
                }
            }

        }
    }

    cout << Ans.size() << '\n';
    for (auto i : Ans) {
        cout << i << ' ';
    }
    cout << '\n';
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
