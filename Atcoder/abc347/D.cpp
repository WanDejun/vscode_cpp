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

void solve() {
    i64 cnt_c = 0, m, t, ans = 0, a, b, c, ans_a = 0, ans_b = 0;
    scanf("%lld%lld%lld", &a, &b, &c); getchar();
	for (i64 i = 0; i < 60; i++) {
		if (c & (1ll << i)) cnt_c++;
	}
	if (((cnt_c % 2) != ((a + b) % 2))) {
		printf("-1");
		return;
	}

	for (i64 i = 0, j = 0; i < cnt_c; i++, j++) {
		while ((c & (1ll << j)) == 0) j++;

		if (max(a, b) == 0) {
			printf("-1");
			return;
		}

		if (a >= b) {
			ans_a |= (1ll << j);
			a--;
		}
		else {
			ans_b |= (1ll << j);
			b--;
		}
	}
	if (a != b) {
		printf("-1");
		return;
	}

	for (i64 i = 0; i < 60 && a; i++) {
		if ((c & (1ll << i)) == 0) {
			a--; b--;
			ans_a |= (1ll << i);
			ans_b |= (1ll << i);
		}
	}
	if (a != 0 || b != 0) {
		printf("-1");
		return;
	}
	printf("%lld %lld", ans_a, ans_b);
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
