#include <bits/stdc++.h>

#define PII array<i64, 2>
#define MII map<i64, i64>
#define MSI map<string, i64>
#define SI set<i64>
#define VI vector<i64>
#define i64 long long

using namespace std;

const i64 N = 1e6 + 5;
const i64 MOD = 998244353;
i64 a[N], b[N];

void solve() {
    i64 n = 0, m = 0, t = 0, ans = 0, sum = 0;
    scanf("%lld%lld", &n, &m); getchar();
	for (i64 i = 0; i < n; i++) {
		scanf("%lld", a + i);
        sum += a[i];
	}

    sort(a, a + n);	

    for (i64 i = 0; i < n; i++) {
        if (sum - a[i] * (n - i) > m) {
            sum -= a[i];
        }
        else {
            printf("%lld\n", (sum - m) / (n - i));
            return;
        }
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
