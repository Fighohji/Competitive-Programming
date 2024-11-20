#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>

using namespace std;
struct node {
    int id;
    int c, m;
    double p;
};
struct availble{
    int id, c, m;
};
vector<availble> ava;
struct thread {
    int id, c, m;
} T[2000010];
void solve() {
    srand(time(nullptr));
    int F; cin >> F;
    vector<node> a(F + 1);
    for (int i = 1; i <= F; ++i) {
        cin >> a[i].c >> a[i].m >> a[i].p;
        a[i].id = i;
    }
    while (1) {
        int id; cin >> id;
        string op; cin >> op;
        int S; cin >> S;
        if (op == "END") break;
        if (op == "CREATE") {
            vector<int> cre, Ans(S + 1);
            for (int i = 1; i <= S; ++i) {
                int x; cin >> x;
                cin >> T[x].c >> T[x].m;
                bool flag = 0;
                for (int j = 0; j < ava.size(); ++j) {
                    auto it = ava[j];
                    if (it.c >= T[x].c && it.m >= T[x].m) {
                        Ans[i] = it.id;
                        T[x].id = j;
                        it.c -= T[x].c;
                        it.m -= T[x].m;
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    random_shuffle(a.begin() + 1, a.end());
                    for (int j = 1; j <= F; ++j) {
                        if (a[j].c >= T[x].c && a[j].m >= T[x].m) {
                            T[x].id = ava.size();
                            ava.push_back({a[j].id, a[j].c - T[x].c, a[j].m -= T[x].m});
                            cre.push_back(a[j].id);
                            Ans[i] = a[j].id;
                        }
                    }
                }
            }
            cout << cre.size() << " ";
            for (int i : cre) cout << i << " ";
            cout.flush();
            for (int i = 1; i <= S; ++i) {
                cout << Ans[i] << " ";
            }
            cout.flush();
        }
        if (op == "DELETE") {
            for (int i = 1; i <= S; ++i) {
                int x; cin >> x;
                ava[T[x].id].c -= T[x].c;
                ava[T[x].id].m -= T[x].m;

            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    solve();
    return 0;
}
