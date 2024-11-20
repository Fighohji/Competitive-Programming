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
constexpr int maxn = 1e6 + 50;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF =  0x3f3f3f3f3f3f3f3f;
constexpr int mod = 998244353; /* 1e9 + 7 */
constexpr int dir[8][2] = {-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};

mt19937_64 rnd(random_device {}());
uniform_int_distribution<ull> dist(0, ULLONG_MAX);//use dist(rnd)
#define endl '\n'
bool BEGIN;
struct Base {
    int lim = 63;
    bool Zero = 0; //一定要特判0！！！
    vector<ll> pos;
    vector<ll> ps;
    Base() { pos.resize(lim + 1, 0); }
    bool insert(ll p) {
        if (p == 0) {
            Zero = 1;
            return 0;
        }
        for (int i = lim; i >= 0; --i) {
            if (p & 1ll << i) {
                if (!pos[i]) {
                    pos[i] = p;
                    ps.push_back(p);
                    return 1;
                }
                p ^= pos[i];
            }
        }
        Zero = 1;
        return 0;
    }
};
ll n;
ll mas[N];
void solve() {
    cin>>n;
    Base B;
    B.ps.clear();
    ll m=(1<<n)-1;
    // cout<<"m "<<m<<endl;
    for(int i=1;i<=m;++i) cin>>mas[i];
    sort(mas+1,mas+1+m);
    for(int i=1;i<=m;++i)
    {
        B.insert(mas[i]);
    }
    while(B.ps.size()<n) B.ps.push_back(0);
    sort(B.ps.begin(),B.ps.begin()+n);

    // for(int i=0;i<n;++i) cout<<B.ps[i]<<" ";
    //     cout<<endl;
    vector<ll> vt;
    for(int s=1;s<=m;++s)
    {
        ll ans=0;
        // cout<<s<<' ';
        for(int i=0;i<n;++i)
        {
            if(s&(1<<i))
            {
                // cout<<i<<" ";
                ans^=B.ps[i];
            }
        }
        // cout<<ans<<endl;
        // cout<<endl;
        vt.push_back(ans);
    }

    sort(vt.begin(),vt.end());
    // for(int i=0;i<vt.size();++i) cout<<vt[i]<<' ';
    //     cout<<endl;
    for(int i=0;i<vt.size();++i)
    {
        // cout<<vt[i]<<' '<<mas[i]<<endl;
        if(vt[i]!=mas[i+1])
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=0;i<n;++i) cout<<B.ps[i]<<' ';
        cout<<endl;
}

bool END;
signed main() {
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T--)
    solve();
    // cout << ((&END - & BEGIN) >> 21) << '\n';
    return 0;
}
