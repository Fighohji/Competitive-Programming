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
    string s, t; cin >> s >> t;
    int T, q; cin >> T >> q;
    int n = SZ(s);
    int res = 0, need = n;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) {
            res++;
        }
    }
    queue<pii> que;
    for (int i = 1; i <= q; ++i) {
        while (!que.empty()) {
            auto [x, y] = que.front();
            if (i - x >= T) {
                que.pop();
                need++;
                if (s[y] == t[y]) {
                    res++;
                }
            } else {
                break;
            }
        }
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            x--;
            need--;
            if (s[x] == t[x]) {
                res--;
            }
            que.emplace(i, x);
        } else if (op == 2) {
            int id1, id2, pos1, pos2;
            cin >> id1 >> pos1 >> id2 >> pos2;
            pos1--, pos2--;
            if (id1 == id2) {
                if (s[pos1] == t[pos1]) res--;
                if (s[pos1] == t[pos2]) res++;
                if (s[pos2] == t[pos2]) res--;
                if (s[pos2] == t[pos1]) res++;
                if (id1 == 1) {
                    swap(s[pos1], s[pos2]);
                } else {
                    swap(t[pos1], t[pos2]);
                }
            } else {
                if (id1 > id2) {
                    swap(pos1, pos2);
                    swap(id1, id2);
                }
                int now = 0;
                if (s[pos1] == t[pos1]) now++;
                if (s[pos2] == t[pos2]) now++;
                res -= now;
                now = 0;
                swap(s[pos1], t[pos2]);
                if (s[pos1] == t[pos1]) now++;
                if (s[pos2] == t[pos2]) now++;
                res += now;
            }
        } else {
            cout << (res == need ? "Yes\n" : "No\n");
        }
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


