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
    i64 n = 0, m = 0, ans = 0, cnt = 0, t, a, k;
    scanf("%lld%lld%lld", &t, &a, &k); getchar();
	
	if ((a >= -k && a <= k) ||
		(t >= 0 && a >= 0 && a <= t + k) ||
		(t <= 0 && a <= 0 && a >= t - k) ) {
		printf("%lld\n", abs(a) + abs(t - a));
	}
	else printf("%lld\n", abs(t) + 2 * abs(t - a));
}

int main() {
	i64 _ = 1;
	// scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
