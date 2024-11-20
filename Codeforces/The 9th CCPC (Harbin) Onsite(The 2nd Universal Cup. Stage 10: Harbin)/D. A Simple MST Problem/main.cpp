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

constexpr int N = 2e6 + 50;
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

bool vis[N];
vector<int> fac[N], buc[N];
int mul[N];
int prime[N];
int cnt;
void isprime(int n) {
    mul[1] = 1;
    for (int i = 2; i <= n; ++i) {
        mul[i] = 1;
        if (!vis[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 1; i <= cnt; ++i) {
        for (int j = prime[i]; j <= n; j += prime[i]) {
            fac[j].push_back(prime[i]);
            mul[j] *= prime[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        buc[mul[i]].push_back(i);
    }
}

int dis[N], v[N];
void solve() {
    int l, r;
    cin >> l >> r;
    if (r - l <= 200) {
        auto calc = [&](int x, int y) -> int {
            int i = 0, j = 0;
            int res = 0;
            while (i < fac[x].size() && j < fac[y].size()) {
                if (fac[x][i] < fac[y][j]) {
                    res++, i++;
                } else if (fac[x][i] > fac[y][j]) {
                    res++, j++;
                } else {
                    i++, j++, res++;
                }
            }
            res += (int)fac[x].size() - i + (int)fac[y].size() - j;
            return res;
        };
        for (int i = l; i <= r; ++i)
            dis[i] = INF, v[i] = 0;
        dis[l] = 0;
        for (int i = l; i < r; ++i) {
            int x = 0;
            for (int j = l; j <= r; ++j) {
                if (!v[j] && (x == 0 || dis[j] < dis[x])) x = j;
            }
            v[x] = 1;
            for (int y = l; y <= r; ++y) {
                if (!v[y]) { dis[y] = min(dis[y], calc(x, y)); }
            }
        }
        int Ans = 0;
        for (int i = l; i <= r; ++i) {
            Ans += dis[i];
        }
        cout << Ans << '\n';

    } else {
        int Ans = 0;
        vector<int> vs(r + 1);
        vector<int> vec(r + 1);
        for (int i = l; i <= r; i++) {
            vec[i] = i;
        }
        sort(vec.begin() + l, vec.end(), [&](int x, int y) {
            return mul[x] < mul[y];
        });
        vector<int> vvs(r + 1);
        for (int i = l; i <= r; ++i) {
            if (vvs[mul[vec[i]]]) continue;
            vvs[mul[vec[i]]] = 1;
            for (int j = mul[vec[i]] + mul[vec[i]]; j <= r; j += mul[vec[i]]) {
                if (!vs[j]) {
                    vs[j] = 1;
                    for (auto it : buc[j]) {
                        if (it > r) break;
                        if (it < l) continue;
                        Ans += fac[it].size();
                    }
                }
            }
        }
        for (int i = l; i <= r; i++) {
            if (vs[mul[i]] == 0) {
                Ans += fac[i].size() + 1;
                vs[mul[i]] = 2;
            } else if (vs[mul[i]] == 2) {
                Ans += fac[i].size();
            }
        }
        Ans -= 2;
        // for (int i = l; i <= r; ++i) {
        //      if(s.count(mul[i]))
        //      {
        //         Ans += fac[i].size();
        //      }
        //      else
        //      {
        //         s.insert(mul[i]);
        //      }
        // }
        // for(auto x : s)
        //     Ans += (int)fac[x].size() + 1;
        cout << Ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    isprime(1000000);
    int _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
}
