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
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
	bool flag = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
		a[i] %= 2;
	}
	if (n == 1) {printf("zn\n"); return;}

	for (i64 i = 1; i < n; i++) {
		if (a[i] != a[i - 1]) cnt++;
	} 
	if (a[n - 1] != a[0]) cnt++;
	printf("%s\n", n % 2 ? "qcjj" : "zn");
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
