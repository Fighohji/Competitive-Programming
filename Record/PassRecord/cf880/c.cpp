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

#define int ll

void solve(int cas) {
    int A, B, C; ll k; cin >> A >> B >> C >> k;
    // split
    if (C > max(A, B) + 1 || C < max(A, B)) {
        cout << "-1\n";
        return ;
    }
    if (C == max(A, B)) {
        int be = 1;
        int mx = 1;
        for (int i = 1; i < A; ++i)
            be *= 10;
        int bem;
        for (int i = 1; i < max(A, B); ++i)
            mx *= 10;
        bem = mx;
        mx = mx * 10 - 1;
        int maxb = 9;
        int minb = 1;
        for (int j = 1; j < B; ++j) {
            maxb = maxb * 10 + 9;
            minb = minb * 10;
        }
        for (int i = be; i <= be * 10 - 1; ++i) {
            int id = mx - i;
            if (id < minb) continue;
            maxb = min(id, maxb);
            int now = maxb - minb + 1;
            if (k > now) {
                k -= now;
            } else {
                cout << i << " + " << minb + k - 1 << " = " << i + minb + k - 1 << '\n';
                return ;
            }
        }
        if (k)
            cout << "-1\n";
    } else {
        int be = 1;
        int mx = 1;
        for (int i = 1; i < A; ++i)
            be *= 10;
        int bem;
        int maxb = 9;
        int minb = 1;
        for (int j = 1; j < B; ++j) {
            maxb = maxb * 10 + 9;
            minb = minb * 10;
        }
        for (int i = 1; i <= max(A, B); ++i)
            mx *= 10;
        bem = mx;// mul min
        mx = mx * 10 - 1;
        for (int i = be; i <= be * 10 - 1; ++i) {
            int id = bem - i;
            if (id > maxb) continue;
            id = max(id, minb);
            int now = (maxb - id + 1);
            if (k > now) {
                k -= now;
            } else {
                cout << i << " + " << id + k - 1 << " = " << i + id + k - 1 << '\n';
                return ;
            }
        }
        if (k)
            cout << "-1\n";
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

