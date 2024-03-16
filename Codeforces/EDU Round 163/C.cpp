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
i64 a[2][N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();

	for (i64 i = 0; i < 2; i++) {
		for (i64 j = 0; j < n; j++) {
			a[i][j] = getchar();
		}
		getchar();
	}
	
	if (a[1][n - 2] == '<') {
		printf("NO\n");
		return;
	}

	for (i64 i = 1; i < n - 1; i += 2) {
		if (a[0][i] == '<' && (a[1][i - 1] == '<' || a[1][i + 1] == '<')) {
			printf("NO\n");
			return;
		}
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
