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

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;


void solve(int cas) {
    string s; cin >> s;
    int n = SZ(s), ans;
    vector<int> val(5);
    val[0] = 1;
    for (int i = 1; i < 5; ++i)
        val[i] = val[i - 1] * 10;
    vector<int> fi(5, INF), ed(5, -1);
    for (int i = 0; i < n; ++i) {
        fi[s[i] - 'A'] = min(fi[s[i] - 'A'], i);
        ed[s[i] - 'A'] = max(ed[s[i] - 'A'], i);
    }
    auto get = [&](const string &s) -> int {
        vector<array<int, 5>> suf(n + 1, {0, 0, 0, 0, 0});
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1];
            suf[i][s[i] - 'A']++;
        }
        int Ans = 0;
        for (int i = 0; i < n; ++i) {
            int now = s[i] - 'A';
            int res = 0;
            for (int j = now + 1; j < 5; ++j)
                res += suf[i + 1][j];
            if (res) Ans -= val[now];
            else Ans += val[now];
        }
        return Ans;
    };
    ans = get(s);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (fi[i] != INF) {
                string ns = s;
                ns[fi[i]] = char(j + 'A');
                ans = max(ans, get(ns));
            }
            if (ed[i] != -1) {
                string bs = s;
                bs[ed[i]] = char(j + 'A');
                ans = max(ans, get(bs));
            }
        }
    }
    cout << ans << '\n';
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin>>T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
