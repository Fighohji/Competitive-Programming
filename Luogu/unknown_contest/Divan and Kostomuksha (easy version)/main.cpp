#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100100, A = 5001000;
int a[N], num[A];
long long f[A];
int n;
int main() {
    scanf("%d", &n);
    int m = 0; // m是值域
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), num[a[i]]++, f[a[i]] += a[i], m = max(m, a[i]);
    for (int i = 1; i <= m; i++) {
        for (int j = i * 2; j <= m; j += i)
            num[i] += num[j];
    }
    for (int i = m; i >= 1; i--) {
        for (int j = i * 2; j <= m; j += i) {
            f[i] = max(f[i], f[j] + 1ll * (num[i] - num[j]) * i);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
        ans = max(ans, f[i]); // 不知道gcd(a[1],a[2]...a[n])是多少，所以要枚举
    printf("%lld", ans);
}
