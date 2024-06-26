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
    i64 n = 0, k, m = 0, t = 0, ans = 0, cnt = 0;
    scanf("%lld", &n); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
	}	
    for (i64 i = 0; i < n; i++) {
		scanf("%lld", b + i);
	}
    sort(a, a + n);
    sort(b, b + n);

    i64 i, j;
    for (i = n - 1, j = n - 1; i >= 0; i--, j--) {
        while (i >= 0 && a[i] > b[j]) i--;
        if (i != -1) cnt++;
    }
	
	printf("%lld\n", n - cnt);
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
