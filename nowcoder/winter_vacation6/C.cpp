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
i64 arr[N], b[3], kk;

void pre_progress() {
	i64 a = 1, b = 1, c = 2;
	arr[1] = a;
	arr[2] = b;
	arr[3] = c;
	kk = 4;
	while (c < 3e9) {
		a = b; b = c; c = a + b;
		arr[kk++] = c;
	}
}

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0, pre, nxt;
    scanf("%lld", &n); getchar();

	for (i64 i = 0; i < 3; i++) {
		i64 t = static_cast<i64>(upper_bound(arr, arr + kk, n) - arr) - 1;
		n -= arr[t];
		b[i] = arr[t];
	}
	
	if (n == 0) printf("%lld %lld %lld\n", b[0], b[1], b[2]);
	else printf("-1\n");
}

int main() {
	i64 _ = 1;
	scanf("%lld", &_); getchar();
	pre_progress();
	for (i64 __ = 0; __ < _; __++) {
		solve();
	}
	system("pause");

	return 0;
}
