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
i64 a[N], b[N], loc[N], ans_arr[N];

void solve() {
	map<i64, i64> M;
    i64 n, m, t, ans = 0, size = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < m; i++) {
		scanf("%lld",a + i);
	}

	for (i64 i = 0; i < m; i++)  {
		M[a[i]]++;
		if (M[a[i]] % 2 == 1) {
			size++;
			loc[a[i]] = i;
		}
		else {
			size--;
			ans_arr[a[i]] += b[i] - b[loc[a[i]]];
			loc[a[i]] = i;
		}
		b[i + 1] = b[i] + size;
	}
	

	for (i64 i = 1; i <= n; i++) {
		if (M[i] % 2 == 1) {
			ans_arr[i] += b[m] - b[loc[i]];
		}
		printf("%lld ", ans_arr[i]);
	}
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
