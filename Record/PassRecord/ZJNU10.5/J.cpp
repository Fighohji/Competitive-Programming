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

struct Info {
    int type;
    string l, r;
};

struct Object {
    set<int> variable[26];
    Object() { }
};

int trans(char c) {
    if (!c) return 0;
    return c >= 'a' ? c - 'a' : c - 'A';
}

void solve() {
    int n; cin >> n;
    vector<Info> equ(n);
    vector<Object> object(26);
    set<int> Pointer[26];
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> equ[i].l >> tmp >> equ[i].r;
        if (equ[i].l.length() == 1 && equ[i].r.length() == 1) {
            if (isupper(equ[i].l[0])) equ[i].type = 1;
            else equ[i].type = 2;
        } else {
            if (equ[i].l.length() == 3) equ[i].type = 3;
            else equ[i].type = 4;
        }
        cout << equ[i].type << '\n';
    }
    while (1) {
        bool flag = 0;

        for (int i = 0; i < n; ++i) {
            if (equ[i].type == 1) {
                if (Pointer[trans(equ[i].l[0])].count(trans(equ[i].r[0]))) continue;
                Pointer[trans(equ[i].l[0])].insert(trans(equ[i].r[0]));
                flag = 1;
            } else if (equ[i].type == 2) {
                for (auto j : Pointer[trans(equ[i].r[0])]) {
                    if (Pointer[trans(equ[i].l[0])].count(j)) continue;
                    Pointer[trans(equ[i].l[0])].insert(j);
                    flag = 1;
                }
            } else if (equ[i].type == 3) {
                for (auto k : Pointer[trans(equ[i].l[0])]) {
                    for (auto j : Pointer[trans(equ[i].r[0])]) {
                        if (object[k].variable[trans(equ[i].l[2])].count(j)) continue;
                        object[k].variable[trans(equ[i].l[2])].insert(j);
                        flag = 1;
                    }
                }
            } else {
                for (auto k : Pointer[trans(equ[i].r[0])]) {
                    for (auto j : object[k].variable[trans(equ[i].r[2])]) {
                        if (Pointer[trans(equ[i].l[0])].count(j)) continue;
                        Pointer[trans(equ[i].l[0])].insert(j);
                        flag = 1;
                    }
                }
            }
        }

        if (!flag) break;
    }
    for (int i = 0; i < 26; ++i) {
        cout << (char)(i + 'A') << ": ";
        for (auto ob : Pointer[i]) {
            cout << (char)(ob + 'a');
        }
        cout << '\n';
    }
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
