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

bool is_prime(i64 n) {
	for (i64 i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, num = 0;
    scanf("%lld", &n); getchar();

	if (n & 1) { 
		num = n + 2;
		if (!is_prime(num)) {
			printf("-1\n");
		}
		else {
			printf("1 ");
			for (i64 i = 1; i < n; i++) {
				printf("%lld ", n - i + 1);
			}
		}
	}
	else {
		num = n + 1;
		if (!is_prime(num)) {
			printf("-1\n");
		}
		for (i64 i = 0; i < n; i++) {
			printf("%lld ", n - i);
		}
	}
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
