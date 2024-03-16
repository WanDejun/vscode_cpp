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
i64 dp[1060];
const i64 w[5] = {1, 3, 6, 10, 15};

void pre() {
	for (i64 i = 0; i <= 1060; i++) {
		dp[i] = i;
	}

	for (i64 i = 1; i < 5; i++) {
		for (i64 j = w[i]; j <= 1060; j++) {
			dp[j] = min(dp[j], dp[j - w[i]] + 1);
		}
	}
}

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
	cnt += (n - 900 > 0 ? n - 900 : 0) / 15;
	t = n > 900 ? 900 + (n - 900) % 15 : n;
	printf("%lld\n", cnt + dp[t]);
}

int main() {
	i64 _ = 1;
	pre();
	scanf("%lld", &_); getchar();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
