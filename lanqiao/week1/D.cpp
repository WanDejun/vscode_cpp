#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 2e5 + 5;
const i64 MOD = 998244353;
i64 s[25], day[N];

i64 cal(i64 day) {
	i64 ans = 0;
	for (i64 i = 0; day; i++, day >>= 1) {
		if (day & 1) ans += s[i];
	}
	return ans;
}

void solve() {
    i64 n, m, q, ans = 0, t, k;
	scanf("%lld%lld%lld", &n, &m, &q);
	i64 st = 0;
	for (i64 i = 0; i < q; i++) {
		scanf("%lld", &t);
		day[i] = t - st - 1;
		st = t;
		//cout << day[i] << " ";
	}
	day[q] = n - st;
	for (i64 i = 0; i < m; i++) {
		scanf("%lld%lld", &k, &t);
		s[k] = max(s[k], t);
	}
	for (i64 i = 1; i < 21; i++) {
		s[i] = max(s[i], s[i - 1] << 1);
	}
	for (i64 i = 0; i <= q; i++) {
		ans += cal(day[i]);
	}
	printf("%lld\n", ans);
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
