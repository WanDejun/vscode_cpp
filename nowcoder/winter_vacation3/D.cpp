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
i64 a[N], b[N], c[N];

void solve() {
    i64 n = 0, m = 0, k = 0, ans = LLONG_MIN, t = 0;
    scanf("%lld%lld", &n, &k); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}

	for (i64 i = 0; i < n; i++) b[i] = c[i] = 0;
	ans = b[0] = c[0] = a[0];
	for (i64 i = 1; i < n; i++) {
		if (k) { 
			b[i] = max(a[i], a[i] + b[i - 1]);
			if (i > 1) c[i] = max(a[i], a[i] + b[i - 2]);
			else c[i] = b[i];
			ans = max(ans, max(c[i], b[i]));
		}
		else {
			b[i] = max(a[i], a[i] + b[i - 1]);
			ans = max(ans, b[i]);
		}
	}

	for (i64 i = 0; i < n; i++) b[i] = c[i] = 0;
	b[n - 1] = c[n - 1] = a[n - 1];
	for (i64 i = n - 2; i >= 0; i--) {
		if (k) { 
			b[i] = max(a[i], a[i] + b[i + 1]);
			if (i < n - 2) c[i] = max(a[i], a[i] + b[i + 2]);
			else c[i] = b[i];
			ans = max(ans, max(c[i], b[i]));
		}
		else {
			b[i] = max(a[i], a[i] + b[i + 1]);
			ans = max(ans, b[i]);
		}
	}

	printf("%lld\n", ans);
}

int main() {
	i64 _ = 1;
	//scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
