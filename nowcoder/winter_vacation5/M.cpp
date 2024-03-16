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
i64 H[N], a[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", &t);
		H[t] = i;
	}
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}
	
	if (n == 1) { printf("-1\n"); }
	else if (n == 2) {
		if (H[a[0]] == 0) printf("-1\n");
		else printf("1\n");
	}
	else {
		for (i64 i = 0; i < n; i++) {
			if ((H[a[i]] == i && i != 0 && i != n - 1) || H[a[i]] == i + 1 || H[a[i]] == i - 1) {printf("1\n"); return;}
		}
		printf("2\n");
	}
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
