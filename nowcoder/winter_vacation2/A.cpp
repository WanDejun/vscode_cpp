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

set<i64> S1({29,30,31,32}), S2({34,36,38,40});

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c); getchar();
	ans += (a - 100) / 50;
	if (S1.find(b) != S1.end()) ans += 0;
	else if (S2.find(b) != S2.end()) ans += 1;
	else ans += 2;

	
	if (S1.find(c) != S1.end()) ans += 0;
	else if (S2.find(c) != S2.end()) ans += 1;
	else ans += 2;

	printf("%lld\n", ans);
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
