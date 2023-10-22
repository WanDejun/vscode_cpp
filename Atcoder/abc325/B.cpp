#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e3 + 5;
const i64 MOD = 998244353;
i64 a[24], b[24];

void solve() {
    i64 n, m, t, ans = 0, maxi = -1;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld%lld", &m, &t);
		a[(24 - t) % 24] += m;
	}
	for (i64 i = 0; i < 24; i++) {
		for (i64 j = 9; j < 18; j++) {
			b[(i + j) % 24] += a[i]; 
		}
	}
	for (i64 i = 0 ; i < 24; i++) {
		if (b[i] > maxi) {
			ans = i;
			maxi = b[i];
		}
	}
	printf("%lld\n", maxi);
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
