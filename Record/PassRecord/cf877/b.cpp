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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    if (pos[1] <= pos[n] && pos[n] <= pos[2] || pos[2] <= pos[n] && pos[n] <= pos[1]) {
        cout << 1 << ' ' << 1 << '\n';
        return ;
    }
    if (abs(pos[a[1]] - pos[a[2]]) == 1) {
        swap(pos[1], pos[n]);
        if (pos[1] <= pos[n] && pos[n] <= pos[2] || pos[2] <= pos[n] && pos[n] <= pos[1]) {
            cout << pos[1] << ' ' << pos[n] << '\n';
        } else {
            swap(pos[1], pos[n]);
            cout << pos[2] << ' ' << pos[n] << '\n';
        }
    } else {
        cout << min(pos[1], pos[2]) + 1 << ' ' << pos[n] << '\n';
    }
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--) {
        solve(1);
    }
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}



