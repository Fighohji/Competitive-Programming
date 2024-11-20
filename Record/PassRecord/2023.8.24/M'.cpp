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
    vector<int>a(k + 1), b(k + 1);
    for(int i = 1; i <= k; ++i)
    {
        cin >> a[i] >> b[i];
    }
    reverse(a.begin() + 1, a.end());
    reverse(b.begin() + 1, b.end());
    vector<int>ck(n + 1, 0);
    int s; cin >> s;
    for(int i = 1; i <= s; ++i)
    {
        int x; cin >> x;
        ck[x] = 1;
    }
    string Ans = "";
    for(int i = 1; i <= k; ++i)
    {
        // cout << i << ' ' << Ans << '\n';
        if(!ck[a[i]] && ck[b[i]])
        {
            Ans += 'T';
            ck[b[i]] = 0;
        }
        else Ans += 'N';
    }
    reverse(all(Ans));
    for(int i = 1; i <= n; ++i)
    {
        if(ck[i])
        {
            cout << "NIE\n";
            return ;
        }
    }
    cout << "TAK\n";
    cout << Ans << '\n';
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
