#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5, maxK = 10005, INF = 1e18 + 5;
int dis[maxn], n, K, TT, g[maxn], f[maxn], dp[maxn], tot, cnt, len[maxn], t[maxn], st[maxn], lenT;
vector<int> vec;
queue<int> Q;
char S[maxn], T[maxn];
struct TRIE {
    int son[30];
}tr[maxn];
set<int> Slen;
void dij() {
    for(int i = 0; i < K; ++i) g[i] = INF;
    g[0] = 0;
    for(auto L : Slen)
    {
        for(int i = 0; i < K; ++i)
        {
            g[(i + L) % K] = min(g[(i + L) % K], g[i] + 1 + (i + L) / K);
        }
        for(int i = 0; i < K; ++i)
        {
            g[(i + L) % K] = min(g[(i + L) % K], g[i] + 1 + (i + L) / K);
        }
    }
}
void insert(int id) {
    int u = 0;
    for(int i = 1;i <= len[id];i++) {
        int x = vec[st[id] + i - 1]; 
        if(!tr[u].son[x]) {
            tr[u].son[x] = ++ cnt;
            f[cnt] = INF;
        }
        u = tr[u].son[x];
        f[u] = min(f[u], (len[id] - i) / K + g[(len[id] - i) % K] + 1);
//      cout << u << " " << f[u] << " " << (len[id] - i) / K << " " << g[(len[id] - i) % K] << endl;
    }
}
void solve() {
    Slen.clear();
    cin >> n >> K;
    vec.push_back(114514);
    for(int i = 1;i <= n;i++) {
        cin >> S + 1;
        len[i] = strlen(S + 1);
        st[i] = vec.size();
//      t[i] = len[i];
        Slen.insert(len[i]);
        for(int j = 1;j <= len[i];j++) vec.push_back(S[j] - 'a');
    }
    cin >> T + 1;
    lenT = strlen(T + 1);
//  sort(t + 1, t + 1 + n);
//  tot = unique(t + 1, t + 1 + n) - t - 1;
    dij();
    for(int i = 1;i <= n;i++) insert(i);
    dp[0] = 0;
    for(int i = 1;i <= lenT;i++) dp[i] = INF;
    for(int i = 0;i < lenT;i++) {
        int u = 0;
        for(int j = i + 1;j <= lenT;j++) {
//          cout << j << " " << u << " " << T[j] - 'a' << endl;
            if(!tr[u].son[T[j] - 'a']) break;
            u = tr[u].son[T[j] - 'a'];
            dp[j] = min(dp[j], dp[i] + f[u]);
//          cout << i << " " << j << " " << dp[j] << " " << f[u] << endl;
        }
    }
    cout << ((dp[lenT] == INF) ? -1 : dp[lenT]) << '\n';
    for(int i = 0;i <= cnt;i++) for(int j = 0;j <= 25;j++) tr[i].son[j] = 0;
    vec.clear(), tot = 0, cnt = 0;
}
signed main() {
//  ios::sync_with_stdio(0);
//  cin.tie(0), cout.tie(0);
    cin >> TT;
    while(TT --) solve();
}
