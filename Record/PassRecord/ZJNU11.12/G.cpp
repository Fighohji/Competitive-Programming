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
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define N maxn
#define db double
#define il inline
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

constexpr int ON = 0;
constexpr int CW = -1;
constexpr int CCW = 1;
constexpr int BACK = 2;
constexpr int FRONT = -2;
const db pi = acos(-1.000);
constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

void solve() {
    int nt, ns, rmax; cin >> nt >> ns >> rmax;
    vector<pii> p(nt), det(ns);
    map<pii, bool> tr;
    for (int i = 0; i < nt; ++i) {
        cin >> p[i].fir >> p[i].sec;
        tr[p[i]] = 1;
    }
    for (int i = 0; i < ns; ++i)
        cin >> det[i].fir >> det[i].sec;
    vector<pii> ans;
    auto getAns = [&](int fx, int fy) {
        map<pii, int> mp;
        for (int i = 0; i < ns; ++i)
            for (int j = 0; j < nt; ++j)
                mp[{p[j].fir - det[i].fir * fx, p[j].sec - det[i].sec * fy}]++;
        for (auto &[pos, val] : mp) {
            if (val == ns) {
                ans.pb(pos);
            }
        }
    };
    auto gotAns = [&](int fx, int fy) {
        map<pii, int> mp;
        for (int i = 0; i < ns; ++i)
            for (int j = 0; j < nt; ++j)
                mp[{p[j].fir - det[i].sec * fx, p[j].sec - det[i].fir * fy}]++;
        for (auto &[pos, val] : mp) {
            if (val == ns) {
                ans.pb(pos);
            }
        }
    };
    getAns(1, 1); getAns(-1, -1);
    gotAns(1, -1); gotAns(-1, 1);
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    int cnt = 0;
    pii Ans;
    for (auto &i : ans) {
        if (tr.count(i) == 0 && (i.fir == 0 || i.sec == 0)) {
            cnt++;
            Ans = i;
        }
    }
    if (cnt > 1) {
        cout << "Ambiguous\n";
    } else if (!cnt) {
        cout << "Impossible\n";
    } else {
        cout << Ans.fir << ' ' << Ans.sec << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
