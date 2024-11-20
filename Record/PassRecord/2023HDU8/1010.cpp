#include <cmath>
#include <random>
#include <vector>
#include <limits.h>
#include <iostream>
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

#define int long long

vector<int> sqr;
int cnt;

void solve(int cas) {
    ll a, b; cin >> a >> b;
    //1
    for (int i = cnt - 1; i >= 0; --i) {
        if (sqr[i] == abs(a - b)) {
            cout << 1 << '\n';
            return ;
        }
    }
    int det = abs(a - b);
    if (det % 2) {
        cout << 2 << '\n';
        return ;
    }
    if (det % 4 == 0) {
        cout << 2 << '\n';
        return ;
    }
    int l = cnt - 1;
    for (int i = 0; i < cnt; ++i) {
        if  (sqr[i] > det) break;
        while (l >= 0 && sqr[l] > det - sqr[i]) l--;
        if (det - sqr[i] == sqr[l]) {
            cout << 2 << '\n';
            return ;
        }
    }
    cout << 3 << '\n';

}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    for (int i = 1; i * i <= 1000000000; ++i) {
        sqr.pb(i * i);
        cnt++;
    }
    int T; cin >> T; while (T--)
    solve(1);
    return 0;
}
