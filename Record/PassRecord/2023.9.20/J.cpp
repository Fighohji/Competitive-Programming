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
    vector a(9, vector<int>(9));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> a[i][j];
    while (1) {
        bool flag = 0;
        for (int i = 0; i < 9 && !flag; ++i)
            for (int j = 0; j < 9 && !flag; ++j) {
                if (a[i][j]) continue;
                vector<bool> vis(10);
                for (int k = 0; k < 9; ++k) {
                    vis[a[i][k]] = 1;
                    vis[a[k][j]] = 1;
                }
                int x = i / 3, y = j / 3;
                for (int k = x * 3; k < x * 3 + 3; ++k)
                    for (int p = y * 3; p < y * 3 + 3; ++p)
                        vis[a[k][p]] = 1;
                int cnt = 0, las = 0;
                for (int k = 1; k <= 9; ++k) {
                    cnt += (vis[k] == 0);
                    if (!vis[k]) las = k;
                }
                if (cnt == 1) {
                    a[i][j] = las;
                    flag = 1;
                    break;
                }
            }

        vector Vis(10, vector<vector<int>>(9, vector<int>(9)));
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (!a[i][j]) continue;
                for (int k = 1; k <= 9; ++k) Vis[k][i][j] = 1;
                for (int k = 0; k < 9; ++k) {
                    Vis[a[i][j]][i][k] = 1;
                    Vis[a[i][j]][k][j] = 1;
                }
                int x = i / 3, y = j / 3;
                for (int k = x * 3; k < x * 3 + 3; ++k)
                    for (int p = y * 3; p < y * 3 + 3; ++p)
                        Vis[a[i][j]][k][p] = 1;
            }
        // cout << a[6][1] << '\n';
        for (int i = 0; i < 9; ++i) {

            for (int j = 0; j < 9; ++j) {
                if (a[i][j]) continue;
                for (int k = 1; k <= 9; ++k) {
                    int cnt = 0;
                    for (int p = 0; p < 9; ++p)
                        if (!Vis[k][i][p])
                            cnt++;
                    if (cnt == 1 && !Vis[k][i][j]) {
                        a[i][j] = k;
                        flag = 1;
                        break;
                    }
                    cnt = 0;
                    for (int p = 0; p < 9; ++p)
                        if (!Vis[k][p][j])
                            cnt++;
                    if (cnt == 1 && !Vis[k][i][j]) {
                        a[i][j] = k;
                        flag = 1;
                        break;
                    }
                    cnt = 0;
                    int x = i / 3, y = j / 3;
                    for (int o = x * 3; o < x * 3 + 3; ++o)
                        for (int p = y * 3; p < y * 3 + 3; ++p)
                            if (!Vis[k][o][p]) cnt++;
                    if (cnt == 1 && !Vis[k][i][j]) {
                        a[i][j] = k;
                        flag = 1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        // if (C == 0) {
        //     for (int i = 0; i < 9; ++i)
        //         for (int j = 0; j < 9; ++j) {
        //             cout << Vis[5][i][j] << " \n"[j == 8];
        //         }
        // }
        if (!flag) break;

    }
    int cnt = 0;
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cnt += (a[i][j] == 0);
    if (cnt) {
        cout << "Not easy\n";
    } else {
        cout << "Easy\n";
    }
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cout << (a[i][j] ? (char)(a[i][j] + '0') : '.') << " \n"[j == 8];
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
