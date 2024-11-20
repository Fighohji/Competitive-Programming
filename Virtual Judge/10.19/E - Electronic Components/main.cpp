#include <climits>
#include <iostream>
#include <random>
#include <queue>
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
#define int long long
struct node
{
    int f, t, id;
    bool operator<(const node &a) const 
    {
        return t < a.t;
    }
} a[1010];
int p[10000010];
int tot = 0;
void solve() {
    int n; cin >> n;
    priority_queue<node> q;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].f >> a[i].t;
        a[i].id = i;
        q.push(a[i]);
    }
    ll Ans = 0;
    while(q.size() > 1)
    {
        node t1 = q.top(); q.pop();
        node t2 = q.top(); q.pop();
        if(t1.f > t2.f)        
        {
            Ans += t2.f * t1.t;
            q.push({t1.f - t2.f, t1.t});
            for(int i = 0; i < t2.f; ++i)
            {
                p[++tot] = t2.id;
            }
        }
        else if(t1.f == t2.f)
        {
            Ans += t2.f * t1.t;
            for(int i = 0; i < t2.f; ++i)
            {
                p[++tot] = t2.id;
            }
        }
        else 
        {
            Ans += t1.f * t1.t;
            q.push({t2.f - t1.f, t2.t});
            for(int i = 0; i < t1.f; ++i)
            {
                p[++tot] = t2.id;
            }
        }
    }
    // cout << Ans << '\n';
    if(q.size() == 1)
    {
        node t = q.top();
        if(t.f > 1)
        {
            while(tot > 0 && p[tot] == t.id)
            {
                tot--;
            }
            while(tot > 0 && t.f > 1)
            {
                if(a[p[tot]].t < 2 * t.t)
                {
                    t.f -= 2;
                    Ans += a[p[tot]].t;
                    tot--;
                }
                else break;
            }
        }
        Ans += t.t * t.f;
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
