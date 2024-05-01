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

i64 sum(i64 a, i64 b) {
	if (a > b) return 0;
	return (a + b) * (b - a + 1) / 2;
}

void solve() {
    i64 n, m, t, ans = 0, k;
    scanf("%lld%lld", &n, &k); getchar();

	a[0] = 0;
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}

	sort(a + 1, a + n + 1);

	if (a[n] < k) {
		for (i64 i = 1; i <= n; i++) {
			ans += sum(a[i - 1] + 1, a[i] - 1);
		}
		ans += sum(a[n] + 1, k);
	}
	else {
		for (i64 i = 1; i <= n; i++) {
			ans += sum(a[i - 1] + 1, min(k, a[i] - 1));
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
