#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII multimap<i64, i64>
#define MSI multimap<string, i64>
#define SI multiset<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e5 + 5;
const i64 MOD = 998244353;
i64 a[N];

i64 cal(i64 n, i64 d) { //最大身高差为d时所产生的最少组数
	i64 ans = 0;
	for (i64 i = 0, j = 0; j < n; j++) {
		if (a[j] - a[i] > d) {i = j;ans++;}
	}
	return ans + 1;
}
i64 bisearch(i64 k, i64 n) { //二分答案，即每组的最大身高差
	i64 l = 0, r = 1e9, mid, t;
	while (l < r) {
		mid = (l + r) >> 1;
		t = cal(n, mid);
		if (t <= k) r = mid;
		else l = mid + 1;
	}
	return r;
}
void solve() {
    i64 n, k, q, ans = 1;
	scanf("%lld%lld", &n, &k);
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	sort(a, a + n);
	ans = bisearch(k, n);
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
