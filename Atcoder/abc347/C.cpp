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
    i64 n, m, t, ans = 0, A, B, maxi = 0, mini = LLONG_MAX, maxi_2 = 0, mini_2 = LLONG_MAX;
    scanf("%lld%lld%lld", &n, &A, &B); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
		a[i] %= (A + B);
		maxi = max(maxi, a[i]);
		mini = min(mini, a[i]);
		if (a[i] <= A) {
			a[i] += (A + B);
		}
		maxi_2 = max(maxi_2, a[i]);
		mini_2 = min(mini_2, a[i]);
	}

	if (maxi - mini < A || maxi_2 - mini_2 < A) 
		printf("Yes");	
	else 
		printf("No");
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
