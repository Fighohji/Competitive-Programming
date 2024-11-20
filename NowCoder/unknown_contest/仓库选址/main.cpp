#include <iostream>
#define ll long long
#define int long long
#define ft first
#define sd second
#define P pair<int, int>
#define Ios ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
void solve() {
    int n, m, all = 0;
    cin >> m >> n;
    vector<int> cntx(n + 1), cnty(m + 1), disx(n + 1), disy(m + 1);
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> x;
            cntx[i] += x, cnty[j] += x;
            disx[0] += i * x, disy[0] += j * x;
            all += x;
        }
    }
    int sumx = cntx[0], sumy = cnty[0];
    int xmin = disx[0], ymin = disy[0];
    for (int i = 1; i <= n; i++) {
        disx[i] = disx[i - 1] + 2 * sumx - all;
        xmin = min(xmin, disx[i]);
        sumx += cntx[i];
    }
    for (int i = 1; i <= m; i++) {
        disy[i] = disy[i - 1] + 2 * sumy - all;
        ymin = min(ymin, disy[i]);
        sumy += cnty[i];
    }
    cout << xmin + ymin << "\n";
}
signed main() {
    Ios;
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
