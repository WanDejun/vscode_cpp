#include <bits/stdc++.h>

#define PII pair<int, int>
#define MII multimap<int, int>
#define MSI multimap<string, int>
#define SI multiset<int>
#define VI vector<int>
#define i64 long long
#define i32 long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 a[N], dp[N];

void solve() {
    i64 n, m, t, ans;
    scanf("%lld", &n); getchar();
	ans = n;
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	dp[n] = 0;
	for (i64 i = n - 1; i > -1; i--) {
		if (i + a[i] + 1 > n) dp[i] = min(dp[i + 1] + 1, n - i);
		else dp[i] = min(dp[i + 1] + 1, dp[i + a[i] + 1]);
	}
	for (i64 i = 0; i < n; i++) {
		ans = min(ans, dp[i] + i);
	}
	printf("%lld\n", ans);
}

int main() {
	i64 _;
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
