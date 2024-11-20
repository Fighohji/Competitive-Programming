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


struct Hash {
    ull seed, p;
    vector<ull> power, hash;
    Hash(const string &s, ull sd = 131, ll P = 1e9 + 9) {
        seed = sd, p = P;
        power.resize(s.length() + 1);
        hash.resize(s.length() + 1);
        power[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            hash[i] = (hash[i - 1] * seed + s[i - 1]);
            power[i] = power[i - 1] * seed;
        }
    }
    ull get_hash(int l, int r) {
        if (l > r) return 0;
        l++, r++;
        ull a = hash[r];
        ull b = hash[l - 1] * power[r - l + 1];
        return a - b;
    }
};
void solve() {
    int k, n;
    string s;
    cin >> s;
    cin >> n;
    k = s.length();
    Hash tmp(s);
    for (int i = 1; i <= k; ++i) {
        if (k % i) continue;
        bool flag = 1;
        for (int j = 1; j <= k; j += i) {
            if (tmp.get_hash(0, i - 1) != tmp.get_hash(j - 1, j - 1 + i - 1)) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            s = s.substr(0, i);
            break;
        }
    }
    Hash hs(s);
    k = s.length();
    ll Ans = 0;
    set<ull> vis;
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < k; ++i) {
            ll pre = hs.get_hash(k - i, k - 1);
            pre *= hs.power[k];
            pre += hs.get_hash(0, k - 1);
            pre *= hs.power[j];
            pre += hs.get_hash(0, j - 1);
            if (vis.count(pre)) continue;
            vis.insert(pre);
            int tot = (i > 0 ? k : 0) + j + k;
            if (tot > n) continue;
            Ans += (n - tot) / k + 1;
        }
    }
    s = s + s;
    hs = Hash(s);
    set<ull> ns;
    for (int i = 0; i < min(n, 2 * k); ++i) {
        for (int j = i; j < min(n, 2 * k); ++j) {
            ull val = hs.get_hash(i, j);
            if ((j - i + 1) == 2 * k || (j - i + 1) >= k && vis.count(val) || (j - i + 1) < k && ns.count(val))
                continue;
            if (j - i + 1 >= k) vis.insert(val);
            else ns.insert(val);
            Ans++;
        }
    }
    cout << Ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
