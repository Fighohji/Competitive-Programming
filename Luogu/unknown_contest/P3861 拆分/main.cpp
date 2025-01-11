#include <iostream>
#include <cmath>
#include <algorithm>
#define int long long
using namespace std;
const int MOD = 998244353;
const int N = 1000005;
int T, n, sqrtn, tot, pos, x[N], pos1[N], pos2[N], f[6721][6721];
signed main() {
	for (cin >> T; T--;) {
		cin >> n;
		tot = 0, sqrtn = (int)sqrt(n);
		for (int i = 1; i <= n / i; i++) {
			if (n % i == 0) {
				x[++tot] = i;
				if (i * i != n) x[++tot] = n / i;
			}
		}
		sort(x + 1, x + tot + 1);
		for (int i = 1; 2 * i <= tot + 1; i++) {
			pos1[x[i]] = i;
			pos2[x[i]] = tot - i + 1;
		}
		for (int i = 1; i <= tot; i++) {
			if (i == 1) f[i][1] = 1;
			else f[i][1] = 0;
			for (int j = 2; j <= tot; j++) {
				f[i][j] = f[i][j - 1];
				if (j > i) continue;
				if (x[i] % x[j] == 0) {
					int tmp = x[i] / x[j];
					pos = (tmp <= sqrtn ? pos1[tmp] : pos2[n / tmp]);
					f[i][j] = (f[i][j] + f[pos][j - 1]) % MOD;
				}
			}
		}
		cout << f[tot][tot] - 1 << "\n";
	}
	return 0;
}
