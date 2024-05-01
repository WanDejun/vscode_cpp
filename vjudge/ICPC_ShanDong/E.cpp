#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

inline void solve() {
    i64 n = 0, k, m = 0, a, b, t = 0, ans = LLONG_MAX, cost = 0, cnt;
    scanf("%lld%lld%lld%lld%lld", &n, &k, &m, &a, &b);
    if (n % m == 0) {
        printf("0\n"); return;
    }
    if (k == 1) {
        printf("-1\n"); return;
    }

    for (t = n, cnt = 0; t != 0; t /= k, cnt++);
    ans = cnt * b;

	for (i64 j = 0; n > 0; n /= k, j++) {
        __int128 pow_k = 1, maxi, mini;
		for (i64 i = 0; i <= (log(m) / log(k)) + 1; i++, pow_k *= k) {
            maxi = (n + 1) * pow_k - 1;
            mini = n * pow_k;

            maxi = maxi / m;
            mini = (mini + m - 1) / m;
            if (maxi >= mini) {
                ans = min(ans, i * a + j * b);
            }
        }
        
	}
	
	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
