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
constexpr int maxn = 1e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)

bool BEGIN;

vector<pair<int, int>> seg;
struct SequenceAutoMachine {
    vector<vector<int>> nxt;
    void init(int n, int char_size) {
        nxt.clear();
        nxt.resize(n + 2, vector<int>(char_size, -1));
        for (int i = n; i >= 0; --i) {
            nxt[i] = nxt[i + 1];
            nxt[i][seg[i].fir] = i;
        }
    }
} sq;

string Ans;

void solve(int cas) {
    Ans = "";
    seg.clear();
    string s; cin >> s;
    int cnt = 0, n = s.length();
    int l = 0, r = 0;
    while (l < n && r < n) {
        while (r < n && s[r] == s[l]) r++;
        seg.eb(s[l] - 'a', r - l);
        cnt++;
        l = r;
    }
    cnt--;
    sq.init(cnt, 26);
    if (cnt <= 1) {
        cout << "-1\n";
        return;
    }
    vector<int> id(26, 0);
    for (int i = 0; i < 26; ++i) {
        id[i] = sq.nxt[id[i]][i];
    }
    string tmp = "";
    for (int i = 0; i < 26; ++i) {
        if (id[i] < 0) continue;
        if (cnt - id[i] < 2) continue;
        auto [c, len] = seg[id[i]];
        bool haveSame = sq.nxt[id[i] + 1][i] == -1 ? 0 : 1;
        int maxSameLen = len;
        if (seg[cnt - 1].fir < seg[cnt].fir && seg[cnt - 1].fir < c && (seg[cnt - 1].sec > 1 && seg[cnt - 2].fir == seg[cnt].fir || seg[cnt - 2].fir != seg[cnt].fir)) {
            tmp += (char)(c + 'a');
            for (int j = 0; j < seg[cnt - 1].sec - 1; ++j) {
                tmp += (char)(seg[cnt - 1].fir + 'a');
            }
            tmp += (char)(seg[cnt].fir + 'a');
        }
        if (haveSame) {
            for (int j = id[i] + 1; j <= cnt; ++j)
                if (seg[j].fir == c)
                    maxSameLen = max(maxSameLen, seg[j].sec);
            string res = "";
            if (seg[cnt].fir < c) {
                if (seg[cnt - 1].fir != c) {
                    res += (char)(c + 'a');
                    res += (char)(seg[cnt].fir + 'a');
                } else {
                    for (int j = 0; j <= seg[cnt - 1].sec; ++j) {
                        res += (char)(c + 'a');
                    }
                    res += (char)(seg[cnt].fir + 'a');
                }
            }
            if (seg[cnt - 1].fir < c) {
                if (seg[cnt - 2].fir != c) {
                    Ans += (char)(c + 'a');
                    Ans += (char)(seg[cnt - 1].fir + 'a');
                } else if (seg[cnt - 2].fir == c && cnt - 2 != id[i]) {
                    for (int j = 0; j <= seg[cnt - 2].sec; ++j) {
                        Ans += (char)(c + 'a');
                    }
                    Ans += (char)(seg[cnt - 1].fir + 'a');
                }
            }
            if (Ans == "") Ans = res;
            if (res != "") Ans = min(Ans, res);
            string Res = "";
            for (int j = 0; j <= maxSameLen; ++j) {
                Res += (char)(c + 'a');
            }
            if (Ans == "") Ans = Res;
            else Ans = min(Ans, Res);
        } else {
            int nxtMin = 100, nxtMinPos = -1;
            for (int j = 0; j < 26; ++j) {
                if (sq.nxt[id[i] + 1][j] != -1) {
                    nxtMin = j;
                    nxtMinPos = sq.nxt[id[i] + 1][j];
                    break;
                }
            }
            if (nxtMinPos > id[i] + 1) {
                for (int j = 0; j < len; ++j) {
                    Ans += (char)(c + 'a');
                }
                if (nxtMin < c) Ans.erase(unique(all(Ans)), Ans.end());
                Ans += (char)(nxtMin + 'a');
            } else { //从当前字符段往后是升序段
                for (int j = 0; j < len; ++j) {
                    Ans += (char)(c + 'a');
                }
                while (1) {
                    if (cnt - nxtMinPos == 1) {
                        if (seg[nxtMinPos].fir < seg[nxtMinPos + 1].fir) {
                            for (int j = 0; j < seg[nxtMinPos].sec - 1; ++j) {
                                Ans += (char)(seg[nxtMinPos].fir + 'a');
                            }
                        }
                        Ans += (char)(seg[nxtMinPos + 1].fir + 'a');
                        break;
                    } else {
                        int nxtNxtMinpos = sq.nxt[nxtMinPos + 1][nxtMin];
                        if (nxtNxtMinpos == -1) {
                            for (int j = 0; j < seg[nxtMinPos].sec; ++j) {
                                Ans += (char)(nxtMin + 'a');
                            }
                            int pos = -1, chr;
                            for (int j = 0; j < 26; ++j) {
                                if (sq.nxt[nxtMinPos + 1][j] != -1) {
                                    pos = sq.nxt[nxtMinPos + 1][j];
                                    chr = j;
                                    break;
                                }
                            }
                            if (pos != nxtMinPos + 1) {
                                Ans += (char)(chr + 'a');
                                break;
                            } else {
                                nxtMinPos = pos;
                                nxtMin = chr;
                            }
                        } else {
                            for (int j = 0; j <= seg[nxtMinPos].sec; ++j) {
                                Ans += (char)(nxtMin + 'a');
                            }
                            break;
                        }
                    }
                }
            }
        }
        break;
    }
    if (tmp != "") Ans = min(Ans, tmp);
    cout << Ans << '\n';
}

//bbcbaaaaaa

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    // freopen("input.txt", "r", stdin);
    // freopen("ans.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve(1);
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}
