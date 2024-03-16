#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();

	scanf("%lld", a + 1);
	for (i64 i = 2; i <= n; i++) {
		scanf("%lld", a + i);
	}

	if (!(n & 1)) cnt = LLONG_MAX;

	for (i64 i = n; i > 1; i--) {
		if (a[i - 1] - a[i] > cnt) {
			printf("NO\n");
			return;
		}
		if (a[i] + cnt > a[i - 1] && (i & 1)) if (cnt < LLONG_MAX) cnt += (a[i] - a[i - 1] + cnt) / (i - 1);
	}
	printf("YES\n");
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
