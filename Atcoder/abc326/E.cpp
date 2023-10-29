#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 3e5 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

i64 qpow(i64 x, i64 n) {
	i64 res = 1;
	while (n) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res;
}

void solve() {
    i64 n, m, t, ans = 0, sum = 0;
    scanf("%lld", &n); getchar();
	i64 one_n = qpow(n, MOD - 2);
	for (i64 i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	i64 pre = 0;
	for (i64 i = n; i > 0; i--) {
		t = (i * one_n % n) * a[i];
		(pre = one_n * ((a[i] + sum) % MOD)) %= MOD;
		(sum += pre) %= MOD;
	}
	
	printf("%lld\n", sum);
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
