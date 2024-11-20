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


void solve() {
    string s; cin >> s;
    vector<char> ch, st = {'1'};
    for (auto i : s) {
        if (i == '+') {
            ch.pb(i);
            if (st.back() == '1' && SZ(ch) > 1) {
                st.pb('?');
            } else if (st.back() == '1') {
                st.pb('1');
            } else if (st.back() == '0') {
                st.pb('0');
            } else {
                st.pb('?');
            }
        } else if (i == '-') {
            ch.pop_back();
            st.pop_back();
        } else if (i == '0') {
            if (st.back() == '1') {
                cout << "NO\n";
                return ;
            } else if (st.back() == '?') {
                st.back() = '0';
            }
        } else {
            if (st.back() == '0') {
                cout << "NO\n";
                return ;
            } else if (st.back() == '?') {
                for (int j = SZ(st) - 1; j >= 1; --j) {
                    if (st[j] != '?') break;
                    st[j] = '1';
                }
            }
        }
    }
    cout << "YES\n";
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
