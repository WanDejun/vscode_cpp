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
const i64 inf = 1e15;
i64 dp[2][2][N], c[N];
char str[N];

void solve() {
    i64 n, m, t, ans = LLONG_MAX;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		str[i] = getchar();
	}
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", c + i);
	}
	dp[0][0][0] = 0;
	dp[0][1][0] = inf;
	dp[1][0][0] = c[0];
	dp[1][1][0] = inf;


	for (i64 i = 1; i < n; i++) {
		if (str[i] != str[i - 1]) {
			dp[0][0][i] = min(inf, dp[0][0][i - 1]);
			dp[1][0][i] = min(inf, dp[1][0][i - 1] + c[i]);
			dp[0][1][i] = min(inf, min(dp[0][1][i - 1], dp[1][0][i - 1]));
			dp[1][1][i] = min(inf, min(dp[1][1][i - 1] + c[i], dp[0][0][i - 1] + c[i]));
		}
		else {
			dp[0][0][i] = min(inf, dp[1][0][i - 1]);
			dp[1][0][i] = min(inf, dp[0][0][i - 1] + c[i]);
			dp[0][1][i] = min(inf, min(dp[0][0][i - 1], dp[1][1][i - 1]));
			dp[1][1][i] = min(inf, min(dp[1][0][i - 1], dp[0][1][i - 1]) + c[i]);
		}
	}
	
	ans = min(dp[0][1][n - 1], dp[1][1][n - 1]);
	
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
