#include <cctype>
#include <climits>
#include <iostream>
#include <random>
#include <set>
using namespace std;

#define ll        long long
#define ull       unsigned long long
#define fir       first
#define sec       second
#define pii       pair<int, int>
#define pll       pair<long long, long long>
#define lowbit(a) (a & (-a))
#define SZ(a)     ((int)a.size())
#define all(a)    a.begin(), a.end()

constexpr int N = 2e5 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353;
constexpr int dir[4][2] = {
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1},
};

mt19937_64 rnd(random_device{}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX); // use dist(rnd)

void solve() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    vector<string> t(n);
    set<string> st;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        st.insert(t[i]);
    }
    int m = s.length(), Ans = 0;
    for (int i = 0; i < m; ++i) {
        int j = i;
        while (j < m && !isalpha(s[j])) j++;
        string tmp;
        while (j < m && isalpha(s[j])) {
            tmp += tolower(s[j]);
            j++;
        }
        i = j;
        if (tmp != "") {
            if (!st.count(tmp)) {
                Ans++;
                st.insert(tmp);
            }
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}



