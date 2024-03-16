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
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, maxi = 0, n_high, n_low;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	for (i64 i = 0; i < n; i++) {
		if (a[i] > 10) {
			n_high = a[i] / 10;
			n_low = a[i] % 10;
			if (n_low >= n_high && n_high >= maxi) {
				maxi = n_low;
			}
			else if (a[i] >= maxi) {
				maxi = a[i];
			}
			else {
				printf("NO\n");
				return;
			}
		}
		else {
			if (a[i] >= maxi) {
				maxi = a[i];
			}
			else {
				printf("NO\n");
				return;
			}
		}
	}
	
	printf("YES\n", ans);
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
