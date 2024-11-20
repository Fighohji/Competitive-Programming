#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int inf = 0x3f3f3f3f;

struct Segt {
    struct T {
        ll mn, tag;
        T() : mn(0), tag(0) {}
        void add(ll val) { mn += val, tag += val; }
    };
    const int N;
    vector<T> t;
    Segt(const vector<ll>& d) : N(d.size()), t(N << 2 | 1) {
        build(d, 1, 0, N - 1);
    }
    void add(int al, int ar, ll val) { add(al, ar, val, 1, 0, N - 1); }
    int find(int fl, int fr) { return find(fl, fr, 1, 0, N - 1); }
#define mid ((l + r) >> 1)
#define ls (v << 1)
#define rs (v << 1 | 1)
    void pu(int v) { t[v].mn = min(t[ls].mn, t[rs].mn); }
    void pd(int v) {
        if (t[v].tag) {
            t[ls].add(t[v].tag);
            t[rs].add(t[v].tag);
            t[v].tag = 0;
        }
    }
    void build(const vector<ll>& val, int v, int l, int r) {
        if (l == r) {
            t[v].mn = val[l];
        } else {
            build(val, ls, l, mid);
            build(val, rs, mid + 1, r);
            pu(v);
        }
    }
    void add(int al, int ar, ll val, int v, int l, int r) {
        if (ar < l || al > r) {
            return;
        }
        if (al <= l && ar >= r) {
            t[v].add(val);
        } else {
            pd(v);
            add(al, ar, val, ls, l, mid);
            add(al, ar, val, rs, mid + 1, r);
            pu(v);
        }
    }
    int find(int fl, int fr, int v, int l, int r) {
        if (fr < l || fl > r || t[v].mn >= 0) {
            return inf;
        }
        if (l == r) {
            return l;
        }
        pd(v);
        int res = find(fl, fr, ls, l, mid);
        if (res == inf) {
            res = find(fl, fr, rs, mid + 1, r);
        }
        return res;
    }
#undef rs
#undef ls
#undef mid
};

struct Tree {
    struct Node {
        array<int, 2> s;
        int fa, sz, dep, top, len, loc;
        ll l;
        Node() : fa(0), sz(1), top(0), len(0), loc(0), l(0) { s.fill(0); }
    };
    ~Tree() {
        delete tr;
    }
    const int N;
    vector<Node> t;
    vector<int> dfn;
    vector<ll> d;
    Segt *tr;
    Tree(int n) : N(n), t(n * 2) {
        for (int i = 1; i <= n; i++) {
            cin >> t[i].l;
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            t[i + n].sz = t[u].sz + t[v].sz + 1;
            t[i + n].l = t[u].l + t[v].l;
            if (t[u].sz < t[v].sz) {
                swap(u, v);
            }
            t[u].fa = t[v].fa = i + n;
            t[i + n].s = {u, v};
        }
        auto dfs = [&](auto&& self, int v, int top) {
            t[v].loc = dfn.size();
            dfn.emplace_back(v);
            t[v].dep = t[t[v].fa].dep + 1;
            t[v].len = 1, t[v].top = top;
            if (!t[v].s[0]) {
                return;
            }
            self(self, t[v].s[0], top);
            self(self, t[v].s[1], t[v].s[1]);
            t[v].len += t[t[v].s[0]].len;
        };
        dfs(dfs, n * 2 - 1, n * 2 - 1);
        d.resize(dfn.size());
        for (int i = 0; i < (int)dfn.size(); i++) {
            auto [u, v] = t[dfn[i]].s;
            if (dfn[i] > n) {
                d[i] = t[u].l - t[v].l - (u < v ? 0 : 1);
            } else {
                d[i] = -1;
            }
        }
        tr = new Segt(d);
    }
    int query() {
        int v = N * 2 - 1;
        while (t[v].s[0]) {
            int l = t[v].loc, r = l + t[v].len - 1;
            int x = tr->find(l, r);
            v = dfn[t[v].loc + (x - l)];
            if (t[v].s[1]) {
                v = t[v].s[1];
            }
        }
        return v;
    }
    void add(int x, int val) {
        while (x) {
            int l = t[t[x].top].loc, r = t[x].loc - 1;
            tr->add(l, r, val);
            x = t[t[x].top].fa;
            if (x) {
                tr->add(t[x].loc, t[x].loc, -val);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    Tree tr(n);
    int q;
    cin >> q;
    cout << tr.query() << '\n';
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        tr.add(x, y);
        cout << tr.query() << '\n';
    }
    return 0;
}
