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
// constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
ll mod;
mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

// struct Matrix {
//     int siz;
//     __int128 mat[101][101];
//     Matrix () { };
//     Matrix (int _siz, __int128 _x = 0) {
//         siz = _siz;
//         for (int i = 1; i <= siz; ++i)
//             mat[i][i] = _x;
//     };
//     void init() {
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 mat[i][j] = 0;
//     }
//     Matrix operator+(const Matrix &t) {
//         Matrix ans = Matrix(siz);
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 ans.mat[i][j] = mat[i][j] + t.mat[i][j];
//         return ans;
//     }
//     Matrix operator-(const Matrix &t) {
//         Matrix ans = Matrix(siz);
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 ans.mat[i][j] = mat[i][j] - t.mat[i][j];
//         return ans;
//     }
//     Matrix operator*(const Matrix &t) {
//         Matrix ans = Matrix(siz);
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 for (int k = 1; k <= siz; ++k)
//                     ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * t.mat[k][j])%mod;
//         return ans;
//     }
//     Matrix operator*(const ll &t) {
//         Matrix ans = Matrix(siz);
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 ans.mat[i][j] = mat[i][j] * t;
//         return ans;
//     }
//     Matrix operator/(const ll &t) {
//         Matrix ans = Matrix(siz);
//         for (int i = 1; i <= siz; ++i)
//             for (int j = 1; j <= siz; ++j)
//                 ans.mat[i][j] = mat[i][j] / t;
//         return ans;
//     }
//     Matrix operator +=(const Matrix &t) { return (*this) = (*this) + t; }
//     Matrix operator -=(const Matrix &t) { return (*this) = (*this) - t; }
//     Matrix operator *=(const Matrix &t) {return (*this) = (*this) * t; }
//     Matrix operator *=(const ll &t) { return (*this) = (*this) * t; }
//     Matrix operator /=(const ll &t) { return (*this) = (*this) / t; }
//     Matrix qpow(ll power) {
//         Matrix tmp = (*this);
//         (*this) = Matrix(siz, 1);
//         while (power) {
//             if (power & 1) (*this) = (*this) * tmp;
//             tmp = tmp * tmp;
//             power >>= 1;
//         }
//         return (*this);
//     }
//     // void print() {
//     //     for (int i = 1; i <= siz; ++i)
//     //         for (int j = 1; j <= siz; ++j)
//     //             cout << mat[i][j] << " \n"[j == siz];
//     // }
// } mt;


struct Matrix {
    // __unsignedint128 mat[10][10];
    int siz;
    Matrix () { };
    Matrix (int _siz, __int128 _x = 0) {
        siz = _siz;
        for (int i = 1; i <= siz; ++i)
            for (int j = 1; j <= siz; ++j)
                mat[i][j] = 0;
        for (int i = 1; i <= siz; ++i)
            mat[i][i] = _x;
    }
    Matrix operator*(const Matrix &t) {
        Matrix ans = Matrix(siz);
        for (int i = 1; i <= siz; ++i)
            for (int j = 1; j <= siz; ++j)
                for (int k = 1; k <= siz; ++k)
                    ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * t.mat[k][j] % mod) %mod;
        return ans;
    }
    Matrix qpow(ll power) {
        Matrix tmp = (*this);
        (*this) = Matrix(siz, 1);
        while (power) {
            if (power & 1) (*this) = (*this) * tmp;
            tmp = tmp * tmp;
            power >>= 1;
        }
        return (*this);
    }
} mt;

__int128 read(string s) {
    __int128 res = 0;
    for (auto i : s) {
        res = res * 10 + i - '0';
    }
    return res;
}

void solve() {
    string s; cin >> s;
    ll a, b, m;
    a = read(s);
    cin >> s;
    b = read(s);
    cin >> m;
    m = read(s);
    mod = m;
    mt.siz = 2;
    mt.mat[1][1] = 0;
    mt.mat[1][2] = 1;
    mt.mat[2][1] = m - 1;
    mt.mat[2][2] = a % m;
    mt.qpow(b);
    __int128 ans = mt.mat[1][1] * 2 % m + mt.mat[1][2] * a % m;
    ans %= m;
    vector<int> dig;
    while (ans) {
        dig.pb(ans % 10);
        ans /= 10;
    }
    reverse(all(dig));
    if (dig.empty()) {
        cout << 0 << '\n';
        return ;
    }
    for (auto i : dig) cout << i;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
