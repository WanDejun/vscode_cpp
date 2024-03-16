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
    i64 n = 0, m = 0, t = 0, ans = 0, maxi = 0, x1, x2, x3, x4;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	sort(a, a + n);
	x1 = a[0];
	x2 = a[n - 1];
	x3 = a[1];
	x4 = a[n - 2];
	
	printf("%lld\n", abs(x1 - x2) + abs(x2 - x3) + abs(x3 - x4) + abs(x4 - x1));
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
