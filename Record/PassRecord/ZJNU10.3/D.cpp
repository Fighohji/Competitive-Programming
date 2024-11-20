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


string s;
ll n, m;
ll now, len;

void solve() {
    cin >> n >> m;
    cin >> s;
    len = s.length();
    vector<int> S(len), A(n), B(m);
    if (len < n * m || len > 2 * n * m) {
        cout << "Impossible\n";
        return ;
    }
    for (int i = 0; i < len; ++i) {
        S[i] = s[i] - '0';
    }
    for (int i = 1; i < 10; ++i) {
        now = 0;
        int j = 0;
        for (;j < len && now < m;) {
            if (S[j] % i == 0 && S[j] / i < 10) {
                B[now++] = S[j] / i;
                j++;
            } else if (j < len - 1 && (S[j] * 10 + S[j + 1]) % i == 0 && (S[j] * 10 + S[j + 1]) / i < 10) {
                B[now++] = (S[j] * 10 + S[j + 1]) / i;
                j += 2;
            } else {
                break;
            }
        }
        if (now == m) {
            A[0] = i;
            auto dfs = [&](auto &&dfs, int place, int pointer) -> bool {
                if (place == n && pointer == len) return 1;
                else if (place == n) return 0;
                int p;
                if (S[pointer] % B[0] == 0) {
                    p = S[pointer] / B[0];
                } else if (pointer < len - 1 && (S[pointer] * 10 + S[pointer + 1]) % B[0] == 0 && (S[pointer] * 10 + S[pointer + 1]) / B[0] < 10) {
                    p = (S[pointer] * 10 + S[pointer + 1]) / B[0];
                } else {
                    return 0;
                }
                string t = "";
                for (int q = 0; q < m; ++q) {
                    int val = B[q] * p;
                    if (val == 0) t += '0';
                    else {
                        string tmp;
                        while (val) {
                            tmp += (char)((val % 10) + '0');
                            val /= 10;
                        }
                        reverse(all(tmp));
                        t += tmp;
                    }
                }
                if (pointer + t.length() <= len && t == s.substr(pointer, t.length())) {
                    pointer += t.length();
                    A[place] = p;
                    if (dfs(dfs, place + 1, pointer)) return 1;
                }
                return 0;
            };
            bool f = dfs(dfs, 1, j);
            if (f) {
                for (int i = 0; i < n; ++i) {
                    cout << A[i];
                }
                cout << ' ';
                for (int i = 0; i < m; ++i) {
                    cout << B[i];
                }
                cout << '\n';
                return ;
            }
        }
    }
    cout << "Impossible\n";
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    return 0;
}
