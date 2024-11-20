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

constexpr int maxn = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};


void solve() {
    int n; cin >> n;
    vector<pii> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i].sec >> vec[i].fir;
        vec[i].sec--;
    }
    sort(vec.begin() + 1, vec.end());
    int pos = -1;
    for (int i = 1; i <= n; ++i) {
        if (vec[i].fir >= 0) {
            pos = i;
            break;
        }
    }
    int AnsL = 0, AnsR = 0;
    if (pos == -1) {
        AnsR += 2;
        pos = n;
    } else {
        bool flag = 1;
        for (int i = pos; i < n; ++i) {
            if (vec[i].fir == vec[i + 1].fir) {
                flag = 0;
                break;
            } else if (vec[i].fir + 1 == vec[i + 1].fir && vec[i].sec != vec[i + 1].sec) {
                flag = 0;
                break;
            }
        }
        AnsR += flag;
    }
    if (vec[pos].fir > 0) pos--;
    if (pos <= 0) {
        AnsL += 2;
    } else {
        bool flag = 1;
        for (int i = pos; i > 1; --i) {
            if (vec[i].fir == vec[i - 1].fir) {
                flag = 0;
                break;
            } else if (vec[i].fir == vec[i - 1].fir + 1 && vec[i].sec != vec[i - 1].sec) {
                flag = 0;
                break;
            }
        }
        AnsR += flag;
    }
    bool f = 0;
    for (int i = 1; i <= n; ++i) {
        if (vec[i].fir == 0 && vec[i].sec == 1) {
            f = 1;
        }
    }
    int Ans = AnsL + AnsR;
    if (!f) {
        vec.pb({0, 1});
        sort(vec.begin() + 1, vec.end());
        n++;
        int pos = -1;
        for (int i = 1; i <= n; ++i) {
            if (vec[i].fir >= 0) {
                pos = i;
                break;
            }
        }
        int AnsL = 0, AnsR = 0;
        if (pos == -1) {
            AnsR += 2;
            pos = n;
        } else {
            bool flag = 1;
            for (int i = pos; i < n; ++i) {
                if (vec[i].fir == vec[i + 1].fir) {
                    flag = 0;
                    break;
                } else if (vec[i].fir + 1 == vec[i + 1].fir && vec[i].sec != vec[i + 1].sec) {
                    flag = 0;
                    break;
                }
            }
            AnsR += flag;
        }
        if (vec[pos].fir > 0) pos--;
        if (pos <= 0) {
            AnsL += 2;
        } else {
            bool flag = 1;
            for (int i = pos; i > 1; --i) {
                if (vec[i].fir == vec[i - 1].fir) {
                    flag = 0;
                    break;
                } else if (vec[i].fir == vec[i - 1].fir + 1 && vec[i].sec != vec[i - 1].sec) {
                    flag = 0;
                    break;
                }
            }
            AnsR += flag;
        }
        Ans = min(AnsL + AnsR + 1, Ans);
    }
    cout << Ans << '\n';
}

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
