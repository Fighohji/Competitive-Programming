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
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    if (n == 1) {
        if (k % 2) {
            s[0] = (s[0] - '0') ^ 1 + '0';
        }
        cout << s << '\n';
        return ;
    }
    int cnt = 0;
    int l = 0, r = 0;
    int cnt0 = 0;
    while (l < n && r < n) {
        while (l < n && s[l] == '1') l++;
        r = l;
        bool f = 0;
        while (r < n && s[r] == '0') {
            cnt0++;
            r++;
            f = 1;
        }
        cnt += f;
        l = r;
    }
    if (cnt >= k) {
        l = 0, r = 0;
        while (l < n && r < n) {
            if (!k) break;
            while (l < n && s[l] == '1') l++;
            r = l;
            bool f = 0;
            while (r < n && s[r] == '0') {
                s[r] = '1';
                r++;
                f = 1;
            }
            k -= f;
            l = r;
        }
        cout << s << '\n';
    } else {
        ll res = k - cnt;
        if (res % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                cout << '1';
            }
        } else {
            if (cnt0 == 0 && k == 1) {
                for (int i = 0; i < n - 1; ++i) {
                    cout << '1';
                }
                cout << '0';
            } else {
                for (int i = 0; i < n; ++i) {
                    cout << '1';
                }
            }
        }
        cout << '\n';
    }
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
