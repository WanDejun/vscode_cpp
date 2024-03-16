#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 1e9 + 7;

i64 qpow(i64 a, i64 b) {
    if (b == 0) return 1;
    else if (b == 1) return a;
    i64 t = qpow(a, b >> 1);
    if (b % 2) 
        return (a * (t * t % MOD)) % MOD;
    else 
        return (t * t) % MOD;
}


void solve() {
    i64 n = 0, k = 0, t = 0, sum = 0, jc = 1;
    scanf("%lld%lld", &n, &k); getchar();
    i64 a = 1, b = 1, c;
    for (i64 i = 0; i <= k; i++) {
        c = qpow(k - i, n);
        (sum += a * (b * c % MOD)) %= MOD;
        a *= -1;
        b = (b * (k - i) % MOD) * ((qpow(i + 1, MOD - 2) + MOD) % MOD) % MOD;
    }
    for (i64 i = 2; i <= k; i++) {
        jc = (jc * i) % MOD;
    }

	printf("%lld\n", (MOD + (sum * (qpow(jc, MOD - 2) + MOD) % MOD)) % MOD);
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
