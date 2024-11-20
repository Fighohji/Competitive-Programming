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

deque<int> have, heap;
vector<int> seq[4];

bool get(int x) {
    if (heap.empty()) return 0;
    for (int i = 0; i < x; ++i) {
        have.push_back(heap.front());
        heap.pop_front();
    }
    return 1;
}

void solve() {
    seq[0] = seq[1] = {1};
    seq[2] = seq[3] = {100};

    for (int i = 2; i <= 99; ++i) {
        int x; cin >> x;
        heap.push_back(x);
    }

    //start
    get(8);

    bool flag = 1;
    while (1) {
        if (have.empty()) break;
        bool inv = 0, ord = 0;
        for (int j = 0; j < have.size(); ++j) {
            int x = have[j];

            for (int i = 0; i < 2; ++i) {
                if (x == seq[i].back() - 10) {
                    seq[i].pb(x);
                    inv = 1;
                    break;
                }
            }

            if (!inv)
                for (int i = 2; i < 4; ++i) {
                    if (x - 10 == seq[i].back()) {
                        seq[i].pb(x);
                        inv = 1;
                        break;
                    }
                }


            if (inv) {
                have.erase(have.begin() + j);
                break;
            }
        }

        if (!inv) {
            int id1 = -1, id2 = -1, Min = INF;
            for (int j = 0; j < have.size(); ++j) {
                int x = have[j];

                for (int i = 0; i < 2; ++i) {
                    if (x > seq[i].back()) {
                        int det = x - seq[i].back();
                        if (det < Min) {
                            id1 = j;
                            id2 = i;
                            Min = det;
                        }
                    }
                }
                for (int i = 2; i < 4; ++i) {
                    if (x < seq[i].back()) {
                        int det = seq[i].back() - x;
                        if (det < Min) {
                            id1 = j;
                            id2 = i;
                            Min = det;
                        }
                    }
                }
                // if (x == 6) {
                //     for (auto i : have)
                //         cout << i << ' ';
                //     cout << "@@@@\n";
                //     cout << id1 << ' ' << id2 << '\n';
                // }
            }

            if (id1 != -1) {
                ord = 1;
                seq[id2].pb(have[id1]);
                have.erase(have.begin() + id1);
            }

        }

        if (!ord && !inv) break;
        flag ^= 1;
        if (flag)
            get(2);
    }
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < SZ(seq[i]); ++j)
            cout << seq[i][j] << " \n"[j == SZ(seq[i]) - 1];
    while (!have.empty()) {
        cout << have.front() << ' ';
        have.pop_front();
    }
    cout << '\n';
    while (!heap.empty()) {
        cout << heap.front() << ' ';
        heap.pop_front();
    }
    cout << '\n';
}

/*
96 69 40 94 35 7 53 88 10 89 47 37 16 61 24 46 90 6 33 25 63 73 26 81 2 45
77 75 48 57 66 34 59 92 44 11 31 18 9 52 91 50 8 98 5 64 86 62 83 4 19
3 27 97 28 36 23 76 58 30 38 12 39 78 41 56 80 67 70 99 13 42 17 49 84
22 32 29 54 71 51 74 79 95 72 15 87 21 65 68 60 85 55 43 93 20 82 14
*/

/*
87 31 58 56 82 93 9 68 65 41 26 64 3 11 5 84 24 46 16 30 14 85 52 12 91 75
96 17 47 37 76 69 78 49 25 28 48 81 95 63 34 43 27 74 80 62 53 83 40 71
72 35 23 21 51 66 55 61 67 32 38 29 60 39 4 18 20 77 7 94 59 42 79 10
92 97 57 2 86 33 89 90 88 19 22 99 45 44 73 70 50 6 15 98 54 13 36 8
*/

signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
