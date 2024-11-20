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
#define GG { cout << "NO\n"; return; }
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

// mt19937_64 rnd(random_device {}());
// uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


void solve(int cas) {
    int n; cin >> n;
    vector<pii> p(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> p[i].fir >> p[i].sec;
    }
    sort(p.begin() + 1, p.end());
    map<pii, int> dif;
    map<pii, int> cnt;
    for (int i = 2; i <= 2 * n; ++i) {
        cnt[p[i]]++;
    }
    vector<pii> ans;
    for (int i = 2; i <= n + 1; ++i) {
        int difx = p[i].fir - p[1].fir;
        int dify = p[i].sec - p[1].sec;
        if (dif[mkp(difx, dify)] == 1) continue;
        dif[mkp(difx, dify)] = 1;
        map<pii, int> tmp;
        tmp[p[i]]++;
        cnt[p[i]]--;
        bool f = 1;
        int res = n - 1;
        for (int j = 2; j <= 2 * n && res; ++j) {
            if (cnt[p[j]] == 0) continue;
            pii np = {p[j].fir + difx, p[j].sec + dify};
            if (cnt.count(np) && cnt[np]) {
                cnt[np]--;
                tmp[np]++;
                cnt[p[j]]--;
                tmp[p[j]]++;
                res--;
            } else {
                f = 0;
                break;
            }
        }
        if (!f || res) {
            for (auto i : tmp) {
                cnt[i.fir] += i.sec;
            }
        } else {
            ans.eb(difx, dify);
            for (auto i : tmp) {
                cnt[i.fir] += i.sec;
            }
        }
    }
    set<pii> Ans;
    for (auto i : ans) {
        Ans.insert(i);
        Ans.insert({-i.fir, -i.sec});
    }
    cout << SZ(Ans) << '\n';
    for (auto i : Ans) {
        cout << i.fir << ' ' << i.sec << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
