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
i64 a[N], c[N];
i64 b[20][37];
i64 temp[20];

void solve() {
    unsigned i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
		c[i] = a[i] % 36;
	}

	t = 1;
	for (i64 i = 0; i < 20; i++) {
		temp[i] = t;
		(t *= 10) %= 36;
	}

	for (i64 i = 0; i < 20; i++) {
		for (i64 j = 0; j < n; j++) {
			b[i][(temp[i] * c[j]) % 36]++;
		}
	}

	for (i64 i = 0; i < n; i++) {
		ans += b[(i64)(log10(a[i])) + 1][(36 - c[i]) % 36];
		if ((c[i] * temp[((i64)(log10(a[i])) + 1) % 36] % 36) == ((36 - c[i]) % 36)) ans--;
	}
	
	printf("%lld\n", ans);
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
