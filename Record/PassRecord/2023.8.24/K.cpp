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
    int n, k; cin >> n >> k;
    vector<string> mp(n);
    vector<pii> op1, op2;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i) {
        cin >> mp[i];
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] == 'x') {
                x++;
                op1.pb({i + 1, j + 1});
            }
            if (mp[i][j] == 'o') {
                y++;
                op2.pb({i + 1, j + 1});
            }
            if (mp[i][j] == '.') z++;
        }
    }
    auto check = [&](vector<string> &s) -> bool {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                if (s[i][j] == '.') continue;
                for (int p = 0; p < 8; ++p) {
                    bool f = 1;
                    for (int o = 1; o < k; ++o) {
                        int ni = i + dir[p][0] * o, nj = j + dir[p][1] * o;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            if (s[ni][nj] != s[i][j]) {
                                f = 0;
                                break;
                            }
                        } else {
                            f = 0;
                            break;
                        }
                    }
                    if (f) return 1;
                }
            }
        return 0;
    };
    bool flag = check(mp);
    int posx = -1, posy = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mp[i][j] == '.') continue;
            vector<string> np = mp;
            np[i][j] = '.';
            if (check(np)) continue;
            else {
                posx = i, posy = j;
                break;
            }
        }
        if (posx != -1) break;
    }
    if (!flag && z) {
        cout << "NIE\n";
        return ;
    }
    if (abs(x - y) > 1) {
        cout << "NIE\n";
    } else {
        if (flag && posx != -1) {
            op1.clear(); op2.clear();
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j) {
                    if (i == posx && j == posy) continue;
                    if (mp[i][j] == 'x') op1.pb({i + 1, j + 1});
                    else if (mp[i][j] == 'o') op2.pb({i + 1, j + 1});
                }
            if (x < y && mp[posx][posy] == 'x' || y < x && mp[posx][posy] == 'o') {
                cout << "NIE\n";
            } else {
                cout << "TAK\n";
                posx++, posy++;
                if (x > y) {
                    for (int i = 0; i < SZ(op2); ++i) {
                        cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                        cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                    }
                    cout << posx << ' ' << posy << '\n';
                } else if (x == y) {
                    if (SZ(op1) > SZ(op2)) {
                        for (int i = 0; i < SZ(op2); ++i) {
                            cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                            cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                        }
                        cout << op1.back().fir << ' ' << op1.back().sec << '\n';
                        cout << posx << ' ' << posy << '\n';
                    } else {
                        for (int i = 0; i < SZ(op1); ++i) {
                            cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                            cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                        }
                        cout << op2.back().fir << ' ' << op2.back().sec << '\n';
                        cout << posx << ' ' << posy << '\n';
                    }
                } else {
                    for (int i = 0; i < SZ(op2); ++i) {
                        cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                        cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                    }
                    cout << posx << ' ' << posy << '\n';
                }
            }
        } else if (flag && posx == -1) {
            cout << "NIE\n";
        } else {
            cout << "TAK\n";
            if (x > y) {
                for (int i = 0; i < SZ(op2); ++i) {
                    cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                    cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                }
                cout << op1.back().fir << ' ' << op1.back().sec << '\n';
            } else {
                for (int i = 0; i < SZ(op1); ++i) {
                    cout << op2[i].fir << ' ' << op2[i].sec << '\n';
                    cout << op1[i].fir << ' ' << op1[i].sec << '\n';
                }
                if (y > x) cout << op2.back().fir << ' ' << op2.back().sec << '\n';
            }
        }
    }
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
