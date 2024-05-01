#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e6 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

i64 qpow(i64 a, i64 b) {
  i64 ans = 1;
  a = (a % MOD + MOD) % MOD;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % MOD;
    a = (a * a) % MOD;
  }
  return ans % MOD;
}

void solve() {
    i64 n = 0, k, m = 0, t = 0, ans = 0, cnt = 0, sum = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld",a + i);
        (sum += a[i]) %= MOD;
	}
	
    printf("%lld", (sum * qpow(n, MOD - 2)) % MOD);
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

