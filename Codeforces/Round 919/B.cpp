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

void solve() {
    i64 n = 0, m = 0, t = 0, ans = LLONG_MIN, cnt = 0, k, x;
    scanf("%lld%lld%lld", &n, &k, &x); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
    sort(a, a + n);
	b[0] = 0;
	for (i64 i = 0; i <= n; i++) {
		b[i] = b[i - 1] + a[i - 1];
	}

	for (i64 i = n; i >= max(0ll, n - k); i--) {
		ans = max(ans, 2 * b[max(0ll, i - x)] - b[i]);
	}

	if (k >= n) ans = max(ans, 0ll);
	else if (x + k >= n) ans = max (ans, -b[n - k]);

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
