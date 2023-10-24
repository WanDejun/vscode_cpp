#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n, m, t, ans = 0;
    scanf("%lld%lld", &n, &m); getchar();
	a[0] = 1;
	for (i64 i = 1; i < n; i++) {
		scanf("%lld", a + i);
	}
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", b + i);
	}
	sort(a, a + n);
	sort(b, b + n);
	for (i64 i = 0; i < n; i++) {
		ans = max(ans, (upper_bound(b, b + n, a[i]) - b) - i);
		ans = max(ans, i + 1 - (lower_bound(a, a + n, b[i]) - a));
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
