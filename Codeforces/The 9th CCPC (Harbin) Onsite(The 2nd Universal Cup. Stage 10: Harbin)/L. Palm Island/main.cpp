#include <climits>
#include <iostream>
#include <random>
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
    int n;
    cin >> n;
    vector<int> a(n), b(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i]--;
    }
    for (int i = 0; i < n; ++i) {
        p[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        a[i] = p[a[i]];
    }
    vector<int> Ans;
    for (int i = 1; i < n; ++i) {
        int id = 0;
        while (a[id] != i) ++id, Ans.push_back(1);
        vector<int> c = a;
        for (int j = 0; j < n; ++j) 
            c[(j - id + n) % n] = a[j];
        a = c;
        id = n - 1;
        int cnt = 0;
        while (i && a[id] != i - 1) {
            id = (id + 1) % n;
            cnt++;
            if (id == 0) id++;
            Ans.push_back(2);
        }
        if (cnt) {
            c = a;
            for (int j = 1; j < n; ++j) {
                c[((j - 1 - cnt) % (n - 1) + n - 1) % (n - 1) + 1] = a[j];
            }
        }
        a = c;
        Ans.push_back(1);
        int tmp = a[0];
        for (int i = 1; i < n; ++i)
            a[i - 1] = a[i];
        a[n - 1] = tmp;
    }
    // for (auto i : a) {
    //     cerr << i << ' ';
    // }
    // cerr << '\n';
    for (auto i : Ans) {
        cout << i;
    }
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
