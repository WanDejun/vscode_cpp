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
i64 a[N], b[N];
i64 val(i64 n) {
    i64 ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
void solve() {
    i64 n, m, t, ans = 0, x, k;
    scanf("%lld%lld", &x, &k); getchar();
	for (i64 i = x; 1; i++) {
        ans = val(i);
        if (ans % k == 0) {printf("%lld\n", i); break;}
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
